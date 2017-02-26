#include <stdio.h>

/******************************************************************************
   This solution uses the concept of a pascal's triangle to find the combination
   of consecutive right or down steps to reach an edge on the grid, then outputs
   the lower right corner value.
******************************************************************************/

int main() {
	long long int grid[21][21]= {0};
	int i,j;

	for(i=0; i<21; i++) {
		for (j=0;j<21;j++){
			if (i==0||j==0)
				grid[i][j] = 1;
			else{
				grid[i][j] = grid[i-1][j]+grid[i][j-1];
			}
		}
	}
	
	printf("%lld\n", grid[20][20]);
}
