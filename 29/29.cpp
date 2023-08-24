//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
////这里创建一个结构体用来表示链表的结点类型
//struct list
//{
//    int name;
//    struct list* next;
//};
//// 循环链表解决
//int main()
//{
//    struct list* houzi, * head, * now;
//    int m, n, a;
//    // n以下的索引到n之后重置为1
//    a = 1;
//    // 总数
//    m = 20;
//    // 报到3退出
//    n = 3;
//    houzi = (struct list*)malloc(sizeof(struct list));//动态申请一个空间，用来存放一个结点，并用临时指针houzi指向这个结点
//    now = (struct list*)malloc(sizeof(struct list));///同上
//    head = houzi;//指针head也指向houzi结点。即存着第一个猴子的指针
//    houzi->name = 1;//第一个猴子的名字是1
//    houzi->next = now;//设置当前houzi结点的后继指针指向now结点
//    houzi = houzi->next;//由于上一行的操作，新的houzi指针指向now结点。这是一个新的猴子
//    for (int i = 2; i <= m - 1; i++)//这个循环的内容跟上面的差不多。创建出多个猴子
//    {
//        houzi->name = i;
//        now = (struct list*)malloc(sizeof(struct list));
//        houzi->next = now;
//        houzi = houzi->next;
//    }
//    houzi->name = m;//这是最后一个猴子。要在循环之外创建
//    houzi->next = head;//最后一个猴子的后继结点是第一个猴子
//    houzi = head;//现在的猴子是第一个猴子了
//    while (m > 1)//现在开始选大王。m=1时，表明只剩下一个猴子即猴大王，退出循环
//    {
//        while (a != n - 1 && houzi->next != NULL)
//        {
//            houzi = houzi->next;
//            ++a;
//        }
//        a = 1;
//        houzi->next = houzi->next->next;
//        houzi = houzi->next;
//        m = m - 1;
//    }
//    printf("%d", houzi->name);
//}


// 法二：约瑟夫环
 
#include<stdio.h>

/// <summary>
/// 递归到剩下的人
/// </summary>
/// <param name="n">n个人</param>
/// <param name="m">第m个人退出</param>
/// <returns>最后剩下的人的编号</returns>
int find(int n, int m) {
	// n个人围成一圈最后剩下的人可以按照这个公式推到：f(n) = (f(n-1) + m) % n 
	// 其中f(n)表示n个人时最后剩下的人的编号，m表示要报数的数目。
	if (n == 1) {
		// 只剩一个人，也就是自己
		return 0;
	}
	else {
		return (find(n - 1, m) + m) % n;
	}

}

int main() {
	// 总人数
	int n = 20;
	// 报到m的人退出
	int m = 3;

	printf_s("最后剩余的人是第%d个人", find(n, m));
}

// 有bug的代码，但是不清楚在哪

//#include<stdio.h>
//
//int main() {
//	int listA[100]{};
//	int listB[100]{};
//
//	// 总人数
//	int n = 3;
//	// 报到tag的人退出
//	int tag = 3;
//	int tempTag = 1;
//	// 剩余人数
//	int personLeft = n;
//	for (int i = 0; i < n; i++) {
//		listA[i] = i + 1;
//		listB[i] = 1;
//	}
//	int ptr = 0;
//	// 循环，直到只剩一个人
//	while (personLeft != 1) {
//		// 当前人未被剔除
//		if (listB[ptr]) {
//			// 当前人不该被剔除
//			if (tempTag != 3) {
//				tempTag++;
//			}
//			// 当前人该被剔除
//			else {
//				personLeft--;
//				listB[ptr] = 0;
//				tempTag = 1;
//			}
//			ptr++;
//		}
//		// 已被剔除，指针+1
//		else {
//			ptr++;
//		}
//		// 循环到最后，重置指针
//		if (ptr == n) {
//			ptr = 0;
//		}
//	}
//	ptr++;
//	printf_s("最后剩余的人是：%d", ptr);
//}