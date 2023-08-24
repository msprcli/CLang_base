#include <stdio.h>

int main() {
	char str1[100] = "Hello World!";
	char str2[100] = "";
	char* ptr1 = str1;
	char* ptr2 = str2;
	int length = 0;
	printf_s("str1: ");
	while (*ptr1 != '\0')
	{
		length++;
		printf_s("%c", *ptr1);
		ptr1++;
	}
	ptr1 = str1;
	ptr2 += length;
	for (size_t i = 0; i < length; i++)
	{
		*ptr2 = *ptr1;
		ptr1++;
		ptr2--;
	}
	printf_s("\nstr2: ");
	for (size_t i = 0; i < length+1; i++)
	{
		printf_s("%c", str2[i]);
	}
}