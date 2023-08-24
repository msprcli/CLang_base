#include <stdio.h>
#include <corecrt_malloc.h>

int main() {
	int n = 10;
	printf_s("请输入要打印的行数，最小为3，非法输入默认打印10行:");
	scanf_s("%d", &n);
	if (n < 3) {
		n = 10;
	}
	// 定义二维指针。
	int shuZu[15][15]{};
	//// 申请一组一维指针空间。
	//shuZu = (int**)malloc(sizeof(int*) * n);
	//for (int i = 0; i < n; i++) {
	//	// 对于每个一维指针，申请一行数据的空间。
	//	shuZu[i] = (int*)malloc(sizeof(int) * (static_cast<unsigned long long>(i) + 1));
	//}
	shuZu[0][0] = 1;
	shuZu[1][0] = 1;
	shuZu[1][1] = 1;
	// 从第三行开始，求解杨辉三角
	for (int i = 2; i < n + 1; i++)
	{
		// 每行第一列一定为1
		shuZu[i][0] = 1;
		for (int j = 1; j < i - 1; j++)
		{
			shuZu[i][j] = shuZu[i - 1][j - 1] + shuZu[i - 1][j];
		}
		// 每行最后一列也一定为1
		shuZu[i][i - 1] = 1;
	}
	/*
	*        1
	*      1   1
	*    1   2   1
	*  1   3   3   1
	*1   4   6   4   1
	*/
	// 循环打印，用空格调整位置
	// i表示对应的行
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < 2 * (n - i); j++)
		{
			printf_s(" ");
		}
		// 行内某一列
		for (int j = 0; j < i; j++)
		{
			printf_s("   %d", shuZu[i][j]);
		}
		printf_s("\n");
	}
}