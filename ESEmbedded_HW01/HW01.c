#include <stdio.h>
#include <stdlib.h>

int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divided(int a, int b) { return a / b; }

static int(*funcPtr[])(int, int)={plus, minus, multiply, divided}; 

int main()
{
	int a, c;
	char b;
	printf("key a Function \nEX: 1 + 1\n");
	scanf("%i %c %i", &a, &b, &c);
	//IF ELSE IF
	if (b == '+')
		printf("%d %c %d = %d\n", a, b, c, funcPtr[0](a, c));
	else if (b == '-')
		printf("%d %c %d = %d\n", a, b, c, funcPtr[1](a, c));
	else if (b == '*')
		printf("%d %c %d = %d\n", a, b, c, funcPtr[2](a, c));
	else if (b == '/')
		printf("%d %c %d = %d\n", a, b, c, funcPtr[3](a, c));
}
