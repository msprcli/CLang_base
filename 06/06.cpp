#include <stdio.h>

void printFn(int a, int b, int n) {
	if (n > 0) {
		printf_s("%d ", a + b);
		printFn(b, a + b, n - 1);
	}
}

int main()
{
	int a = 1, b = 1, n = 0;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		printf_s("1");
		break;
	case 2:
		printf_s("1 1");
		break;
	default:
		printf_s("1 1 ");
		printFn(a, b, n-2);
		break;
	}
}