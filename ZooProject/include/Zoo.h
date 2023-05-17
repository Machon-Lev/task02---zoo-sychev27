//#include "Animal.h"
#include "Lion.h"
#include "Owl.h"
#include "Dog.h"
#include <vector>

class Zoo
{
public:
	void run();

private:
	vector <Animal*> zoo;
	void createZoo();
	void draw();
	void stop(int numOfAnimal);
	void move(int numOfAnimal);
	void create(char type, string name);
	void del(int numOfAnimal);
	void delAll(char type);
	void nextTurn();
	void help();

};

