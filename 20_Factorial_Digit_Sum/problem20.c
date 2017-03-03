#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * largeMult(int * multiplicand, int multiplier);

int main() {
	int * multiplicand;
	int multiplier;
	int i;
	int sum= 0;

	multiplicand = (int *) malloc(500*sizeof(int));
	for (i=0; i<500; i++) {
		multiplicand[i] = 0;
	}

	multiplier=1; 
	multiplicand[0] = 0;
	multiplicand[1] = 0;
	multiplicand[2] = 1;


	for(multiplier=1; multiplier<100; multiplier++) {
		multiplicand = largeMult(multiplicand, multiplier);
	}

	for(i=0; i<500; i++){
		sum += multiplicand[i];
	}

	free(multiplicand);

	printf("%d\n", sum);
}

int * largeMult(int * multiplicand, int multiplier) {
	int * temp;
	int carry=0;
	int i = 0;
	int j = 0;
	int number;

	temp = (int *) malloc(500*sizeof(int));
	memcpy(temp, multiplicand, 500*sizeof(int));

	for(i=0; i< multiplier-1; i++) {

		for(j = 0; j < 500; j++) {
			number = multiplicand[j] + temp[j]+ carry;
			if (number < 10){
				multiplicand[j] = number;
				carry = 0;
			}
			else{
				number -= 10;
				multiplicand[j] = number;
				carry = 1;
			}
		}

	}

	free(temp);

	return multiplicand;

}

