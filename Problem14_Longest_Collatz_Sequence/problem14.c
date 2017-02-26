#include <stdio.h>

int collatz(long long int );

int main() {
	int longestChain=0;
	long long int startNumber=0;
	int tempChain=0;
	long long int i;
	
	for(i=0; i<1000000; i++) {
		tempChain = collatz(i);
		if(longestChain < tempChain){
			longestChain = tempChain;
			startNumber = i;
		}
	}

	printf("%d\n", startNumber);
}

int collatz(long long int start) {
	if(start == 0)
		return 0;
	if(start ==1)
		return 1;
	else if(start % 2 == 0){
		start /= 2;
		return (1 + collatz(start));
	}
	else {
		start = 3*start+1;
		return (1 + collatz(start));
	}	
}
