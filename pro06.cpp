
#include "stdafx.h"
#include <stdio.h>
#define MAX 100
#pragma warning(disable:4996)
void p01() {
	int data[MAX];
	int n = 0, tmp;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == -1)
			break;
		int i = n - 1;
		while (i >= 0 && data[i] > tmp) {
			data[i + 1] = data[i];
			i--;
		}
		data[i+1] = tmp;
		n++;
		if (data[i] == tmp) {
			printf("duplicate entry\n");
			while (++i < n - 1)
				data[i] = data[i + 1];
			n--;
		}		
		for(int j = 0 ; j < n ; j++)
		printf("%d  ", data[j]);
	}
}
void p03() {
	int data[MAX];
	FILE *fp = fopen("input3.txt", "r");
	int n = 0;
	while (fscanf_s(fp, "%d", &data[n]) != EOF)
		n++;
	int max,temp;
	for (int i = n -1; i > 0; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (data[j] > data[max])
				max = j;
		}
		temp = data[i];
		data[i] = data[max];
		data[max] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
}
void p05() {
	int start[MAX];
	int end[MAX];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf_s("%d %d", &start[i], &end[i]);
	int temp, max;
	for (int i = n - 1; i > 0; i--) {
		max = 0;
		for (int j = 1; j <= i; j++) {
			if (start[j] > start[max])
				max = j;
			else if (start[j] == start[max] && end[j] > end[max])
				max = j;
		}
		temp = start[max];
		start[max] = start[i];
		start[i] = temp;
		temp = end[max];
		end[max] = end[i];
		end[i] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", start[i], end[i]);
}
void p06() {
	int N;
	scanf_s("%d", &N);
	int flag = (1 << N) - 1;
	int A[60];
	int count = 0, tmp = 1;
	for (int i = 0; i < N; i++)
		scanf_s("%d", &A[i]);
	for (int i = 0; i < N; i++,tmp *= 2) {
		if ((flag & tmp) > 0) {
			flag -= tmp;
			if (A[i] == i)
				count++;
			else{
				int x = i, y;
				while (A[x] >= 0 && A[x] < N) {
					y = A[x];
					if (i == y) {
						count++;
						break;
					}
					int check = 1 << y;
					if ((flag & check) > 0) {
						flag -= check;
						x = y;
					}
					else
						break;
				}
			}
		}
	}
	printf("%d", count);
}
void p07() {
	int x, y;
	scanf_s("%d %d", &x, &y);
	int max, count = 1, mx = x,my= y;
	if (x > y) max = x; else  max = y;
	while (max < 10) {
		max /= 10;
		count *= 10;
	}
	while (mx > count)
		mx *= 10;
	while (my > count)
		my *= 10;
	if (mx < my)
		printf("%d %d", x, y);
	else
		printf("%d %d", y, x);
}

int main()
{
	while(true)
	p06();
	getchar(); getchar();
	return 0;
}

