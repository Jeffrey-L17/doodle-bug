#include "ant.h"
#include "declaration.h"
#include "grid.h"

// refer to doodlebug.cpp for replica comments

Ant::Ant(int row, int col)
{
	setType(ANT);
	setRow(row);
	setCol(col);
	set_timeSteps(0); 
}

void Ant::move(Organism*** grid)
{
	set_timeSteps(get_timeSteps() + 1); 
	set_movedStep(true); 

	bool spotFound = false;
	int num_check = 0;
	int checkUp = 0, checkRight = 0, checkDown = 0, checkLeft = 0;
	direction check;

	while (!spotFound && num_check != 4)
	{
		check = static_cast<direction>(rand() % 4);

		if (check == UP && !checkUp)
		{
			checkUp = 1;
			if (getRow() - 1 != -1)
			{
				if (grid[getRow() - 1][getCol()] == NULL)
				{
					spotFound = true; 
					grid[getRow() - 1][getCol()] = this;
					grid[getRow()][getCol()] = NULL;
					setRow(getRow() - 1);
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
}

void Ant::breed(Organism*** grid)
{
	bool spotFound = false;
	int num_check = 0;
	int checkUp = 0, checkRight = 0, checkDown = 0, checkLeft = 0;
	direction check;

	if (get_timeSteps() >= ANT_breedTime)
	{
		while (!spotFound && num_check != 4)
		{
			check = static_cast<direction>(rand() % 4);

			if (check == UP && !checkUp)
			{
				checkUp = 1;
				if (getRow() - 1 != -1)
				{
					if (grid[getRow() - 1][getCol()] == NULL)
					{
						spotFound = true;
						grid[getRow() - 1][getCol()] = new Ant(getRow() - 1, getCol());
						set_timeSteps(0);
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
						grid[getRow()][getCol() + 1] = new Ant(getRow(), getCol() + 1);
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
						grid[getRow() + 1][getCol()] = new Ant(getRow() + 1, getCol());
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
						grid[getRow()][getCol() - 1] = new Ant(getRow(), getCol() - 1);
						set_timeSteps(0);
					}
				}
			}
			num_check = checkUp + checkRight + checkDown + checkLeft;
		}
	}
}