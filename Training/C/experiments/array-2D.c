#include <stdio.h>
#include <stdlib.h>

//using single pointer creating 2D array using dynamic memory allocation
#if 0
int main (void)
{
	int *ptr;
	int row = 4;
	int column = 3;
	int i = 0;
	int j = 0;

	ptr = malloc(sizeof(int) * row * column);

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf ("%d ", ptr);
			ptr++;
		}
	}

	ptr = ptr - 12;

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf ("%d ", *ptr);
			ptr++;
		}
		printf ("\n");
	}
	free(ptr);
	return 0;
}
#endif

//using array of pointers to create 2D array 
#if 0
int main (void)
{
	int row = 3;
	int *ptr[row];
	int column = 4;
	int i = 0;
	int j = 0;

	for (i = 0; i < column; i++)
		ptr[i] = malloc(sizeof(int) * column);

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			scanf ("%d ", (ptr[i] + j));
//			scanf ("%d ", &(ptr[i][j]));
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf ("%d ", *(ptr[i] + j));
//			printf ("%d ", (ptr[i][j]));
		}
		printf ("\n");
	}
	return 0;
}
#endif

//using double pointers to create 2D array 
#if 1
int main (void)
{
	int **ptr;
	int row = 4;
	int column = 5;
	int i = 0;
	int j = 0;

	ptr = malloc(sizeof(int) * row);

	for (i = 0; i < column; i++)
		ptr[i] = malloc(sizeof(int) * column);

	ptr[0][4] = 5;
	ptr[1][3] = 4;
	ptr[2][2] = 3;
	ptr[3][1] = 2;

	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++) {
			printf ("%d ", ptr[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
#endif

