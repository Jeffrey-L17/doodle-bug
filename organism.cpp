#include "organism.h"
#include "declaration.h"

Organism::Organism()
{
	timeSteps = 0;
	movedStep = true;
}

void Organism::setRow(int r)
{
	x = r;
}

int Organism::getRow()
{
	return x;
}

void Organism::setCol(int c)
{
	y = c;
}

int Organism::getCol()
{
	return y;
}

void Organism::setType(bugType z)
{
	bugID = z;
}

bugType Organism::getType()
{
	return bugID;
}

void Organism::set_timeSteps(int s)
{
	timeSteps = s;
}

int Organism::get_timeSteps()
{
	return timeSteps;
}

void Organism::set_movedStep(bool m)
{
	movedStep = m;
}

bool Organism::get_movedStep()
{
	return movedStep;
}

void Organism::move(Organism***)
{
	cout << "ERROR "; // should not resort to Organism move function, have
					// to use virtual function from doodlebug or ant
}

void Organism::breed(Organism***)
{
	cout << "ERROR "; // should not resort to Organism breed function, have
					// to use virtual function from doodlebug or ant
}