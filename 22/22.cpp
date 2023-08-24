#include<stdio.h>

int main() {
	char str[1000] = "Hello World!";
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	printf_s("字符串：\"%s\"的长度为：%d", str, length);
}