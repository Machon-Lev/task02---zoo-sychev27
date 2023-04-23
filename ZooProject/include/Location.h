#include <iostream>
#include <string>
using namespace std;

struct Location
{
	int row;
	int column;

	Location operator+ (const Location& otherLoc) const;
	Location& operator+= (const Location& otherLoc);
	bool operator== (const Location& otherLoc);
	bool operator!= (const Location& otherLoc);
	friend ostream& operator<< (ostream& ostr, const Location& loc);
};


ostream& operator<< (ostream& ostr, const Location& loc);
