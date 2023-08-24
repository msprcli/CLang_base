#include <stdio.h>

// 函数调用次数
int tag = 1;

int useage(int a, int b) {
	switch (tag)
	{
	case 1:
		tag++;
		// 第一次调用，返回较大的
		// 三目运算符  判断条件？为true返回：为false返回
		return a > b ? a : b;
		break;
	case 2:
		tag++;
		// 第二次调用，返回较小的
		if (a > b) {
			return b;
		}
		return a;
		break;
	case 3:
		tag++;
		// 第三次调用，求和
		return a + b;
		break;
	default:
		tag = 1;
		printf_s("超出了三次调用，将进行回滚，本次操作无效。");
		break;
	}
}

int main() {
	int a = 1, b = 2;
	for (int i = 1; i <= 3; i++)
	{
		printf_s("第%d次调用，参数为 a:%d b:%d 返回结果为：%d\n", i, a, b, useage(a, b));
	}
}