#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Free the memory allocated for a 2D grid
 * @grid: 2D grid
 * @height: Height dimension of the grid
 *
 * Description: Frees the memory used by the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
