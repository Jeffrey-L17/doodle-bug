#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"

class Doodlebug : public Organism // derived class
{
private:
	int timeStarve; // time step counter to keep track of doodlebug starvation period

public:
	Doodlebug(int, int); //default constructor to set row and column

	void set_timeStarve(int);
	int get_timeStarve();

	void move(Organism***);
	void breed(Organism***); 
};

#endif