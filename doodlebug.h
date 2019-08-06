#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"

class Doodlebug : public Organism
{
private:
	int timeStarve; // time step counter to keep track of doodlebug starvation period

public:
	Doodlebug(int, int); //default constructor to set row and column

	void set_timeStarve(int);
	int get_timeStarve();

	void virtual move(Organism***); // virtual included to allow separate move function based on class
	void virtual breed(Organism***); // likewise
};

#endif