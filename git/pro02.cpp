
#include "stdafx.h"

void p04();
void p06();
void p08();
void p10();
void p11();
int way(int x1, int y1, int x2, int y2, int x3, int y3);
int direction(int x1, int y1, int x2, int y2);
void p12();
int main()
{
	while(1)
		p12();
	return 0;
}
void p04() {
	int n, min;
	scanf_s("%d", &min);

	for (int i = 1; i < 10; i++) {
		scanf_s("%d", &n);
		if (n < min&&n >= 0)
			min = n;
	}
	printf("%d", min);
}
void p06() {
	int y1, m1, d1, y2, m2, d2,out;
	scanf_s("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
	if (y1 == y2) {
		if (m1 == m2) {
			if (d1 == d2)
				out = 0;
			else if (d1 < d2)
				out = -1;
			else
				out = 1;
		}
		else if (m1 < m2)
			out = -1;
		else
			out = 1;
	}
	else if (y1 < y2)
		out = -1;
	else
		out = 1;
	printf("%d", out);
}
void p08() {
	int a, b, c, d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	if (a > b || c > d)
		printf("Input error");
	else if (d >= a && b >= c)
		printf("YES");
	else
		printf("NO");
}
void p10() {
	int n, x1, x2, y1, y2, polyline = 0;
	scanf_s("%d %d %d", &n, &x1, &y1);
	for (int i = 1; i < n; i++) {
		scanf_s("%d %d", &x2, &y2);
		if (x1 == x2) 
			if(y2 > y1)
				polyline += y2 - y1;
			else 
				polyline += y1 - y2;
		else if (y1 == y2) 
			if(x2 > x1)
				polyline += x2 - x1;
			else
				polyline += x1 - x2;
		else {
			printf("Input error");
			return;
		}
		x1 = x2;
		y1 = y2;
	}
	printf("%d", polyline);
}
void p11() {
	int x1, y1, x2, y2, x3, y3,out;
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	out = way(x1, y1, x2, y2, x3, y3);
	switch (out)
	{
		case -1:
		case 3:printf("Left"); break;
		case 0:printf("Stright"); break;
		case 1:
		case -3:printf("Right"); break;
		case 2:
		case -2:printf("U-turn"); break;
		default:printf("Input error"); break;
	}
}
int way(int x1, int y1, int x2, int y2, int x3, int y3) {
	if ((x1 == x2 || y1 == y2) && (x2 == x3 || y2 == y3)) 
		return direction(x1, y1, x2, y2) - direction(x2, y2, x3, y3);
	else
		return 4;
}
int direction(int x1, int y1, int x2, int y2) {
	x1 -= x2;
	y1 -= y2;
	if (x1 == 0) {
		if (y1 > 0)
			return 2;//왼
		else
			return 0;//오
	}
	else {
		if (x1 > 0)
			return 1;//위
		else
			return 3;//아래
	}
}
void p12() {
	int x1, y1, x2, y2, x3, y3, n, L, S, R, U;
	L = S = R = U = 0;
	scanf_s("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
	for (int i = 2; i < n; i++) {
		scanf_s("%d %d", &x3, &y3);
		switch (way(x1, y1, x2, y2, x3, y3))
		{
			case -1:
			case 3:L++; break;
			case 0:S++; break;
			case 1:
			case -3:R++; break;
			case 2:
			case -2:U++; break;
			default:printf("Input error"); return;
		}
		x1 = x2;
		y1 = y2;
		x2 = x3;
		y2 = y3;
	}
	printf("%d %d %d %d", L, S, R, U);
}