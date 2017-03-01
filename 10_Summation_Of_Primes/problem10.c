#include <stdio.h>

int isPrime(int);

int main() {
	long long int primeSum=0;
	int limit = 2000000;
	
	int i=0;
	while(i<limit){
		if (isPrime(i))
			primeSum+=i;
		i++;
	}

	printf("%lld\n", primeSum);

	return 0;
}

int isPrime(int number){
	int i=5;
	if (number <= 1)
		return 0;
	else if (number<=3)
		return 1;
	else if (number%2==0 || number%3==0)
		return 0;
	while(i*i <= number) {
		if (number%i == 0 || number%(i+2) == 0)
			return 0;
		i += 6;
	}	
	return 1;
}

