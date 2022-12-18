#pragma once
#include <SFML/Graphics.hpp>

enum direction {
	left,
	right
};

class Person
{
public:
	float dx, dy, currentFrame;
	direction moveDirection;
	int speed, animationSpeed;

	Person(int, int);
};

