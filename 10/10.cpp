#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

char* readFile(char filename[]) {
    FILE* file = NULL;
    errno_t err;
    char content[MAX_SIZE];
    size_t bytesRead = 0;

    err = fopen_s(&file, filename, "rt+");
    if (err != 0) {
        printf_s("文件打开失败\n");
        return NULL;
    }

    bytesRead = fread_s(content, sizeof(content), sizeof(char), MAX_SIZE, file);
    if (bytesRead == 0) {
        printf_s("文件读取失败\n");
        fclose(file);
        return NULL;
    }
    // 将未被读取的部分置为字符串结束标志
    content[bytesRead] = '\0';

    fclose(file);

    printf_s("文件内容为:\n%s\n", content);
    return content;
}

void analyseFile(char* content) {
    int lowerChar = 0;
    int upperChar = 0;
    int nubmerChar = 0;
    int tabChar = 0;
    int otherChar = 0;
    int flag = 0;
    while (content[flag] != '\0') {
        if (content[flag] >= 'a' && content[flag] <= 'z') {
            lowerChar++;
        }
        else if (content[flag] >= 'A' && content[flag] <= 'Z') {
            upperChar++;
        }
        else if (content[flag] >= '0' && content[flag] <= '9') {
            nubmerChar++;
        }
        else if (content[flag] == '\t') {
            tabChar++;
        }
        else if (content[flag] != '\n') {
            // 排除换行符
            otherChar++;
        }
        flag++;
    }
    printf_s("lowerChar = %d \n", lowerChar);
    printf_s("upperChar = %d \n", upperChar);
    printf_s("nubmerChar = %d \n", nubmerChar);
    printf_s("tabChar = %d \n", tabChar);
    printf_s("otherChar = %d \n", otherChar);
}

int main() {
    // 定义文件名
    char fileName[]{ "./a.txt" };
    // 读取文件
    char* content = readFile(fileName);
    // 开始处理
    analyseFile(content);
    return 0;
}