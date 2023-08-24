#include <stdio.h>

int main() {
	// 多一位用于存放'/0'
	char str1[101]{};
	char str2[101]{};
	char str3[201]{};
	printf_s("请输入两个字符串，单个长度不要超过100:\n");
	printf_s("第一个串为:\n");
	gets_s(str1);
	printf_s("第二个串为:\n");
	gets_s(str2);
	int n = 0;
	while (str1[n] != '\0') {
		str3[n] = str1[n];
		n++;
	}
	int m = 0;
	while (str2[m] != '\0') {
		str3[n] = str2[m];
		m++;
		n++;
	}
	str3[n] = '\0';
	printf_s("合并后的字符串为：%s", str3);
}


// 使用指针可以优化效率

/*
 #include <stdio.h>

int main() {
    char str1[101]{};
    char str2[101]{};
    char str3[201]{};
    char *p = str3;
    
    printf_s("请输入两个字符串，单个长度不要超过100:\n");
    printf_s("第一个串为:\n");
    gets_s(str1);
    printf_s("第二个串为:\n");
    gets_s(str2);
    
    while (*str1 != '\0') {
        *p = *str1;
        p++;
        str1++;
    }
    
    while (*str2 != '\0') {
        *p = *str2;
        p++;
        str2++;
    }
    
    *p = '\0';
    
    printf_s("合并后的字符串为：%s", str3);
    
    return 0;
}
*/