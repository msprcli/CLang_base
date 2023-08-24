#include <stdio.h>

int getSum(int year,int month,int day) {
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0;
	count += day;
	if (year % 4 == 0) {
		days[1] = 29;
	}
	for (int i = 1; i < month; i++)
	{
		count += days[i - 1];
	}
	return count;
}

int main() {
	static int count = 0;
	static int year = 0, month = 0, day = 0;
	printf_s("请输入年 月 日，以空格分割\n");
	scanf_s("%d %d %d", &year, &month, &day);
	count=getSum(year, month, day);
	printf_s("是第%d天", count);
}