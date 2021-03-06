// pro09.cpp.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#define MAX 100
int compareLexicographic(int x, int y);
int lenOfOverlap(int sa, int ta, int sb, int tb);
int calpoly(int c, int o, int x);
void improv06() {
	int n, x;
	int Coef[MAX] = { 0 };
	int Order[MAX];
	int temp,index;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf_s("%d %d", &Coef[i], &Order[i]);
	scanf_s("%d", &x);
	int sum = 0;
	for (int i = 0; i < MAX; i++)
		sum += calpoly(Coef[i], Order[i], x);
	printf("%d", sum);
}
int calpoly(int c, int o,int x) {
	if (c == 0)
		return 0;
	if (o == 0)
		return c;
	double temp = 1;
	for (int i = 0; i < o; i++)
		temp *= x;
	return c * temp;
}
void p06() {
	int n, x;
	int Coef[MAX];
	int Order[MAX];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &Coef[i], &Order[i]);
	}
	scanf_s("%d", &x);
	int xorder = 0,sum = 0,mx=1;
	for (int i = n - 1; i >= 0; i--) {
			while (xorder < Order[i]) {
				mx *= x;
				xorder++;
			}
			sum += Coef[i] * mx;			
	}
	printf("%d", sum);
}
void p05() {
	FILE *fp;
	int data[MAX];
	int n = 0,i;
	fopen_s(&fp,"input5.txt", "r");
	fscanf_s(fp, "%d", &data[n++]);
	while (fscanf_s(fp, "%d", &data[n]) != EOF)
		n++;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (compareLexicographic(data[j], data[j + 1]) < 0) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d\t", data[i]);
}
int compareLexicographic(int x, int y) {
	int max, count = 1, mx = x, my = y;
	if (x == y) {
		return 0;
	}
	x > y ? max = x : max = y;
	while (max > 10) {
		max /= 10;
		count *= 10;
	}
	while (mx < count)
		mx *= 10;
	while (my < count)
		my *= 10;
	if (mx == my) 
		return x > y ? -1 : 1;
	return mx > my ? -1 : 1;
}
int lenOfOverlap(int sa, int ta, int sb, int tb) {
	if (sa > ta) {
		int temp = sa;
		sa = ta;
		ta = temp;
	}
	if (sb > tb) {
		int temp = sb;
		sb = tb;
		tb = temp;
	}
	if (sa <= sb) {
		if (ta < tb) {
			if (ta > sb)
				return abs(sb - ta);
			else
				return 0;
		}
		else
			return abs(tb - sb);
	}
	else {
		if (ta > tb) {
			if (tb > sa)
				return abs(sa - tb);
			else
				return 0;
		}
		else
			return abs(ta - sa);
	}
}
void p03() {
	int data[8];
	for (int i = 0; i < 8; i++)
		scanf_s("%d", &data[i]);
	printf("%d", lenOfOverlap(data[0], data[2], data[4], data[6])*lenOfOverlap(data[1], data[3], data[5], data[7]));
}
double func(double x, double y, double z) {
	return x <= y ? (y <= z ? y : (x <= z ? z : x)) : (z <= y ? y : (x <= z ? x : z));
}
int main()
{	
	improv06();
	getchar(); getchar();
    return 0;
}

