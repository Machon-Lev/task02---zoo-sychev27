#include "Animal.h"

class Dog : public Animal
{
	bool bigStep;
public:
	Dog(string name, int row, int column, char horizontDirection, char verticalDirection);
	void step() override;
	char getInitial() const override;
	void turnVertically() override {};
	void printDetails() const override;
	void move() override;

private:

};