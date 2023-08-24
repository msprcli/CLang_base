#include <stdio.h>


int main()
{
	int a = 0, b = 0, yueShu = 0, zuiDaBeiShu = 0, beiShu = 0;
	scanf_s("%d %d", &a, &b);
	zuiDaBeiShu = a * b;
	// 保证a最大
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	// 辗转相除，yueShu就是a和b的最大公约数
	yueShu = b;
	while (a % b) {
		yueShu = a % b;
		a = b;
		b = yueShu;
	}
	
	// 两者乘积/最大公约数就是最小公倍数
	beiShu = zuiDaBeiShu / yueShu;
	printf("%d", beiShu);

}
