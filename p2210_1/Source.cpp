#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <future>
#include <chrono>
#include <mutex>
#include <fstream>

#include "timer.h"
#include "visualray.h"
#include "murshroomer.h"

using namespace std;

Frame frame;
ConsoleBuffer console;
Timer timer;

void DrawChars(Frame& frame, string& text, int x, int y) {
	int new_x = x;

	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '\n') {
			y++;
			new_x = x;
		}
		else if (text[i] == '\t') {
			for (int k = 0; k < 4; k++) {
				frame.setPixel(' ', new_x, y);
				new_x++;
			}
		}
		else {
			frame.setPixel(text[i], new_x, y);
			new_x++;
		}
	}
}

float Frand(const float a, const float b) {
	return a + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (b - a));
}

void MushroomerWork(Murshroomer* self, Murshroomer* another,
					promise <float> distPromise, promise <float> diffPromise,
					float maxSpeed, float maxTime, time_t seedOffset) {

	srand(time(0) - seedOffset);
	string debug = "";

	while (timer.running) {
		float speed = Frand(0.05f, maxSpeed);
		float time = Frand(0.05f, maxTime);
		float angle = Frand(0.05f, 360.0f);

		this_thread::sleep_for(chrono::milliseconds(static_cast<int>(time * 1000)));
		self->Walk(speed, time, angle);

		self->AddFriendsPathLen(distance(self->friendsPos, another->pos));
		self->AddDistToFriend(distance(self->pos, another->pos));
		self->AddFoundByFriend(another->GetMushroomsFound());
	}

	distPromise.set_value(self->GetDist());
	diffPromise.set_value(self->GetDistToFriend());
}

string MsInfo(Murshroomer& fr) {
	return fr.GetName() +
		+ ":\n\tSpeed: " + to_string(fr.walkInfo.x)
		+ "\n\tTime: " + to_string(fr.walkInfo.y)
		+ "\n\tAngle: " + to_string(fr.walkInfo.z)
		+ "\n\tMushrooms: " + to_string(fr.GetMushroomsFound());
}

int main() {
	float maxSpeed, maxTime;
	cout << "Input U and T parameters (max. speed and time allowed): ";
	cin >> maxSpeed >> maxTime;

	Murshroomer fr1("Vasya");
	Murshroomer fr2("Petya");

	promise <float> distPromise1, distPromise2;
	promise <float> diffPromise1, diffPromise2;

	future <float> distFuture1 = distPromise1.get_future();
	future <float> diffFuture1 = diffPromise1.get_future();

	future <float> distFuture2 = distPromise2.get_future();
	future <float> diffFuture2 = diffPromise2.get_future();

	string debug = "";
	console.Handle();
	timer.Run(10);

	thread MsThread1(MushroomerWork, &fr1, &fr2,
		move(distPromise1), move(diffPromise1),
		maxSpeed, maxTime, 0);

	thread MsThread2(MushroomerWork, &fr2, &fr1,
		move(distPromise2), move(diffPromise2),
		maxSpeed, maxTime, 1);

	std::chrono::duration<float> diff;

	while (timer.running) {
		timer.Check();
		frame.clearBuff();

		fr1.Draw(frame);
		fr2.Draw(frame);

		diff = timer.end - timer.beg;
		debug += "Time elapsed: " + to_string(diff.count()) + "\n\n";
		debug += MsInfo(fr1) + "\n\n";
		debug += MsInfo(fr2);
		DrawChars(frame, debug, 0, 0);
		debug = "";

		frame.drawBuffA(console, false);
	}
	MsThread1.join();
	MsThread2.join();

	frame.clearBuff();

	float dist1 = distFuture1.get() / fr1.GetStepCount();
	float diff1 = diffFuture1.get() / fr1.GetStepCount();
	float dist2 = distFuture2.get() / fr2.GetStepCount();
	float diff2 = diffFuture2.get() / fr2.GetStepCount();

	cout << "U = " << maxSpeed << endl;
	cout << "T = " << maxTime << endl << endl;
	cout << fr1.GetName()
		<< ":\n\tAverage distance to starter point: " << dist1
		<< "\n\tThinks his average distance to friend is: " << diff1 << endl << endl;

	cout << fr2.GetName()
		<< ":\n\tAverage distance to starter point: " << dist2
		<< "\n\tThinks his average distance to friend is: " << diff2 << endl;

	return 0;
}