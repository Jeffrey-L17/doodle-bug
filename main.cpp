#include "menu.h"
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "grid.h"


int main()
{
	Organism*** test;
	test = createGrid();
	randomizeGrid(test);
	displayGrid(test);

	system("pause");
	return 0;
}