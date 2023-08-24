#include <stdio.h>

int main() {
	int a = 0, n = 0, sn = 0, temp = 0;
	printf_s("求解sn=a+aa+aaa+...+aaa...aa..a\n");
	printf_s("请输入a和n，以空格分割\n");
	scanf_s("%d", &a);
	scanf_s("%d", &n);

	for (size_t i = 0; i < n; i++)
	{
		temp *= 10;
		temp += a;
		sn += temp;
	}
	printf_s("sn = %d", sn);
}