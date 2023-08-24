#include <stdio.h>
#include <corecrt_malloc.h>
#include <stdlib.h>
#include <time.h>


int main() {
	// 数组长度
	int n = 10;
	// 偏移量
	int m = 3;
	// 一维动态数组
	int* zanCun = (int*)malloc(static_cast<size_t>((unsigned)sizeof(int*)) * n);
	int* shuZu = (int*)malloc(static_cast<size_t>((unsigned)sizeof(int*)) * n);
	printf_s("偏移前的数组：");
	for (int i = 0; i < n; i++) {
		// 通过随机数生成
		// 根据时间重新播种，单位是从1970.1.1 00:00:00到今天的秒数
		// srand((unsigned)time(NULL))
		zanCun[i] = rand() % 150;
		printf_s(" %d", zanCun[i]);
	}
	for (int i = 0; i < n; i++)
	{
		shuZu[(i + m) % n] = zanCun[i];
	}
	printf_s("\n偏移后的数组：");
	for (int i = 0; i < n; i++) {
		printf_s(" %d", shuZu[i]);
	}
}