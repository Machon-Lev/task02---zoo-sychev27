#include "Animal.h"

class Owl : public Animal
{
public:
	Owl(string name, int row, int column, char horizontDirection, char verticalDirection);
	void step() override;
	char getInitial() const override;
	void printDetails() const override;

private:

};