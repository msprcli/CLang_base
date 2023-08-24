#include <stdio.h>

int main() {
	char sentence[100]{};
	gets_s(sentence);
	int tag = 0;
	while (sentence[tag] != '\0') {
		if (sentence[tag] >= 'a' && sentence[tag] <= 'z') {
			int flag = sentence[tag];
			int newTag = 97 + (25 - (flag - 97));
			sentence[tag] = newTag;
		}
		else if (sentence[tag] >= 'A' && sentence[tag] <= 'Z') {
			int flag = sentence[tag];
			int newTag = 65 + (25 - (flag - 65));
			sentence[tag] = newTag;
		}
		tag++;
	}
	printf_s("%s", sentence);
}