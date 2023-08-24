#include <stdio.h>
#include <string.h>

void swapStr(char* str1, char* str2) {
	char tempStr[100]{};
	strcpy_s(tempStr, sizeof(tempStr),str1);
	strcpy_s(str1, sizeof(str1),str2);
	strcpy_s(str2, sizeof(str2),tempStr);
}

void sortString(char* str1, char* str2, char* str3) {

	if (strcmp(str1, str2) > 0) {
		swapStr(str1, str2);
	}
	if (strcmp(str1, str3) > 0) {
		swapStr(str1, str3);
	}
	if (strcmp(str2, str3) > 0) {
		swapStr(str2, str3);
	}
}

int main() {
	char str1[100]{};
	char str2[100]{};
	char str3[100]{};

	gets_s(str1);
	gets_s(str2);
	gets_s(str3);

	sortString(str1, str2, str3);

	printf_s("Lower:%s \nMiddle: %s\nHiger: %s", str1, str2, str3);
}