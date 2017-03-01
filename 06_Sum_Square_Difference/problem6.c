#include <stdio.h>

int SumOfSquares(int);
int SquareOfSum(int);

int main() {
	int num = 100;
	int difference = SquareOfSum(num) - SumOfSquares(num);
	printf("%d\n", difference);

	return 0;
}

int SumOfSquares(int number){
	int i;
	int sum = 0;
	for (i=1; i<=number; i++) {
		sum += i*i;
	}
	return sum;
}

int SquareOfSum(int number){
	int i;
	int sum = 0;
	for (i=1; i<=number;i++) {
		sum += i;
	}
	sum *= sum;

	return sum;
}

