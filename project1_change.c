#include <stdio.h>

void main(void) {
	int inputDollar = 0;				// �Է� �޷�
	int stdDollar[] = { 100, 50, 20, 10, 5, 1 };	// ���� �޷�
	int stdDollarSize = sizeof(stdDollar) / sizeof(int);	// ���� �޷� ����
	int stdDollarNumber[20];			// ���� �޷����� ����
	for (int i = 0; i < 20; i++) {
		stdDollarNumber[i] = 0;
	}
	int remainDollar = 0;
	char message[] = "Dollar";

	printf("���� �޷� (100�޷�, 50�޷�, 20�޷�, 10�޷�, 5�޷�, 1�޷�) \n");
	printf("������ �ż��� �ּ�ȭ �� �޷��� �Է��� �ּ���. ");

	scanf_s("%d", &inputDollar);
	remainDollar = inputDollar;
	for (int i = 0; i < stdDollarSize; i++) {
		if (remainDollar >= stdDollar[i]) {
			stdDollarNumber[i] = remainDollar / stdDollar[i];
			remainDollar -= stdDollarNumber[i] * stdDollar[i];
		}
	}
}