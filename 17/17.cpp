#include <stdio.h> // 基础头文件
#include <stdlib.h> // 随机数
#include <time.h> // 获取以秒为单位的时间（自1970-01-01 00:00:00起的秒数）

constexpr auto LIST_LENGTH = 32;;
int main()
{
	int arr1[100]{}, arr2[100]{};
	// 随机数，生成随机字符
	int achar, bchar;
	// 先后赋值避免规律性，否则会出现大和小一半一半的情况
	// 先使用时间重新播种
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < LIST_LENGTH; i++)
	{
		achar = rand() % 128;
		arr1[i] = achar;
	}
	// 再利用上次随机播种生成的随机的一个随机数重新播种
	// 不重新播种的话会出现18：0：14的情况
	srand((unsigned)rand());
	for (size_t i = 0; i < LIST_LENGTH; i++)
	{
		bchar = rand() % 128;
		arr2[i] = bchar;
	}
	// 显示两个列表
	printf_s("listA is :");
	for (size_t i = 0; i < LIST_LENGTH; i++)
	{
		printf_s(" %d", arr1[i]);
	}
	printf_s("\nlistB is :");
	for (size_t i = 0; i < LIST_LENGTH; i++)
	{
		printf_s(" %d", arr2[i]);
	}
	// 开始比较并存入统计结果
	int bigger = 0, equal = 0, smaller = 0;
	for (size_t i = 0; i < LIST_LENGTH; i++)
	{
		if (arr1[i] > arr2[i]) {
			bigger++;
		}
		else if (arr1[i] == arr2[i]) {
			equal++;
		}
		else {
			smaller++;
		}
	}
	// 显示比较结果
	int count = bigger - smaller;
	printf_s("\n\nbiggr: %d \nequal: %d \nsmaller: %d \ncount: %d\n\n", bigger, equal, smaller, count);
	if (count > 0) {
		printf_s("listA is bigger than listB;");
	}
	else if (count == 0) {
		printf_s("listA equals with listB;");
	}
	else {
		printf_s("listA is smaller than listB;");
	}
}
