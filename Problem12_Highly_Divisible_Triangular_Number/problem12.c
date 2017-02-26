#include <stdio.h>

int main() {
	int divisors=0;
	long long int triangleSum;
	long long int i=0;
	int triangleNumber=1;

	while (divisors<= 500) {
		triangleSum = 0;
		divisors=0;

		for(i = 1; i <= triangleNumber; i++) {
			triangleSum+=i;
		}	


		for(i = 1; i*i<=triangleSum; i++) {
			if(triangleSum%i==0){
				divisors++;
			}
		}

		divisors *=2;

		triangleNumber++;
	}

	printf("%lld\n", triangleSum);

	return 0;
}
