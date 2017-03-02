#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int triangleMatrix[15][15] = {0};
	int arraySize = 15;
	int i=0, j=0;
	int left,right,top;
	size_t bufsize = 50;
	char * temp = (char *)malloc(bufsize*sizeof(char));
	char * token;

	while(!feof(stdin)){
		getline(&temp, &bufsize, stdin);
		token = strtok(temp," ");
		while(token!= NULL){
			triangleMatrix[i][j] = atoi(token);
			token = strtok(NULL, " ");

			j++;
		}
		j=0;
		i++;
	}
	
	i=0;
	i=0;	
	while(arraySize-1-i > 0){
		while (j<arraySize-1){
			left = triangleMatrix[arraySize-1-i][j];
			right = triangleMatrix[arraySize-1-i][j+1];
			top = (left > right) ? left : right;
			triangleMatrix[arraySize-2-i][j] += top;
			j++;
		}
		j=0;
		i++;	
	}

	for(i=0; i<15; i++){
		for(j=0; j<15; j++){
			printf("%10d", triangleMatrix[i][j]);
		}
		printf("\n");
	}
}

