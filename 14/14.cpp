#include <stdio.h>

int main() {
	// 多一位用于存放'/0'
	char str1[201]{};
	char str2[201]{};
	char* p = str1;

	printf_s("请输入两个字符串，单个长度不要超过100:\n");
	printf_s("第一个串为:\n");
	gets_s(str1);
	printf_s("第二个串为:\n");
	gets_s(str2);
	int num1 = 0, num2 = 0;
	while (*p != '\0') {
		num1 += *p;
		p++;
	}
	p = str2;
	while (*p != '\0') {
		num2 += *p;
		p++;

	}
	printf_s("结果为：%d", num1 - num2);
}