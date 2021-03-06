// pro04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
void p03() {
	int N,x,y=0;
	scanf_s("%d", &N);
	while (y <= N) {
		if (y % 2 == 0) {
			for (x = 0; x <= N; x++)
				printf("%d %d\n", x, y);
		}
		else {
			for (x = N; x >= 0; x--)
				printf("%d %d\n", x, y);
		}
		y++;
	}
}
void p04() {
	int K, x = 0, sum = 0;
	scanf_s("%d",&K);
	while (sum <= K) {
		while (x  <= sum) {
			printf("%d %d\n", x, sum-x);
			x++;
		}
		x = 0;
		sum++;
	}
}
void p07() {
	srand((unsigned int)time(NULL));
	int N, x = 0, y = 0, count = 0, dir;
	scanf_s("%d", &N);
	for (int i = 0; i < 1000; i++) {
		while (true) {
			if (x == N || x == -N || y == N || y == -N)
				break;
			dir = rand() % 4;
			if (dir == 0)
				x++;
			else if (dir == 1)
				x--;
			else if (dir == 2)
				y++;
			else
				y--;
			count++;
		}
		x = y = 0;
	}
	printf("%lf", count / 1000.0);
}
void p08() {
	srand((unsigned int)time(NULL));
	int dice,count=0;
	bool flag = false;
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 6; j++) {
			dice = rand() % 6;
			if (dice == 0) {
				count++;
				break;
			}
		}
	}
	printf("6번 던져서 적어도 한번 %lf\n", count / 1000000.0);
	count = 0;
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 12; j++) {
			dice = rand() % 6;
			if (dice == 0) {
				if (flag) {
					count++;
					flag = false;
					break;
				}
				flag = true;
			}
		}
	}
	printf("12번 던져서 적어도 한번 %lf\n", count / 1000000.0);

}
void p10() {
	int x1, x2, y1, y2, x3, x4, y3, y4,temp,cntx=0,cnty=0;
	scanf_s("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	if (x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (y1 > y2) {
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	if (x3 > x4) {
		temp = x3;
		x3 = x4;
		x4 = temp;
	}
	if (y3 > y4) {
		temp = y3;
		y3 = y4;
		y4 = temp;
	}
	printf("%d %d %d %d %d %d %d %d\n", x1, x2, y1, y2, x3, x4, y3, y4);
	while (x3 < x4) {
		if (x3 >= x1&&x3 < x2)
			cntx++;
		x3++;
	}
	while (y3 < y4) {
		if (y3 >= y1&&y3 < y2)
			cnty++;
		y3++;
	}
	printf("%d\n", cntx*cnty);
}
void p11() {
	int pre, prepre, able = 0;
	bool result = false;
	int N;
	scanf_s("%d", &N);
	scanf_s("%d %d", &prepre, &pre);
	if (prepre == 1 && pre == 0)
		result = true;
	for (int i = 0; i < N - 2; i++) {
		prepre = pre;
		scanf_s("%d", &pre);
		switch (prepre * 4 + pre * 2 + able) {
		case 0:able = 1; break;
		case 1:break;
		case 2:result = false; break;
		case 3:able = 0; break;
		case 4:result = false; break;
		case 5:able = 0; break;
		case 6:able = 1; break;
		case 7:break;
		}
	}
	if(result)
		printf("YES");
	else
		printf("NO");
}
void main() {
	while (true)
		p11();
}

