#ifndef ANT_H
#define ANT_H

#include "organism.h"

// Comments for ant.h and ant.cpp will be intentionally left blank. The comments would be a replica
// of doodlebug.h and doodle.cpp, respectively, as they will have the same function as doodlebug
// minus the starvation function


class Ant : public Organism
{
public:
	Ant(int, int); //default constructor to set row and column

	void virtual move(Organism***);
	void virtual breed(Organism***);
};

#endif