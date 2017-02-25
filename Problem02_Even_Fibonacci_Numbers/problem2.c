#include <stdio.h>

int main() {
	int first=1;
	int second=2;
	int temp=0;
	int sum=2;
	
	while(second<4000000){
		temp = first;
		first = second;
		second += temp;
		if (second%2==0)
			sum+=second;
	}	
	printf("%d\n", sum);
	return 0;
}
