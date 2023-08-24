#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, cols;
	printf_s("请输入矩阵的行数和列数：");
	scanf_s("%d %d", &rows, &cols);

	// 动态分配内存保存矩阵
	int** matrix = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
	}

	printf_s("请输入矩阵的元素：\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}
	// 动态分配内存保存鞍点的坐标
	int** saddlePoints = (int**)malloc(rows * cols * sizeof(int*));
	for (int i = 0; i < rows * cols; i++) {
		saddlePoints[i] = (int*)malloc(2 * sizeof(int));
	}
	int count = 0;  // 鞍点的个数

	// 寻找鞍点
	for (int i = 0; i < rows; i++) {
		int maxRowValue = matrix[i][0];  // 当前行的最大值，默认为第一个元素
		int maxColIndex = 0;  // 当前行最大值所在的列索引，默认为0

		// 找到当前行的最大值和其所在的列索引
		for (int j = 1; j < cols; j++) {
			if (matrix[i][j] > maxRowValue) {
				maxRowValue = matrix[i][j];
				maxColIndex = j;
			}
		}

		int isSaddlePoint = 1;  // 假设当前元素为鞍点
		// 判断当前行最大值是否同时是所在列的最小值
		for (int k = 0; k < rows; k++) {
			if (matrix[k][maxColIndex] < maxRowValue) {
				isSaddlePoint = 0;  // 如果存在比当前行最大值小的元素，则当前元素不是鞍点
				break;
			}
		}

		// 如果当前元素是鞍点，则保存其坐标
		if (isSaddlePoint) {
			saddlePoints[count][0] = i;
			saddlePoints[count][1] = maxColIndex;
			count++;
		}
	}

	// 输出鞍点的坐标
	printf("鞍点的坐标为：\n");
	if (count == 0) {
		printf_s("这个数组没有鞍点");
	}
	for (int i = 0; i < count; i++) {
		printf_s("(%d, %d)\n", saddlePoints[i][0], saddlePoints[i][1]);
	}

	// 释放动态数组内存
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);

	for (int i = 0; i < rows * cols; i++) {
		free(saddlePoints[i]);
	}
	free(saddlePoints);

	return 0;

}