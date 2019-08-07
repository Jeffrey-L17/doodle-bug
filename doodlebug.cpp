#include "doodlebug.h"
#include "declaration.h"
#include "grid.h"

Doodlebug::Doodlebug(int row, int col)
{
	setType(DOODLEBUG);
	setRow(row);
	setCol(col);
	set_timeStarve(0); // initialize starvation period to 0 
						// doodlebug dies when it reaches 3 without food
	set_timeSteps(0); // initialize survival period to 0
						// doodlebug breeds when it reaches 8
}

void Doodlebug::set_timeStarve(int t)
{
	timeStarve = t; // needed later to increment or reset starvation period
}

int Doodlebug::get_timeStarve()
{
	return timeStarve; // needed later to check status of starvation period
}

void Doodlebug::move(Organism*** grid)
{
	set_timeSteps(get_timeSteps() + 1); // grabs timeSteps and increments it to indicate survival period
	set_movedStep(true); // prevents moving more than once per turn

	bool spotFound = false; // stops loop if ant is eaten
	int num_check = 0; // or if all 4 directions are checked
	int checkUp = 0, checkRight = 0, checkDown = 0, checkLeft = 0;
	direction check;

	while (!spotFound && num_check < 4)
	{
		check = static_cast<direction>(rand() % 4);

		if (check == UP && !checkUp)
		{
			checkUp = 1;
			if (getRow() - 1 != -1) // prevent looping around grid
			{
				if (grid[getRow() - 1][getCol()] != NULL) // checks to see if there is a NULL space because getType..
				{											// would generate error on NULL space
					if (grid[getRow() - 1][getCol()]->getType() == ANT)
					{
						spotFound = true; // stops the check for food
						delete grid[getRow() - 1][getCol()]; // delete the ant
						grid[getRow() - 1][getCol()] = this; // copy ant's original position with 'this' doodlebug instance
						grid[getRow()][getCol()] = NULL; // set doodlebug's original position to NULL to empty it out
						setRow(getRow() - 1); // assign new position to this doodlebug
						set_timeStarve(0); // reset starvation period
					}
				}
			}
		}

		else if (check == RIGHT && !checkRight)
		{
			checkRight = 1;
			if (getCol() + 1 != 20) 
			{
				if (grid[getRow()][getCol() + 1] != NULL)
				{
					if (grid[getRow()][getCol() + 1]->getType() == ANT)
					{
						spotFound = true;
						delete grid[getRow()][getCol() + 1];
						grid[getRow()][getCol() + 1] = this;
						grid[getRow()][getCol()] = NULL;
						setCol(getCol() + 1);
						set_timeStarve(0);
					}
				}
			}
		}

		else if (check == DOWN && !checkDown)
		{
			checkDown = 1;
			if (getRow() + 1 != 20)
			{
				if (grid[getRow() + 1][getCol()] != NULL)
				{
					if (grid[getRow() + 1][getCol()]->getType() == ANT)
					{
						spotFound = true;
						delete grid[getRow() + 1][getCol()];
						grid[getRow() + 1][getCol()] = this;
						grid[getRow()][getCol()] = NULL;
						setRow(getRow() + 1);
						set_timeStarve(0);
					}
				}
			}
		}

		else if (check == LEFT && !checkLeft)
		{
			checkLeft = 1;
			if (getCol() - 1 != -1)
			{
				if (grid[getRow()][getCol() - 1] != NULL)
				{
					if (grid[getRow()][getCol() - 1]->getType() == ANT)
					{
						spotFound = true;
						delete grid[getRow()][getCol() - 1];
						grid[getRow()][getCol() - 1] = this;
						grid[getRow()][getCol()] = NULL;
						setCol(getCol() - 1);
						set_timeStarve(0);
					}
				}
			}
		}
		num_check = checkUp + checkRight + checkDown + checkLeft; // stops loop if all 4 directions are checked
	} 
	
	num_check = 0; // reset check values
	checkUp = 0, checkRight = 0, checkDown = 0, checkLeft = 0;
	
	if (!spotFound)
		set_timeStarve(get_timeStarve() + 1); // increment starvation period

	while (!spotFound && num_check != 4)
	{
		check = static_cast<direction>(rand() % 4);
		if (check == UP && !checkUp)
		{
			checkUp = 1;
			if (getRow() - 1 != -1) // prevent looping around grid
			{
				if (grid[getRow() - 1][getCol()] == NULL)
				{
					spotFound = true; // stops the check for empty spot
					grid[getRow() - 1][getCol()] = this; // replace new empty spot with 'this' doodlebug instance
					grid[getRow()][getCol()] = NULL; // set doodlebug's original position to NULL to empty it out
					setRow(getRow() - 1); // assign new position to this doodlebug
				}
			}
		}

		else if (check == RIGHT && !checkRight)
		{
			checkRight = 1;
			if (getCol() + 1 != 20)
			{
				if (grid[getRow()][getCol() + 1] == NULL)
				{
					spotFound = true;
					grid[getRow()][getCol() + 1] = this;
					grid[getRow()][getCol()] = NULL;
					setCol(getCol() + 1);
				}
			}
		}

		else if (check == DOWN && !checkDown)
		{
			checkDown = 1;
			if (getRow() + 1 != 20)
			{
				if (grid[getRow() + 1][getCol()] == NULL)
				{
					spotFound = true;
					grid[getRow() + 1][getCol()] = this;
					grid[getRow()][getCol()] = NULL;
					setRow(getRow() + 1);
				}
			}
		}

		else if (check == LEFT && !checkLeft)
		{
			checkLeft = 1;
			if (getCol() - 1 != -1)
			{
				if (grid[getRow()][getCol() - 1] == NULL)
				{
					spotFound = true;
					grid[getRow()][getCol() - 1] = this;
					grid[getRow()][getCol()] = NULL;
					setCol(getCol() - 1);
				}
			}
		}
		num_check = checkUp + checkRight + checkDown + checkLeft;
	}
	
	// deletes doodlebug if it hasn't eaten in three turns
	if (get_timeStarve() >= DOODLEBUG_survivalTime)
	{
		int row = getRow(), col = getCol(); // necessary because deleting object also deletes its member function
		delete grid[getRow()][getCol()];
		grid[row][col] = NULL;
	} 
} 

void Doodlebug::breed(Organism*** grid)
{
	bool spotFound = false; // only breeds if empty spot is found
	int num_check = 0;
	int checkUp = 0, checkRight = 0, checkDown = 0, checkLeft = 0;
	direction check;

	if (get_timeSteps() >= DOODLEBUG_breedTime)
	{
		while (!spotFound && num_check != 4)
		{
			check = static_cast<direction>(rand() % 4);

			if (check == UP && !checkUp)
			{
				checkUp = 1;
				if (getRow() - 1 != -1) // prevent looping around grid
				{
					if (grid[getRow() - 1][getCol()] == NULL)
					{
						spotFound = true; // stops the check for empty spot
						grid[getRow() - 1][getCol()] = new Doodlebug(getRow() - 1, getCol()); // replace new empty spot with 'this' doodlebug instance
						set_timeSteps(0); // reset survival period
					}
				}
			}

			else if (check == RIGHT && !checkRight)
			{
				checkRight = 1;
				if (getCol() + 1 != 20)
				{
					if (grid[getRow()][getCol() + 1] == NULL)
					{
						spotFound = true;
						grid[getRow()][getCol() + 1] = new Doodlebug(getRow(), getCol() + 1);
						set_timeSteps(0);
					}
				}
			}

			else if (check == DOWN && !checkDown)
			{
				checkDown = 1;
				if (getRow() + 1 != 20)
				{
					if (grid[getRow() + 1][getCol()] == NULL)
					{
						spotFound = true;
						grid[getRow() + 1][getCol()] = new Doodlebug(getRow() + 1, getCol());
						set_timeSteps(0);
					}
				}
			}

			else if (check == LEFT && !checkLeft)
			{
				checkLeft = 1;
				if (getCol() - 1 != -1)
				{
					if (grid[getRow()][getCol() - 1] == NULL)
					{
						spotFound = true;
						grid[getRow()][getCol() - 1] = new Doodlebug(getRow(), getCol() - 1);
						set_timeSteps(0);
					}
				}
			}
			num_check = checkUp + checkRight + checkDown + checkLeft;
		}
	}
}