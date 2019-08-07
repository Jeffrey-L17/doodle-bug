#ifndef GRID_H
#define GRID_H

#include "organism.h"
#include "declaration.h"

Organism*** createGrid();
void randomizeGrid(Organism***); //randomly populate the grid
void displayGrid(Organism***); // display what's currently on the grid
int doodleCount(Organism***); // keep count of doodlebugs for display
int antCount(Organism***); // likewise for ant

void resetMove(Organism***); // Critter's move is reset to false to allow movement next turn
void DoodleTurn(Organism***); // Doodlebugs' turn order
void AntTurn(Organism***); // Ants' turn order

void deleteGrid(Organism***); // deallocating grid to free memory



#endif
