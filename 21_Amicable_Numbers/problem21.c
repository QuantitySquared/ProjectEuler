#include <stdio.h>

int insertIntoArray(int *, int, int);
int findInArray(int *, int, int);
int sumOfDivisors(int);

int main() {
	int max= 10000;
	int i;
	int storageArray[50] = {0};
	int amicableNums = 0;
	int divisorSum;
	int sum=0;

	for(i=1; i<=max; i++){
		divisorSum = sumOfDivisors(i);
		if (i!=divisorSum && i==sumOfDivisors(divisorSum) && divisorSum < max){
			if(!findInArray(storageArray, amicableNums, divisorSum)){
				insertIntoArray(storageArray, amicableNums, divisorSum);
				amicableNums++;
				sum += divisorSum;
			}
		}
	}

	printf("%d\n", sum);


}

int insertIntoArray(int * array, int elements, int num){
	array[elements] = num;
	return 1;
}

int findInArray( int * array, int elements, int num){
	int i;
	for (i=0; i<elements; i++){
		if(num == array[i])
			return 1;
	}
	return 0;
}

int sumOfDivisors(int num) {
	int sum=0;
	int i;
	
	for(i=1; i<num; i++){
		if (num%i == 0)
			sum += i;
	}

	return sum;

}
