#include <stdio.h>


int getSum(int x, int n) {
	if (n == 0)return 1;
	else if (n == 1)return x;
	else {
		return(2 * (n-1) + 1) * x * getSum(x, n - 1) - (n - 1) * getSum(x, n - 2);
	}
}

int main() {
	int n = 10;
	int x = 15;

	printf_s("请输入n和x，以空格分割：");
	scanf_s("%d", &n);
	scanf_s("%d", &x);

	printf_s("结果为：%d", getSum(x, n));
}