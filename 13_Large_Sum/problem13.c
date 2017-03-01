#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseString(char *);
char * stringAdder(char *, char *);

int main() {
	char * sum;
	char * input[100];
	size_t bufsize = 50;
	int i,j;

	sum = (char *)malloc(60*sizeof(char));
	
	for(i=0; i<60; i++) {
		sum[i] = '0';
	}
	sum[99] = '\0';	


	for(i=0; i<100; i++) {
		input[i] = (char *)malloc(bufsize*sizeof(char));
	}

	for(i=0; i<100; i++) {
		getline(&input[i], &bufsize, stdin);
	}

	
	for(i=0; i<100; i++) {
		input[i] = reverseString(input[i]);
	}

	for(i=0;i<100; i++) {
		sum = stringAdder(sum, input[i]);
	}

	sum = reverseString(sum);

	printf("%s\n",sum); 
	return 0;
}

char * reverseString(char * input) {
	int i;
	char temp;
	size_t length;
	length = strlen(input);
	
	for(i=0; i<(length-1)/2+1; i++) {
		temp = input[i];
		input[i]= input[length-2-i];
		input[length-2-i] = temp;
	}
	
	return input;
}

char * stringAdder(char sum[], char addend[]) {
	int i;
	size_t sumLength, addendLength;
	int carry=0;
	int number;
	
	sumLength = strlen(sum);
	addendLength = strlen(addend);

	for(i=0; i<sumLength-1;i++) {

		if(i<=addendLength-2){
			number = sum[i] - '0';
			number += addend[i] - '0';
			number += carry;
			if(number>=10){
				number -= 10;
				sum[i] = number + '0';
				carry = 1;
			}	
			else{
				sum[i] = number + '0';
				carry = 0;
			}
		}
		else{
			number = sum[i] - '0';
			number += carry;
			if(number>=10){
				number -= 10;
				sum[i] = number +'0';
				carry = 1;
			}
			else {
				sum[i] = number + '0';
				carry = 0;
			}
		}
	}
	return sum;
}	

