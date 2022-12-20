#pragma once
#include <SFML/Graphics.hpp>

enum Direction {
	left,
	right
};

class Person
{
public:
	float dx, dy, currentFrame;
	Direction moveDirection;
	int speed, animationSpeed;

	Person(int, int);
};

