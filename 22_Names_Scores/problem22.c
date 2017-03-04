#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quickSort(char **, int, int);
int partition(char **, int, int);
int letterScore(char * );

int main (){
	char * largeInput;
	size_t numCharacters = 50000;
	char * sortingArray[6000];
	int i;
	char *token;
	int numNames;
	char *newLine;
	long long int nameScore=0;

	token = (char *)malloc(20*sizeof(char));
	largeInput = (char *)malloc(numCharacters*sizeof(char));
	for(i=0; i<6000; i++){
		sortingArray[i] = malloc(20*sizeof(char));
	}
	getline(&largeInput, &numCharacters, stdin);

	numNames=0;
	token = strtok(largeInput,",");
	while(token != NULL){
		strcpy(sortingArray[numNames],token);

		newLine = strchr(sortingArray[numNames], '\n');
		if (newLine!= NULL) {
			*newLine = '\0';
		}
		
		token = strtok(NULL, ",");
		numNames++;
	}

	
	quickSort(sortingArray, 0, numNames-1);

	for(i=0; i<numNames; i++){
		nameScore += (i+1) * letterScore(sortingArray[i]);
	}

	printf("%lld\n", nameScore); 

	return 0;
}

void quickSort(char ** array, int first, int last){
	int p;
	if(first<last){
		p = partition(array, first, last);
		quickSort(array, first, p-1);
		quickSort(array, p+1, last);
	}
}

int partition(char ** array, int first, int last){
	char pivot[18];
	char temp[18];
	int i = first-1;
	int j;

	strcpy(pivot, array[last]);

	for(j=first; j<last; j++){
		if(strcmp(array[j], pivot)<=0){
			i++;
			strcpy(temp, array[i]);
			strcpy(array[i], array[j]);
			strcpy(array[j], temp);
		}
	}
	strcpy(temp, array[i+1]);
	strcpy(array[i+1], array[last]);
	strcpy(array[last], temp);
	return i+1;
}

int letterScore(char * string) {
	int sum=0;
	char letters[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int i;
	int j;

	i=0;
	while(string[i] != '\0'){
		if (string[i] != '\"'){
			for(j=0;j<26;j++){
				if (string[i]==letters[j])
					sum+=j+1;
			}
		}
		i++;
	}

	return sum;
}
