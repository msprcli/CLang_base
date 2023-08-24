#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

static string judge(int num) {
	for (int i = 2; i < sqrt(num)+1; i++)
	{
		if (num % i == 0) {
			return("不是素数");
		}
	}
	return("是素数");
}

int main() {
	int num = 0;
	scanf_s("%d", &num);
	while (num>=0)
	{
		printf_s("%s\n", judge(num).c_str());
	}
}