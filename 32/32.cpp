#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// <summary>
/// 学生选修课分数
/// </summary>
typedef struct CoursesScore {
	/// <summary>
	/// 语文成绩
	/// </summary>
	int ChineseScore;
	/// <summary>
	/// 数学成绩
	/// </summary>
	int MathScore;
	/// <summary>
	/// 英语成绩
	/// </summary>
	int EnglishScore;
	/// <summary>
	/// 学生姓名
	/// </summary>
	char StudentName[10];
}CoursesScore, CoursesScoreRecords[8];

/// <summary>
/// 获取一个0-100的随机数
/// </summary>
/// <returns>int随机数</returns>
int getRandomNumber() {
	return rand() % 101;
}

int main() {
	/// 8名学生
	CoursesScore courseScoreList[8]{};

	// 初始化
	for (int i = 0; i < 8; i++)
	{
		courseScoreList[i].ChineseScore = getRandomNumber();
		courseScoreList[i].MathScore = getRandomNumber();
		courseScoreList[i].EnglishScore = getRandomNumber();
		// int转字符串并控制缓冲区大小
		char No[10]{ "No." };
		char StudentName[7]{};
		snprintf(StudentName, sizeof(StudentName), "%d", (i + 1));
		strcat_s(No, StudentName);
		No[9] = '\0';
		strcpy_s(courseScoreList[i].StudentName, No);
	}
	// 计算总分
	int countSocre[9]{};
	for (int i = 0; i < 8; i++)
	{
		countSocre[i] += courseScoreList[i].ChineseScore;
		countSocre[i] += courseScoreList[i].MathScore;
		countSocre[i] += courseScoreList[i].EnglishScore;
	}
	// 计算平均分
	double averageScore[9]{};
	for (int i = 0; i < 8; i++)
	{
		averageScore[i] = (double)countSocre[i] / 3;
	}

	// 冒泡排序
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7 - i; j++) {
			// 成绩高的靠前
			if (countSocre[j] < countSocre[j + 1]) {
				// 交换总分与对应的项
				int tempScore = countSocre[j];
				countSocre[j] = countSocre[j + 1];
				countSocre[j + 1] = tempScore;
				// 交换对应的学生
				CoursesScore tempCourseScore = courseScoreList[j];
				courseScoreList[j] = courseScoreList[j + 1];
				courseScoreList[j + 1] = tempCourseScore;
			}
		}
	}
	// 显示前三位
	printf_s("前三名为：\n");
	for (int i = 0; i < 8; i++)
	{
		printf_s("学生：%s 语文：%d 数学：%d 英语：%d 总分：%d\n",
			courseScoreList[i].StudentName,
			courseScoreList[i].ChineseScore,
			courseScoreList[i].MathScore,
			courseScoreList[i].EnglishScore,
			countSocre[i]);
		//printf_s("学生：%s", courseScoreList[i].StudentName);
		//printf_s(" 语文：%d", courseScoreList[i].ChineseScore);
		//printf_s(" 数学：%d", courseScoreList[i].MathScore);
		//printf_s(" 英语：%d", courseScoreList[i].EnglishScore);
		//printf_s(" 总分：%d\n", countSocre[i]);
	}
}