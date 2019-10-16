#include <stdio.h>

void main(void) {
	int inputDollar = 0;				// 입력 달러
	int stdDollar[] = { 100, 50, 20, 10, 5, 1 };	// 기준 달러
	int stdDollarSize = sizeof(stdDollar) / sizeof(int);	// 기준 달러 갯수
	int stdDollarNumber[20];			// 기준 달러들의 갯수
	for (int i = 0; i < 20; i++) {
		stdDollarNumber[i] = 0;
	}
	int remainDollar = 0;
	char message[] = "Dollar";

	printf("기준 달러 (100달러, 50달러, 20달러, 10달러, 5달러, 1달러) \n");
	printf("지폐의 매수를 최소화 할 달러를 입력해 주세요. ");

	scanf_s("%d", &inputDollar);
	remainDollar = inputDollar;
	for (int i = 0; i < stdDollarSize; i++) {
		if (remainDollar >= stdDollar[i]) {
			stdDollarNumber[i] = remainDollar / stdDollar[i];
			remainDollar -= stdDollarNumber[i] * stdDollar[i];
		}
	}
}