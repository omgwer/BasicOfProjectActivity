#include "Person.h"

Person::Person(int speed, int animationSpeed)
{
	dx = dy = 0;
	this->currentFrame = 0;
	this->moveDirection = right;
	this->speed = speed;
	this->animationSpeed = animationSpeed;
}
