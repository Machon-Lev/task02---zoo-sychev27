#include "Dog.h"

Dog::Dog(string name, int row, int column, char horizontDirection, char verticalDirection) :
	Animal(name, row, column, horizontDirection, verticalDirection)
{
	bigStep = true;
}

void Dog::move()
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

void Dog::step()
{
	if (movePossibility)
	{
		if (bigStep)
		{
			if (horizontDirection == 'r')
			{
				if (loc.column + 3 <= 19)
				{
					loc.column += 3;
					turnHorizontally();
					bigStep = false;
				}
				else
				{
					if (loc.column + 3 == 20)
					{
						turnHorizontally();
					}
					else
					{
						if (loc.column + 3 == 21)
						{
							loc.column -= 1;
						}
						else
						{
							if (loc.column + 3 == 22)
							{
								turnHorizontally();
							}
						}
					}
				}
			}
			else
			{
				if (loc.column - 3 >= -20)
				{
					loc.column -= 3;
					turnHorizontally();
					bigStep = false;
				}
				else
				{
					if (loc.column - 3 == -21)
					{
						turnHorizontally();
					}
					else
					{
						if (loc.column - 3 == -22)
						{
							turnHorizontally();
						}
						else
						{
							if (loc.column - 3 == -23)
							{
								turnHorizontally();
							}
						}
					}
				}
			}
		}
		else
		{
			if (horizontDirection == 'r')
			{
				if (loc.column + 1 <= 19)
				{
					loc.column += 1;
					turnHorizontally();
					bigStep = true;
				}
				else
				{
					if (loc.column + 1 == 20)
					{
						turnHorizontally();
					}
				}

			}
			else
			{
				if (loc.column - 1 >= -20)
				{
					loc.column -= 1;
					turnHorizontally();
					bigStep = true;
				}
				else
				{
					if (loc.column - 1 == -21)
					{
						turnHorizontally();
					}
				}
			}
		}
	}
}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::printDetails() const
{
	cout << name + "- Dog" + " " << loc;
}