#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <mutex>

#include "visualray.h"
#include "murshroomer.h"

using namespace std;

Frame frame;

int main() {
	Murshroomer fr1;
	Murshroomer fr2;
	float mul = 0.0f;

	while (true) {
		frame.clearBuff();
		fr1.Walk(frame, 1.0f, 1.0f, mul);
		fr2.Walk(frame, 0.6f, 0.7f, -1.0f * mul);
		mul += 0.01;
		frame.drawBuff();
	}

	return 0;
}