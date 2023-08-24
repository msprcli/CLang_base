#include<stdio.h>

void getSchedule(char teamA[], char teamB[]) {
	//for (int i = 0; i < (int)sizeof(teamA); i++)
	for (int i = 0; i < 3; i++)
	{
		//for (int j = 0; j < (int)sizeof(teamB); j++)
		for (int j = 0; j < 3; j++)
		{
			if (teamA[i] == 'a' && teamB[j] == 'd'||
				teamA[i] == 'c' && teamB[j] == 'd'||
				teamA[i] == 'c' && teamB[j] == 'f') {
				continue;
			}
			else {
				printf_s("i: %d ; j: %d  ", i, j);
				printf_s("%c VS %c\n", teamA[i], teamB[j]);
			}
		}
	}
}

int main() {
	char teamA[] = { 'a','b','c' };
	char teamB[] = { 'c','d','e' };
	printf_s("sizeof(teamA): %d\n", (int)sizeof(teamA));
	printf_s("sizeof(teamB): %d\n", (int)sizeof(teamB));
	getSchedule(teamA, teamB);
}