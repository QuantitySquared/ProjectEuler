#include <stdio.h>

int twentyNumberMultiple(int);

int main() {
	int num = 1;

	while (!twentyNumberMultiple(num))
	{
		num++;
	}
	printf("%d\n", num);
	return 0;
}

int twentyNumberMultiple(int number){
	int i;
	for (i = 1; i<21; i++)
	{
		if (number % i != 0)
			return 0;
	}
	return 1;
}

