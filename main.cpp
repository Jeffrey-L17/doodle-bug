#include "declaration.h"
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "grid.h"


int main()
{
	srand(time(0));
	Organism*** test;
	test = createGrid();
	randomizeGrid(test);
	displayGrid(test);

	char input;
	cin.get(input);
	while (input == '\n')
	{
		resetMove(test);
		DoodleTurn(test);
		AntTurn(test);
		displayGrid(test);
		cin.get(input);
	}


	system("pause");
	return 0;
}