#include "grid.h"
#include "ant.h"
#include "doodlebug.h"
#include "declaration.h"

Organism*** createGrid()
{
	Organism*** grid;
	grid = new Organism**[DIMENSION]; //create dynamic array of pointers to Organism type

	for (int i = 0; i < DIMENSION; i++)
		grid[i] = new Organism*[DIMENSION]; // make each pointer in the grid point to dynamic
											// array of actual Organism values
	for (int i = 0; i < DIMENSION; i++)
		for (int j = 0; j < DIMENSION; j++)
			grid[i][j] = NULL; // Traversing the array and populating it with NULL values

	return grid;
}

void randomizeGrid(Organism*** grid)
{
	int num_Ants = 0;
	while (num_Ants < init_ANT)
	{
		int row = rand() % DIMENSION; // randomly generate x,y coordinates
		int col = rand() % DIMENSION;
		if (grid[row][col] == NULL) // checks to see if there's an empty spot
		{
			grid[row][col] = new Ant(row, col); // assigns new ant to empty position
			num_Ants++;
		}
	}
	int num_Doodles = 0;
	while (num_Doodles < init_DOODLEBUG)
	{
		int row = rand() % DIMENSION; // randomly generate x,y coordinates
		int col = rand() % DIMENSION;
		if (grid[row][col] == NULL) // checks to see if there's an empty spot
		{
			grid[row][col] = new Doodlebug(row, col); // assigns new doodlebug to empty position
			num_Doodles++;
		}
	}
}

void displayGrid(Organism*** grid)
{
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col] == NULL)
				cout << "-";
			else if (grid[row][col]->getType() == ANT)
				cout << "O";
			else if (grid[row][col]->getType() == DOODLEBUG)
				cout << "X";
		}
		cout << endl;
	}

}

void resetMove(Organism*** grid)
{
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col] != NULL) // checks for critters in position
				grid[row][col]->set_movedStep(false); // reset moved to false
		}
	}
}

void DoodleTurn(Organism*** grid)
{
	// Movement Phase
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col]->getType() == DOODLEBUG)
			{
				if (grid[row][col]->get_movedStep() == false)
					grid[row][col]->move(grid);
			}
		}
	}

	// Breeding Phase
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col]->getType() == DOODLEBUG)
					grid[row][col]->breed(grid);
		}
	}
}

void AntTurn(Organism*** grid)
{
	// Movement Phase
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col]->getType() == ANT)
			{
				if (grid[row][col]->get_movedStep() == false)
					grid[row][col]->move(grid);
			}
		}
	}

	// Breeding Phase
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			if (grid[row][col]->getType() == ANT)
				grid[row][col]->breed(grid);
		}
	}
}

void deleteGrid(Organism*** grid)
{
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			delete grid[row][col]; // deleting independent objects
		}
		delete[] grid[row]; // deleting dynamically allocated array
	}
	delete[] grid; // deleting entire grid
}