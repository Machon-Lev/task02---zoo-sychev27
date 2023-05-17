#include "Lion.h"

Lion::Lion(string name, int row, int column, char horizontDirection, char verticalDirection) :
	Animal(name, row, column, horizontDirection, verticalDirection)
{
}


void Lion::move()
{
	int hor = rand() % 2;
	if (hor)
	{
		horizontDirection = 'r';
	}
	else
	{
		horizontDirection = 'l';
	}
	movePossibility = true;
}

void Lion::step()
{
	if (movePossibility)
	{
		if (horizontDirection == 'r')
		{
			if (loc.column + 2 <= 19)
			{
				loc.column += 2;
			}
			else
			{
				if (loc.column + 2 == 20)
				{
					turnHorizontally();
				}
				else
				{
					if (loc.column + 2 == 21)
					{
						turnHorizontally();
						loc.column -= 2;
					}
				}
			}
		}
		else
		{
			if (loc.column - 2 >= -20)
			{
				loc.column -= 2;
			}
			else
			{
				if (loc.column - 2 == -21)
				{
					turnHorizontally();
				}
				else
				{
					if (loc.column - 2 == -22)
					{
						turnHorizontally();
						loc.column += 2;
					}
				}
			}
		}
	}
}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::printDetails() const
{
	cout << name + "- Lion" + " " << loc;
}