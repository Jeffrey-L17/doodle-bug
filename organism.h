#ifndef ORGANISM_H
#define ORGANISM_H

enum bugType {ANT, DOODLEBUG}; // enumerated to allow only these 2 bug types
enum direction {UP, DOWN, LEFT, RIGHT}; // enumerated to allow only these 4 directions

class Organism
{
private:
	bugType bugID; // Critter Identification
	int x; // x-coordinate position on the grid
	int y; // y-coordinate position on the grid

	int timeSteps; // time-steps to keep track of breeding time for both critters
	int timeStarve; // time step counter to keep track of doodlebug starvation period
	bool movedStep; // indicating whether the critter object has already moved
	
public:
	Organism(); // Default constructor that initialize timeSteps to 0 and movedStep to true
				// to prevent movement upon spawn

	void setRow(int);
	void setCol(int);
	void setType(bugType);
	bugType getType();

	
	

};







#endif