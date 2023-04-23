#include "Location.h"

ostream& operator<< (ostream& ostr, const Location& loc)
{
	return ostr << "Row: " + to_string(loc.row) + " Column: " + to_string(loc.column);
}

Location Location::operator+ (const Location& otherLoc) const
{
	Location newLoc;
	newLoc.row = row + otherLoc.row;
	newLoc.column = column + otherLoc.column;
	return newLoc;
}

Location& Location::operator+= (const Location& otherLoc)
{
	return *this = *this + otherLoc;
}


bool Location::operator== (const Location& otherLoc)
{
	return this->row == otherLoc.row && this->column == otherLoc.column;
}

bool Location::operator!= (const Location& otherLoc)
{
	return !(*this == otherLoc);
}