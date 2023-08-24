#include <stdio.h>
#include <corecrt_malloc.h>

/// <summary>
/// 将字符串中从m开始的全部字符复制成另一个字符串
/// </summary>
/// <param name="ptr1">源字符串</param>
/// <param name="ptr2">目的字符串</param>
/// <param name="m">偏移量</param>
void copyStr(char* ptr1, char* ptr2, int m) {
	ptr1 += m - 1;
	while (*ptr1 != '\0') {
		*ptr2 = *ptr1;
		ptr1++;
		ptr2++;
	}
	*ptr2 = '\0';
}

/// <summary>
/// 将第二个字符串中的内容替换到第一个字符串中，替换位置从m开始
/// </summary>
/// <param name="ptr1">目的字符串</param>
/// <param name="ptr2">源字符串</param>
/// <param name="m">从m位开始</param>
void replaceStr(char* ptr1, char* ptr2, int m) {
	ptr1 += m - 1;
	while (*ptr2 != '\0') {
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
}

int main() {
	char str1[1000]{ "Hello World!" };
	char str2[1000]{};
	char str3[1000]{ "aaaaaaaaaa?" };
	char* ptr1 = str1;
	char* ptr2 = str2;
	char* ptr3 = str3;
	int m = 3;
	copyStr(ptr1, ptr2, m);
	printf_s("源串为：%s\n从%d个字符开始复制\n复制后的字符串为：%s\n", str1, m, str2);
	replaceStr(ptr1, ptr3, m);
	printf_s("要替换的内容为：%s\n从%d个字符开始替换\n替换后的字符串为：%s\n", str3, m, str1);

}