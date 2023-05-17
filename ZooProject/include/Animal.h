#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Location.h"
using namespace std;

class Animal
{
protected:
	string name;
	Location loc;
	bool movePossibility;
	char horizontDirection;
	char verticalDirection;

public:
	Animal(string name, int row, int column, char horizontDirection, char verticalDirection);
	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual void step() = 0;
	void stop();
	virtual void move();
	virtual void turnVertically();
	void turnHorizontally();

private:

};



