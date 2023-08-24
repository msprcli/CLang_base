#include <stdio.h>

int main() {
	int numberList[100] = { 1,-6,2,32,4,0,0,-1,-2,-3,-5,'\0',' ','\0' };
	int numNumber = 1;
	printf_s("原始数组为：");
	while (!(numberList[numNumber - 1] == '\0' && numberList[numNumber] == ' ' && numberList[numNumber + 1] == '\0')) {
		printf_s(" %d", numberList[numNumber - 1]);
		numNumber++;
	}
	numNumber--;
	printf_s("\n数组中数字的数量为：%d\n", numNumber);
	int* pLeft = numberList, * pRight = &numberList[numNumber - 1];
	while (pLeft < pRight) {
		// 从右边开始找小于0的元素，找到后退出循环
		while (*pRight > 0 && *pLeft < *pRight) {
			pRight--;
		}
		// 从左边开始找大于0的元素，找到后退出循环
		while (*pLeft < 0 && *pLeft < *pRight) {
			pLeft++;
		}
		// 交换
		if (*pLeft > *pRight) {
			int temp = *pLeft;
			*pLeft = *pRight;
			*pRight = temp;
		}
		// 放到外面，避免连续两个0形成死循环
		pLeft++;
		pRight--;
	}
	int i = 1;
	printf_s("交换后的数组为：");
	while (i<numNumber) {
		printf_s("%d ", numberList[i-1]);
		i++;
	}
}