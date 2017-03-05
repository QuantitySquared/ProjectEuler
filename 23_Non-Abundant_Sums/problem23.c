#include <stdio.h>

int divisorSum(int);
int isAbundant(int *, int, int);

int main(){
	int max = 28123;
	int abundantList[20000] = {0};
	int abundantSum[28124] = {0};
	int abundantNumbers;
	int i, j;
	int temp=0;
	int sum = 0;
	int conditionsMet=0;

	for(i=1; i<=max; i++){
		if (divisorSum(i) > i){
			abundantList[abundantNumbers] = i;
			abundantNumbers++;
		}
	}

	for(i=0; i<abundantNumbers; i++){
		for (j=i; j < abundantNumbers; j++) {
			if(abundantList[i]+abundantList[j] <= max)
				abundantSum[abundantList[i]+abundantList[j]] = 1;
			else
				break;
		}
	}

	for(i=0; i<=max; i++){
		if(!abundantSum[i])
			sum+=i;
	}
/*
	for(i=1; i<max; i++){
		for(j=0; j<i; j++){
			if(isAbundant(abundantList, abundantNumbers, j) && isAbundant(abundantList, abundantNumbers, i-j)){
				conditionsMet=1;
				printf("%d\n", i);
				break;
			}
		}
		if (conditionsMet==0){
			sum+=i;
		}
		conditionsMet=0;
	}
*/	
	printf("%d\n", sum);

	return 0;
}

int divisorSum(int input) {
	int sum=0;
	int i;
	
	for(i=1; i<input; i++){
		if(input%i == 0)
			sum+=i;
	}

	return sum;
}

int isAbundant(int *abundantList, int abundantNums, int input){
	int i;
	for(i=0; i<abundantNums; i++){
		if (input == abundantList[i])
			return 1;
	}
	return 0;
}

