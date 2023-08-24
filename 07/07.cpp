#include <stdio.h>
#include <string.h>

int getWords(char* sentence);
int judgeIsWord(char* word, int length);

int main() {
	char sentence[2000];
	// 获取输入
	fgets(sentence, sizeof(sentence), stdin);
	// 去掉换行符
	sentence[strcspn(sentence, "\n")] = '\0';
	if (strcmp(sentence, "0") == 0) {
		char demoStr[] = "Hello World. This is a demo sentence.";
		for (int i = 0; i < sizeof(demoStr); i++)
		{
			sentence[i] = demoStr[i];
		}
	}
	printf("%s\n", sentence);
	printf("words count: %d\n", getWords(sentence));
	return 0;
}

int getWords(char* sentence) {
	int wordCount = 0;
	while (*sentence != '\0') {
		char word[100] = { 0 };
		int wordLength = 0;
		// 开始读取字符
		while (*sentence != ' ' && *sentence != '\0') {
			word[wordLength] = *sentence;
			wordLength++;
			sentence++;
		}
		// 当前单词读取结束，判断是否为合法单词
		wordCount += judgeIsWord(word, wordLength);
		// 清除后续的空格
		while (*sentence == ' ') {
			sentence++;
		}
	}
	return wordCount;
}

int judgeIsWord(char* word, int length) {
	// 为定冠词a，不是想要的单词
	if ((*word == 'a' || *word == 'A') && length == 1) {
		return 0;
	}
	// 判断单词是否有非法输入
	int m = 0;
	while (m < length-1) {
		if (!((word[m] >= 'A' && word[m] <= 'Z') || (word[m] >= 'a' && word[m] <= 'z'))) {
			// 不是英文字符
			return 0;
		}
		m++;
	}
	// 判断最后一位是否是标点
	if (!((word[m] >= 'A' && word[m] <= 'Z') || (word[m] >= 'a' && word[m] <= 'z'))) {
		if (word[m] == ',' || word[m] == '.' || word[m] == ':' || word[m] == ';') {
			return 1;
		}
		// 不是英文字符
		return 0;
	}
	return 1;
}