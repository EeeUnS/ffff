// pro08.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 101
#pragma warning(disable:4996)
void p01() {
	srand((unsigned int)time(NULL));
	int N,x,y,dir;
	int maze[MAX][MAX] = { 0 };
	scanf_s("%d", &N);
	int count = 0;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				maze[j][k] = 0;
		x = y = N / 2;
		while (x != 0 && y != 0 && x != N - 1 && y != N - 1) {
			maze[x][y] = 1;
			dir = rand() % 4;
			if (dir == 0 && maze[x][y + 1] == 0)
				y++;
			else if (dir == 1 && maze[x + 1][y] == 0)
				x++;
			else if (dir == 2 && maze[x][y - 1] == 0)
				y--;
			else if (dir == 3 && maze[x - 1][y] == 0)
				x--;
			else if (maze[x][y + 1] == 1 && maze[x + 1][y] == 1 && maze[x][y - 1] == 1 && maze[x - 1][y] == 1) {
				count++;
				break;
			}
		}
	}
	printf("%lf", 1-((double)count / 10000));
}
void p03() {
	int C[MAX][MAX];
	int n, k;
	scanf_s("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		C[i][i] = 1;
		C[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	printf("%d", C[n][k]);
}
void p04() {
	int array[MAX][MAX];
	int n;
	double av,sd,temp, sum = 0;
	FILE *fp = fopen("input4.txt", "r");
	fscanf_s(fp,"%d", &n);
	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fscanf_s(fp,"%d", &array[i][j]);
	}
	fclose(fp);
	//가로
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			printf("%d ", array[i][j]);
			sum += array[i][j];
		}
		av = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			temp = (array[i][j] - av);
			sum += temp * temp;
		}
		sd = sqrt(sum / n);
		printf("%lf %lf\n", av, sd);
	}
	//세로
	double result[MAX];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) 
			sum += array[j][i];
		av = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			temp = (array[j][i] - av);
			sum += temp * temp;
		}
		sd = sqrt(sum / n);
		result[i] = sd;
		printf("%lf ", av);
	}printf("\n");
	for (int i = 0; i < n; i++) 
		printf("%lf ", result[i]);
}
void p06() {
	int array[MAX][MAX];
	int n;
	FILE *fp = fopen("input6.txt", "r");
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			fscanf_s(fp, "%d", &array[i][j]);
	}
	fclose(fp);
	//출력
	int dir = 1,i=0,j=-1;
	while (n > 0) {
		for (int k = 0; k < n; k++) {
			j += dir;
			printf("%d ", array[i][j]);
		}
		n--;
		for (int k = 0; k < n; k++) {
			i += dir;
			printf("%d ", array[i][j]);
		}
		dir *= -1;
	}
}
void p07() {
	int Bars[MAX];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &Bars[i]);
	int i = 0, j = n - 1, max, Lmax = 0, Rmax = 0,water=0;
	while (i!=j)
	{
		if (Lmax < Bars[i])
			Lmax = Bars[i];
		if (Rmax < Bars[j])
			Rmax = Bars[j];
		Lmax > Rmax ? max = Rmax : max = Lmax;
		Bars[j] > Bars[i] ? water += max - Bars[i++] : water += max - Bars[j--];
	}
	printf("%d",water);
}
int main()
{
	while(true)
		p07();
    return 0;
}

