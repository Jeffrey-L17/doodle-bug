// Jeffrey Liu
// Program 8: 2D Doodlebugs-Ant simulation
// July 7, 2019

#include "declaration.h"
#include "organism.h"
#include "ant.h"
#include "doodlebug.h"
#include "grid.h"


int main()
{
	srand(time(0)); // seed value random number generator based on time
	Organism*** test;
	test = createGrid();
	randomizeGrid(test);
	int counter = 1;

	cout << "Here is a 20 by 20 grid depiction of Doodlebugs (X) preying on Ants (O).\n";
	cout << "Hit the ENTER key to see the next phase. Input any other key to end the program.\n";
	cout << "Tip: You can hold the ENTER key to view the phases quickly.\n\n";
	cout << "This is turn order #" << counter;
	cout << ". There are " << doodleCount(test) << " doodlebugs and " << antCount(test) << " ants.\n\n";
	displayGrid(test);

	char input;
	cin.get(input);

	while (input == '\n') // allow use to hit ENTER key to see next phase
	{
		counter++;
		cout << "This is turn order #" << counter;
		resetMove(test);
		DoodleTurn(test);
		AntTurn(test);
		cout << ". There are " << doodleCount(test) << " doodlebugs and " << antCount(test) << " ants.\n\n";
		displayGrid(test);
		cin.get(input);
	}
	
	deleteGrid(test); // deallocating the pointer grid
	system("pause");
	return 0;
}