#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 20

// array1 을 array2 에 넣는다
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

// limitValue == -1 인 경우 이 값을 정하지 않겠다는 의미이다
// 이 함수의 리턴값이 -1 인 경우는 계산 도중 한도값을 넘었기 때문이다
int getChangeNum(int* stdNumNumber, int* stdNum, int stdNumSize, int *startIndex, int inputNum, int limitValue) {
	initArray(stdNumNumber, 0, stdNumSize);

	int changeNum = 0; // 총 카운트된 화폐 갯수 넣는 변수
	bool start = false;
	for (int i = *startIndex; i < stdNumSize; i++) {
		// 카운트할 금액이 더이상 남지 않았을 경우
		if (inputNum <= 0) {
			break;
		}
		// 카운트할 금액이 남았을 때
		else if (inputNum >= stdNum[i]) {
			if (start == false) {
				start = true;
				*startIndex = i + 1;
			}

			stdNumNumber[i] = inputNum / stdNum[i];
			inputNum -= stdNumNumber[i] * stdNum[i];
			changeNum += stdNumNumber[i];
			// -1 인 경우는 정해진 한도값이 없다는 의미이다
			if (limitValue == -1) {

			}
			// 정해진 한도값보다 더 많은 동전갯수가 나오는 경우
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
	//int inputNum = 0;				// 입력 달러
	//**
	//int stdNum[] = { 250, 120, 100, 50, 10 };	// 기준 달러
	//**
	//int stdNumSize = sizeof(stdNum) / sizeof(int);	// 기준 달러 갯수

	int stdNumNumber[ARRAY_SIZE];			// '기준 달러들의 갯수'
	int leastChaStdNumNumber[ARRAY_SIZE];	// 최소의 '기준 달러들의 갯수'
	int changeNumNumber = 0;		// 거스름돈 갯수
	initArray2(stdNumNumber, leastChaStdNumNumber, 0, stdNumSize);

	int remainNum = 0;



	//**
	//printf("기준 달러 (100달러, 50달러, 20달러, 10달러, 5달러, 1달러) \n");
	//printf("지폐의 매수를 최소화 할 달러를 입력해 주세요. ");

	//**
	//scanf_s("%d", &inputNum);


	int startIndex = 0;

	int curChangeNum = 0; // 계산결과 구해진 동전 총 갯수
	int limitValue = -1;
	bool start = false;
	while (1) {
		// 시작 인덱스가 배열을 벋어날 경우
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

