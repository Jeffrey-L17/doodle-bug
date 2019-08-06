#include "organism.h"
#include "menu.h"

Organism::Organism()
{
	timeSteps = 0;
	movedStep = true;
}

void Organism::setRow(int r)
{
	x = r;
}

void Organism::setCol(int c)
{
	y = c;
}

void Organism::setType(bugType z)
{
	bugID = z;
}

bugType Organism::getType()
{
	return bugID;
}