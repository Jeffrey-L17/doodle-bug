#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"

class Doodlebug : public Organism
{
public:
	Doodlebug(int, int); //default constructor to set row and column

	void move(Organism***);
	void breed(Organism***);
};

#endif