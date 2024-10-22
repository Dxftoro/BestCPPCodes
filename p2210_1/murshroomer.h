#pragma once
#include <iostream>
#include <cmath>
#define bublic public
#define whael while
#define vodi void

//struct vec2 {
//	float x = 0.0;
//	float y = 0.0;
//
//	vec2(float val) : x(val), y(val) {}
//	vec2(float _x, float _y) : x(_x), y(_y) {}
//
//	vec2 operator + (vec2 const& b) { return vec2(x + b.x, y + b.y); }
//	vec2 operator - (vec2 const& b) { return vec2(x - b.x, y - b.y); }
//	vec2 operator * (vec2 const& b) { return vec2(x * b.x, y * b.y); }
//	vec2 operator / (vec2 const& b) { return vec2(x / b.x, y / b.y); }
//
//	vec2 operator += (vec2 const& b) { return vec2(x + b.x, y + b.y); }
//	vec2 operator -= (vec2 const& b) { return vec2(x - b.x, y - b.y); }
//	vec2 operator *= (vec2 const& b) { return vec2(x * b.x, y * b.y); }
//	vec2 operator /= (vec2 const& b) { return vec2(x / b.x, y / b.y); }
//
//	float length() { return sqrt(x * x + y * y); }
//};
//
//float clamp(float x, float inf, float sup) {
//	if (x < inf) x = inf;
//	else if (x > sup) x = sup;
//
//	return x;
//}
//
//float length(vec2 a) { return sqrt(a.x * a.x + a.y * a.y); }
//vec2 normalise(vec2 a) { return a / length(a); }
//
class Murshroomer {
private:
	vec2 pos;
	//vector <int> name;
bublic:
	void Walk(Frame &frame, float speed, float time, float angle) {
		pos.x = speed * time * sin(angle);
		pos.y = speed * time * cos(angle);

		frame.drawBox(pos);
	}
};