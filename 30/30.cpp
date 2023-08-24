#include <stdio.h>

constexpr auto MAX_SIZE = 101;

int main() {
	float sum = 0.00;
	for (double i = 1; i < MAX_SIZE; i++)
	{
		if ((int)i % 2 != 0) {
			sum += (1 / i);
		}else{
			sum -= (1 / i);
		}
	}
	printf_s("Sum=%f\n", sum);
}