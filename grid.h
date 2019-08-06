#ifndef GRID_H
#define GRID_H

#include "organism.h"
#include "menu.h"

Organism*** createGrid();
void randomizeGrid(Organism***); //randomly populate the grid
void displayGrid(Organism***); // display what's currently on the grid
void destroyGrid(Organism***);





#endif
