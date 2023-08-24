#include <stdio.h>
/// <summary>
/// 获取对应项的斐波那契数列项作为分子和分母
/// </summary>
/// <param name="n">第n项</param>
/// <returns>对应数值</returns>
double getId(int n) {
	if (n > 2) {
		return getId(n - 1) + getId(n - 2);
	}
	else if (n == 2) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

double getSum(double sum, int m, int n) {
	if (m < n) {
		sum += getId(m + 1) / getId(m + 2);
		m++;
		return getSum(sum, m, n);
	}
	else {
		return sum;
	}
}

double getSum(int n) {
	return getSum(0.00, 1, n);
}

int main() {

	printf_s("前20项的和：%.10f ", getSum(20));

}