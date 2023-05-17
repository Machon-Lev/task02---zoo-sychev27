#include "Zoo.h"

void Zoo::createZoo()
{
	int column = rand() % 39 - 20;
	int row = rand() % 19 - 10;
	zoo.push_back(new Lion("Simba", row, column, 'r', 't'));
	column = rand() % 39 - 20;
	row = rand() % 19 - 10;
	zoo.push_back(new Lion("Mufasa", row, column, 'l', 't'));
	column = rand() % 39 - 20;
	row = rand() % 19 - 10;
	zoo.push_back(new Owl("Hedwin", row, column, 'l', 'd'));
	column = rand() % 39 - 20;
	row = rand() % 19 - 10;
	zoo.push_back(new Dog("Toto", row, column, 'l', 'd'));
}


void Zoo::run()
{
	srand((unsigned)time(NULL));
	createZoo();
	draw();
	char typeOfAnimal;
	int numOfAnimal;
	string name;
	string command;
	help();
	cout << "Enter your command\n";
	cin >> command;
	while (command != "exit")
	{
		if (command == "stop")
		{
			cin >> numOfAnimal;
			stop(numOfAnimal);
		}
		if (command == "move")
		{
			cin >> numOfAnimal;
			move(numOfAnimal);
		}
		if (command == "create")
		{
			cin >> typeOfAnimal;
			cin >> name;
			create(typeOfAnimal, name);
			draw();
		}
		if (command == "del")
		{
			cin >> numOfAnimal;
			del(numOfAnimal);
			draw();
		}
		if (command == "delAll")
		{
			cin >> typeOfAnimal;
			delAll(typeOfAnimal);
			draw();
		}
		if (command == ".")
		{
			nextTurn();
			draw();
		}
		if (command == "help")
		{
			help();
		}
		cout << "Enter your command\n";
		cin >> command;
	}
}

void Zoo::draw()
{
	int numOfAnimalToDraw;
	for (int i = -10; i < 10 ; i++)
	{
		for (int j = -20; j < 20; j++)
		{
			numOfAnimalToDraw = -1;
			for (size_t k = 0; k < zoo.size(); k++)
			{
				if (zoo[k]->getLocation().row == i && zoo[k]->getLocation().column == j)
				{
					numOfAnimalToDraw = k;
					break;
				}
			}
			if (numOfAnimalToDraw >= 0)
			{
				cout << " " << zoo[numOfAnimalToDraw]->getInitial();
			}
			else
			{
				cout << " *";
			}
		}
		cout << "\n";
	}
	int size = zoo.size();
	for (size_t i = 0; i < size; i++)
	{
		cout << i << " ";
		zoo[i]->printDetails();
		cout << "\n";
	}
	cout << "\n";
}

void Zoo::stop(int numOfAnimal)
{
	zoo[numOfAnimal]->stop();
}

void Zoo::move(int numOfAnimal)
{
	zoo[numOfAnimal]->move();
}

void Zoo::create(char type, string name)
{
	int column = rand() % 39 - 20;
	int row = rand() % 19 - 10;
	switch (type)
	{
	case 'L':
		zoo.push_back(new Lion(name, row, column, 'r', 'u'));
		break;
	case 'D':
		zoo.push_back(new Dog(name, row, column, 'r', 'u'));
		break;
	case 'O':
		zoo.push_back(new Owl(name, row, column, 'r', 'u'));
		break;
	default:
		break;
	}
}

void Zoo::del(int numOfAnimal)
{
	int size = zoo.size();
	if (numOfAnimal >= size || numOfAnimal < 0)
	{
		cout << "enter valid index\n";
		return;
	}
	try 
	{
		zoo.erase(zoo.begin() + numOfAnimal);
	}
	catch(const overflow_error& e)
	{
		cout << "enter valid index";
	}
	catch (const runtime_error& e)
	{
		cout << "enter valid index";
	}
	catch (...)
	{
		cout << "enter valid index";
	}
}

void Zoo::delAll(char type)
{
	int size = zoo.size();
	for (size_t i = 0; i < size; i++)
	{
		if (zoo[i]->getInitial() == type)
		{
			zoo.erase(zoo.begin() + i);
			size--;
			i --;
		}
	}
}

void Zoo::nextTurn()
{
	int size = zoo.size();
	for (size_t i = 0; i < size; i++)
	{
		zoo[i]->step();
	}
}

void Zoo::help()
{
	cout << "stop - Make the animal stop, takes as a parameter the number of the animal as it appears inthe list.\n";
	cout << "move - Make the animal able to move, takes as a parameter the number of the animal as it appears inthe list.\n";
	cout << "create - Create a new animal, takes as a parameters the type of animal as a first big letter and name of the animal.\n";
	cout << "del - delete the animal from list, takes as parameter the number of the animal as it appears inthe list.\n";
	cout << "delAll - delete all animals of a certain type, takes as parameter the type of animal as a first big letter.\n";
	cout << ". - Causes the program to advance to the next turn, meaning that all animals in motion continue to move according to the rules.\n";
	cout << "exit - Exit the program.\n\n";
}
