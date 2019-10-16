#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 20

// array1 �� array2 �� �ִ´�
void copyArray(int* array1, int* array2, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		array2[i] = array1[i];
	}
}

void initArray(int* array, int initNum, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = initNum;
	}
}
void initArray2(int* array1, int* array2, int initNum, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		array1[i] = initNum;
		array2[i] = initNum;
	}
}

// limitValue == -1 �� ��� �� ���� ������ �ʰڴٴ� �ǹ��̴�
// �� �Լ��� ���ϰ��� -1 �� ���� ��� ���� �ѵ����� �Ѿ��� �����̴�
int getChangeNum(int* stdNumNumber, int* stdNum, int stdNumSize, int *startIndex, int inputNum, int limitValue) {
	initArray(stdNumNumber, 0, stdNumSize);

	int changeNum = 0; // �� ī��Ʈ�� ȭ�� ���� �ִ� ����
	bool start = false;
	for (int i = *startIndex; i < stdNumSize; i++) {
		// ī��Ʈ�� �ݾ��� ���̻� ���� �ʾ��� ���
		if (inputNum <= 0) {
			break;
		}
		// ī��Ʈ�� �ݾ��� ������ ��
		else if (inputNum >= stdNum[i]) {
			if (start == false) {
				start = true;
				*startIndex = i + 1;
			}

			stdNumNumber[i] = inputNum / stdNum[i];
			inputNum -= stdNumNumber[i] * stdNum[i];
			changeNum += stdNumNumber[i];
			// -1 �� ���� ������ �ѵ����� ���ٴ� �ǹ��̴�
			if (limitValue == -1) {

			}
			// ������ �ѵ������� �� ���� ���������� ������ ���
			else if (limitValue <= changeNum) {
				return -1;
			}
		}
	}
	return changeNum;
}

void showChangNumArray(int* array, int stdNumSize, int* stdNum, int leastChangeNum) {
	char message[] = "Won";
	printf("\n");
	for (int i = 0; i < stdNumSize; i++) {
		printf("%s[%.3d]: %d \n", message, stdNum[i], array[i]);
	}
	printf("least Change Count: %d", leastChangeNum);

}

int getLeastChangeNum(int inputNum, int* stdNum, int stdNumSize, bool showArray) {
	//**
	//int inputNum = 0;				// �Է� �޷�
	//**
	//int stdNum[] = { 250, 120, 100, 50, 10 };	// ���� �޷�
	//**
	//int stdNumSize = sizeof(stdNum) / sizeof(int);	// ���� �޷� ����

	int stdNumNumber[ARRAY_SIZE];			// '���� �޷����� ����'
	int leastChaStdNumNumber[ARRAY_SIZE];	// �ּ��� '���� �޷����� ����'
	int changeNumNumber = 0;		// �Ž����� ����
	initArray2(stdNumNumber, leastChaStdNumNumber, 0, stdNumSize);

	int remainNum = 0;



	//**
	//printf("���� �޷� (100�޷�, 50�޷�, 20�޷�, 10�޷�, 5�޷�, 1�޷�) \n");
	//printf("������ �ż��� �ּ�ȭ �� �޷��� �Է��� �ּ���. ");

	//**
	//scanf_s("%d", &inputNum);


	int startIndex = 0;

	int curChangeNum = 0; // ����� ������ ���� �� ����
	int limitValue = -1;
	bool start = false;
	while (1) {
		// ���� �ε����� �迭�� ��� ���
		if (startIndex > stdNumSize - 1) {
			break;
		}
		curChangeNum = getChangeNum(stdNumNumber, stdNum, stdNumSize, &startIndex, inputNum, limitValue);
		if (start == false) {
			limitValue = curChangeNum;
			copyArray(stdNumNumber, leastChaStdNumNumber, stdNumSize);
			start = true;
		}
		else {
			if (curChangeNum == -1) {

			}
			else if (limitValue > curChangeNum) {
				limitValue = curChangeNum;
				copyArray(stdNumNumber, leastChaStdNumNumber, stdNumSize);
			}
		}
	}

	//**
	if (showArray == true)
		showChangNumArray(leastChaStdNumNumber, stdNumSize, stdNum, limitValue);

	return limitValue;
}

