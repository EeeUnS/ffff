
#include "stdafx.h"

void p01();
void p03();
int Euclid(int x, int y);
void p05();
void p07();
void p08();
void main()
{
	while (true)
		p08();
}
void p01() {
	int oddsum = 0, evensum = 0, count = 0, n;
	while (true) {
		scanf_s("%d", &n);
		if (n % 2 == 0)
			evensum += n;
		else
			oddsum += n;
		count++;
		if (evensum == oddsum) {
			printf("%d", count);
			break;
		}			
	}
}
void p03() {
	int x, y;
	scanf_s("%d %d", &x, &y);
	printf("%d", Euclid(x, y));
}
int Euclid(int x, int y) {
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	if (x%y == 0)
		return y;
	else
		return Euclid(x%y, y);
}
void p05() {
	int max, premax, n;
	scanf_s("%d", &n);
	max = premax = n;
	if (n == -1)
		return;
	else {
		while(n!=-1){
			if (n > max) {
				premax = max;
				max = n;
			}
			else if (n > premax)
				premax = n;
			scanf_s("%d", &n);
		}
		printf("%d %d", max, premax);
	}
}
void p07() {
	int pre=2147483647, prepre=2147483647, n, count = 0;
	for (int i = 0; true; i++) {
		scanf_s("%d", &n);
		if (n == -1) {
			if (pre <= prepre)
				count++;
			break;
		}
		if (i == 1 && pre <= n)
			count++;
		else if (pre <= prepre && pre <= n)
			count++;
		prepre = pre;
		pre = n;
	}
	printf("%d", count);
}
void p08() {
	int money, tax = 0;
	int step1 = 12000000, step2 = 46000000, step3 = 88000000;
	int step4 = 150000000, step5 = 500000000;
	scanf_s("%d", &money);
	if (money > step5) {
		tax += (money - step5)*0.4;
		money = step5;
	}
	if (money > step4) {
		tax += (money - step4)*0.38;
		money = step4;
	}
	if (money > step3) {
		tax += (money - step3)*0.35;
		money = step3;
	}
	if (money > step2) {
		tax += (money - step2)*0.24;
		money = step2;
	}
	if (money > step1) {
		tax += (money - step1)*0.15;
		money = step1;
	}
	tax += money * 0.06;
	printf("%d", tax);
}