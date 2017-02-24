#include <stdio.h>

int IsPalindrome(int);

int main() {
	int i;
	int j; 
	int k;
	int largest=0;

	for (i=999; i>0; i--){
		for (j=999; j>0; j--) {
			k = i * j;
			if(IsPalindrome(k)){
				if(k>largest)
					largest = k;
			}

		}
	}
	printf("%d\n",largest);

	return 0;	
}

int IsPalindrome(int number) {
	int forward = number;
	int reverse=0;

	while(forward > 0){
		reverse = reverse*10 + forward%10;
		forward /= 10;
	}
	if (number == reverse)
		return 1;
	else
		return 0;
}

