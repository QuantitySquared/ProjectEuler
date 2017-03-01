#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diagonal_right_product (int [][20], int, int);
int diagonal_left_product (int [][20], int, int);
int right_product (int [][20], int, int);
int down_product (int [][20], int, int);

int main() {
	char * test[20];
	int i=0, j=0;
	size_t bufsize = 60;
	int grid [20][20];
	int init=0;
	int tempProduct = 0;
	int largestProduct = 0;

	for(i=0; i<20; i++) {
		test[i] = (char *)malloc(bufsize* sizeof(char));
	}
	
	i=0;	
	while(!feof(stdin)){
		getline(&test[i], &bufsize , stdin);
		i++;
	}

	for(i=0; i<20; i++){
		for(j=0; j<20; j++) {
			if(!init) {
				grid[i][j] = atoi(strtok(test[i]," "));
				init = 1;
			}
			else
				grid[i][j] = atoi(strtok(NULL," "));
				
		}
		init = 0;
	}
	
	for(i=0; i<20; i++){
		free(test[i]);
	}

	for(i = 0; i<20; i++) {
		for (j=0; j<20; j++) {
			tempProduct = diagonal_right_product(grid, i, j);
			if (tempProduct > largestProduct)
				largestProduct=tempProduct;
			
			tempProduct = diagonal_left_product(grid, i, j);
			if (tempProduct > largestProduct)
				largestProduct=tempProduct;
			
			tempProduct = right_product(grid, i, j);
			if (tempProduct > largestProduct)
				largestProduct=tempProduct;
				
			tempProduct = down_product(grid, i, j);
			if (tempProduct > largestProduct)
				largestProduct=tempProduct;
			
		}
	}

	printf("%d\n", largestProduct);

	return 0;
}

int diagonal_right_product (int matrix[][20], int row, int column) {
	int i=0;
	int product=1;
	if(row+4 > 19 || column+4 > 19)
		return 0;

	else{
		for(i=0; i<4; i++) {
			product *= matrix[row+i][column+i];
		}

	}

	return product;
}

int diagonal_left_product (int matrix[][20], int row, int column) {
	int i = 0;
	int product = 1;
	if (row+4>19 || column-4 < 0)
		return 0;
	else{
		for(i=0; i<4; i++) {
			product *= matrix[row+i][column-i];
		}
	}
	return product;
}

int right_product (int matrix[][20], int row, int column) {
	int i = 0;
	int product = 1;
	if (column+4 > 19)
		return 0;
	else{
		for(i=0; i<4; i++) {
			product *= matrix[row][column+i];
		}
	}
	return product;
}

int down_product (int matrix[][20], int row, int column) {
	int i = 0;
	int product = 1;
	if (row+4>19)
		return 0;
	else{
		for(i=0; i<4; i++) {
			product *= matrix[row+i][column];
		}
	}
	return product;
}

