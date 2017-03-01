#include <stdio.h>
#include <math.h>

int main() {
	long long int number = 600851475143;
	int divisor = 2;
	while (number > 1) {
		if (number % divisor == 0) {
			number /= divisor;
			divisor--;
		}
		divisor++;
	}
	printf("%d\n", divisor);

	return 0;
}

