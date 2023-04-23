#include "Animal.h"

class Lion : public Animal
{
public:
	Lion(string name, int row, int column, char horizontDirection, char verticalDirection);
	void step() override;
	char getInitial() const override;
	void turnVertically() override {};
	void printDetails() const override;
	void move() override;

private:

};

