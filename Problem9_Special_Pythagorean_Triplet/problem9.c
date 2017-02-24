#include <stdio.h>
#include <math.h>

int main() {
	double a;
	double b;
	double c;
	double product;

	for(a=1; a<1000; a++) {
		for(b=1; b<1000; b++) {
			c = a*a + b*b;
			c = sqrt(c);

			if(floor(c) == c){
				if(a+b+c == 1000){
					product = a*b*c;
					printf("%f\n", product);
					return 0;
				}
			}	
		}
	}

	return 0;
}

