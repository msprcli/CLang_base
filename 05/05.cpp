#include <stdio.h>

int main()
{
	double height = 10.00, length = 0.00;
	length += height;
	while (height > 0) {
		height /= 2;
		length += height;
	}
	printf_s("length:%f", length);
}