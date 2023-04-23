#include "Animal.h"

Animal::Animal(string name,int row, int column, char horizontDirection, char verticalDirection)
{
	this->name = name;
	loc.row = row;
	loc.column = column;
	this->horizontDirection = horizontDirection;
	this->verticalDirection = verticalDirection;
	movePossibility = true;
}

void Animal::stop()
{
	movePossibility = false;
}

void Animal::move()
{
	int hor = rand() % 2;
	int ver = rand() % 2;
	if (hor)
	{
		horizontDirection = 'r';
	}
	else
	{
		horizontDirection = 'l';
	}
	if (ver)
	{
		verticalDirection = 'u';
	}
	else
	{
		verticalDirection = 'd';
	}
	movePossibility = true;
}

void Animal::turnHorizontally()
{
	if (horizontDirection == 'r')
	{
		horizontDirection = 'l';
	}
	else
	{
		horizontDirection = 'r';
	}
}

void Animal::turnVertically()
{
	if (verticalDirection == 'u')
	{
		verticalDirection = 'd';
	}
	else
	{
		verticalDirection = 'u';
	}
}


Location Animal::getLocation() const
{
	return loc;
}