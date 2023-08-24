#include <stdio.h>
#include <string.h>

constexpr auto MAX_LENGTH = 50; // 假设国家名的最大长度为50个字符;

int main() {
    char countries[5][MAX_LENGTH]{
        "China",
        "France",
        "Italy",
        "Cuba",
        "America"
    }; // 存储输入的国家名
    char temp[MAX_LENGTH]; // 用于临时存储字符串的数组

    //// 输入五个国家名
    //printf("请输入五个英文国家名：\n");
    //for (int i = 0; i < 5; i++) {
    //    printf("国家%d：", i + 1);
    //    scanf("%s", countries[i]);
    //}

    // 使用冒泡排序按字母顺序排序国家名
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            // 比较两个国家名，直接使用strcmp函数，如果前者比后者靠后则交换
            if (strcmp(countries[j], countries[j + 1]) > 0) {
                strcpy_s(temp, countries[j]);
                strcpy_s(countries[j], countries[j + 1]);
                strcpy_s(countries[j + 1], temp);
            }
        }
    }

    // 输出排序后的国家名
    printf("按字母顺序排序后的国家名：\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", countries[i]);
    }

    return 0;
}