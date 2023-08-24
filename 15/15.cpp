#include <stdio.h>

int main() {
    // 多一位用于存放'/0'
    char str1[201]{};
    char str2[201]{};
    char* p1 = str1, * p2 = str2;
    printf_s("请输入一个字符串，长度不要超过200:\n");
    printf_s("第一个串为:\n");
    gets_s(str1);
    while (*p1 != '\0') {
        *p2 = *p1;
        p1++;
        p2++;
    }
    printf_s("复制后的字符串为：%s", str2);
}
