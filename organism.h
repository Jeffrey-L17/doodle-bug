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
	bool movedStep; // indicating whether the critter object has already moved
	
public:
	Organism(); // Default constructor that initialize timeSteps to 0 and movedStep to true...
				// to prevent movement upon spawn

	void setRow(int);
	int getRow(); // needed to prevent looping grid row-wise
	void setCol(int);
	int getCol(); // needed to prevent looping grid column-wise
	void setType(bugType);
	bugType getType();

	void set_timeSteps(int); // important to keep track of breeding period
	int get_timeSteps();

	void set_movedStep(bool); // important to keep track of which critters moved because it could...
	bool get_movedStep(); // move to a latter part of the array and move again repeatedly
	
	void move(Organism***);
	void breed(Organism***);

};







#endif