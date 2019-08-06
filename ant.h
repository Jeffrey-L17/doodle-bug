#ifndef ANT_H
#define ANT_H

#include "organism.h"

class Ant : public Organism
{
public:
	Ant(int, int); //default constructor to set row and column

	void move(Organism***);
	void breed(Organism***);
};

#endif