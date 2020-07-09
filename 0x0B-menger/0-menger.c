#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: the level of the Menger Sponge to draw
 *
 * Return: Nothing.
 **/

void menger(int level)
{
	int i = 0, j = 0, row = 0, col = 0, side = 0;
	char drawing;

	if (level < 0)
		return;

	side = pow(3, level);

	while (i < side)
	{
		for (j = 0; j < side; j++)
		{
			row = i;
			col = j;
			drawing = '#';

			while (row > 0 && col > 0)
			{
				if (row % 3 == 1 && col % 3 == 1)
					drawing = ' ';
				row = row / 3;
				col = col / 3;
			}
			printf("%c", drawing);
		}
		printf("\n");
		i++;
	}
}
