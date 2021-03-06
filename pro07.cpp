// pro07.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#define MAX 100
void p02() {
	int array[MAX];
	int N, count = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf_s("%d", &array[i]);
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (array[i] > array[j] && array[i] > array[k] && array[j] > array[k])
					count++;
			}
		}
	}
	printf("%d ", count);
}
void p04() {
	int array[MAX];
	int N, count = 1,maxlength = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);
	for (int i = 1; i < N; i++) {
		if (array[i] >= array[i - 1])
			count++;
		else
			count = 1;
		if (count > maxlength)
			maxlength = count;
	}
	printf("%d ", maxlength);
}
void p07() {
	//입력
	int start[MAX];
	int end[MAX];
	int N = 0;
	FILE *data;
	fopen_s(&data, "input7.txt", "r");
	while (fscanf_s(data, "%d", &start[N]) != EOF) {
		fscanf_s(data, "%d", &end[N]);
		N++;
	}
	//정렬
	int max, temp;
	for (int i = N-1; i > 1; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (start[max] < start[j])
				max = j;
		}
		temp = start[max];
		start[max] = start[i];
		start[i] = temp;
		temp = end[max];
		end[max] = end[i];
		end[i] = temp;
	}
	//탐색
	int maxinterval = 0,sindex,eindex;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (end[i] - start[j]> maxinterval) {
				maxinterval = end[i] - start[j];
				sindex = i;
				eindex = j;
			}
		}
	}
	printf("[%d, %d], [%d, %d]", start[sindex], end[sindex], start[eindex], end[eindex]);
}
void p10() {
	int array[MAX];
	int result[MAX];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);

	for (int i = 0; i < N; i++) {
		if (array[i] == i)
			result[i] = i;
		else
			result[i] = -1;
	}
	int level, x;
	for (int i = 0; i < N; i++) {
		if (result[i] == -1) {
			for (x = i, level = 1; level <= N; level++) {
				x = array[x];
				if (result[x] != -1 || x < i) {
					result[i] = result[x];
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) 
		printf("%d ", result[i]);
}
void p11() {
	//입력
	int array[MAX];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &array[i]);
	//탐색
	int maxlength = 0, count = 0;
	for (int i = 0; i < N; i++) {
		if (array[i] == 0) {
			array[i] = 1;
			for (int j = 0; j < N; j++) {
				if (array[j] == 1)
					count++;
				else
					count = 0;
				if (count > maxlength)
					maxlength = count;
			}
			array[i] = 0;
		}
	}
	//길이가 0이면 0이 없다.
	if (maxlength == 0)
		maxlength = N;
	printf("%d", maxlength);
}
int main()
{
	while (true) 
		p10();  
	getchar(); getchar();
	return 0;
}

