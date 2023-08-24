#include<stdio.h>
/// <summary>
/// 将str1中第i个字符开始到第j个字符结束的位置替换为str2
/// </summary>
/// <param name="str1">目的str</param>
/// <param name="str2">源str</param>
/// <param name="i">开始位置</param>
/// <param name="j">结束位置</param>
void replace(char* str1, char* str2, int i, int j) {
	str1 += i;
	for (int m = 1; m < j - i; m++)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
}

int main() {
	char str1[1000]{ "Hello World!" };
	char str2[6]{ "Apple" };
	int i = 6;
	int j = 10;
	printf_s("替换前的字符串为：%s\n", str1);
	replace(str1, str2, i, j);
	printf_s("替换后的字符串为：%s\n", str1);
}