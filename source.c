#include <stdio.h>
#include "greedyAlg.h"

int main(void)
{
	int money = 0, result = 0;
	FILE* fp = NULL;
	fp = fopen("sample_input.txt", "r");
	if (fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d", &money);

		// 알고리즘
		//
		int stdNum[] = { 250, 120, 100, 50, 10 };	// 기준 금액
		int stdNumSize = sizeof(stdNum) / sizeof(int);

		result = getLeastChangeNum(money, stdNum, stdNumSize, false);
		//

		printf("%d\n", result);
	}
	return 0;
}