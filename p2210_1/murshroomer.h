#pragma once
#include <iostream>
#include <string>
#include <future>
#include <cmath>
#define bublic	public

//класс "Грибник" для упрощения визуализации грибников в задаче
class Murshroomer {
private:
	int stepCount = 0;

	int allMushrooms = 0;
	int mushroomsFound = 0;
	int allFriendsMushr = 0;

	float selfPathLen = 0.0f;
	float friendsPathLen = 0.0f;
	float dist = 0.0f;
	float distToFriend = 0.0f;

	std::string name;
bublic:
	vec2 pos;
	vec2 friendsPos;
	vec3 walkInfo;

	Murshroomer(std::string name) {
		this->name = name;
	}
	~Murshroomer() {}

	//грибник идёт с заданной скоростью, временем и направлением и находит грибы, количество которых случайно
	void Walk(float speed, float time, float angle) {
		vec2 newPos;
		newPos.x = speed * time * sin(angle);
		newPos.y = speed * time * cos(angle);

		selfPathLen += distance(pos, newPos);
		dist += distance(vec2(0), newPos);
		pos = newPos;

		mushroomsFound = rand() % 15;
		allMushrooms += mushroomsFound;
		stepCount++;

		walkInfo.x = speed;
		walkInfo.y = time;
		walkInfo.z = angle;
	}
	//отображает грибника в консоли в виде прямоугольника
	void Draw(Frame &frame) {
		frame.drawBox(
			vec2(
				clamp(pos.x, -1.0f, 1.0f),
				clamp(pos.y, -1.0f, 1.0f)
			),
			vec2(0.05f, 0.066f));
	}

	int GetMushroomsFound() { return mushroomsFound; }
	int GetAllMushrooms() { return allMushrooms; }
	int GetStepCount() { return stepCount; }

	float GetDist() { return dist; }
	float GetDistToFriend() { return distToFriend; }

	std::string GetName() { return name; }

	void AddFriendsPathLen(float pathPart) { this->friendsPathLen += pathPart; }
	void AddDistToFriend(float distToFriend) { this->distToFriend += distToFriend; }
	void AddFoundByFriend(int foundByFriend) { this->allFriendsMushr += foundByFriend; }
};