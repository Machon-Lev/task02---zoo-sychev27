#include "Owl.h"

Owl::Owl(string name, int row, int column, char horizontDirection, char verticalDirection) :
	Animal(name, row, column, horizontDirection, verticalDirection)
{
}


void Owl::step()
{
	if (movePossibility)
	{
		if (horizontDirection == 'r' && verticalDirection == 'd')
		{
			if (loc.column + 3 <= 19 && loc.row + 3 <= 9)
			{
				loc.column += 3;
				loc.row += 3;
			}
			else
			{
				if ((loc.column + 3 == 20 && loc.row + 3 <= 10) || (loc.row + 3 == 10 && loc.column + 3 <= 20))
				{
					turnHorizontally();
					turnVertically();
					loc.column += 1;
					loc.row += 1;
				}
				else
				{
					if ((loc.column + 3 == 21 && loc.row + 3 <= 11) || (loc.row + 3 == 11 && loc.column + 3 <= 21))
					{
						turnHorizontally();
						turnVertically();
						loc.column -= 1;
						loc.row -= 1;
					}
					else
					{
						if (loc.column + 3 == 22 || loc.row + 3 == 12)
						{
							turnHorizontally();
							turnVertically();
							loc.column -= 3;
							loc.row -= 3;
						}
					}
				}
			}
		}
		else
		{
			if (horizontDirection == 'r' && verticalDirection == 'u')
			{
				if (loc.column + 3 <= 19 && loc.row - 3 >= -10)
				{
					loc.column += 3;
					loc.row -= 3;
				}
				else
				{
					if ((loc.column + 3 == 20 && loc.row - 3 >= -11) || (loc.row - 3 == -11 && loc.column + 3 <= 20))
					{
						turnHorizontally();
						turnVertically();
						loc.column += 1;
						loc.row -= 1;
					}
					else
					{
						if ((loc.column + 3 == 21 && loc.row - 3 >= -12) || (loc.row - 3 == -12 && loc.column + 3 <= 21))
						{
							turnHorizontally();
							turnVertically();
							loc.column -= 1;
							loc.row += 1;
						}
						else
						{
							if (loc.column + 3 == 22 || loc.row - 3 == -13)
							{
								turnHorizontally();
								turnVertically();
								loc.column -= 3;
								loc.row += 3;
							}
						}
					}
				}
			}
			else
			{
				if (horizontDirection == 'l' && verticalDirection == 'u')
				{
					if (loc.column - 3 >= -20 && loc.row - 3 >= -10)
					{
						loc.column -= 3;
						loc.row -= 3;
					}
					else
					{
						if ((loc.column - 3 == -21 && loc.row - 3 >= -11) || (loc.row - 3 == -11 && loc.column - 3 >= -21))
						{
							turnHorizontally();
							turnVertically();
							loc.column -= 1;
							loc.row -= 1;
						}
						else
						{
							if ((loc.column - 3 == -22 && loc.row - 3 >= -12) || (loc.row - 3 == -12 && loc.column - 3 >= -22))
							{
								turnHorizontally();
								turnVertically();
								loc.column += 1;
								loc.row += 1;
							}
							else
							{
								if (loc.column - 3 == -23 || loc.row - 3 == -13)
								{
									turnHorizontally();
									turnVertically();
									loc.column += 3;
									loc.row += 3;
								}
							}
						}
					}
				}
				else
				{
					if (horizontDirection == 'l' && verticalDirection == 'd')
					{
						if (loc.column - 3 >= -20 && loc.row + 3 <= 9)
						{
							loc.column -= 3;
							loc.row += 3;
						}
						else
						{
							if ((loc.column - 3 == -21 && loc.row + 3 <= 10) || (loc.row + 3 == 10 && loc.column - 3 >= -21))
							{
								turnHorizontally();
								turnVertically();
								loc.column -= 1;
								loc.row += 1;
							}
							else
							{
								if ((loc.column - 3 == -22 && loc.row + 3 <= 11) || (loc.row + 3 == 11 && loc.column - 3 >= -22))
								{
									turnHorizontally();
									turnVertically();
									loc.column += 1;
									loc.row -= 1;
								}
								else
								{
									if (loc.column - 3 == -23 || loc.row + 3 == 12)
									{
										turnHorizontally();
										turnVertically();
										loc.column += 3;
										loc.row -= 3;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

char Owl::getInitial() const
{
	return 'O';
}

void Owl::printDetails() const
{
	cout << name + "- Owl" + " " << loc;
}