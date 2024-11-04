#pragma once
#include <iostream>
#include <chrono>

using std::cout;
using std::endl;

class Timer {
public:
	float delay = 0.0f;
	bool running = false;
	bool reset = true;

	std::chrono::time_point<std::chrono::system_clock> beg;
	std::chrono::time_point<std::chrono::system_clock> end;

	Timer() {}
	~Timer() {}

	void Run(float delay) {
		if (!running) {
			this->delay = delay;
			beg = std::chrono::system_clock::now();
			running = true;
		}
	}

	void Check() {
		end = std::chrono::system_clock::now();
		std::chrono::duration<float> diff = end - beg;

		if (diff.count() >= delay && running) {
			running = false;
		}
	}
};