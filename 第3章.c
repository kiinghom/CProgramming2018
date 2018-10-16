
#include<stdio.h>
#include<stdlib.h>

void p20() {
	int left[20], right[20], len =0;
	int x;
	scanf("%d", &x);
	if(x < 0) {
		printf("No\n");
		return;
	}
	if(x == 0) {
		printf("Yes\n");
		return;
	}/*
	while(x != 0) {
		int last = x % 10;
		left[len] = last;
		len++;
		x = x / 10;
		//left[len++] = x % 10;
		//x /= 10;
	}*/
	int b = 0;
	int save = x;
	while(x != 0) {
		b = b * 10 + x %10;
		x /= 10;
	}
	if(b == save) {
		printf("Yes\n");
		return;
	}
	//bool flag = true;
	int flag = 1;
	for(int i = 0; i < len; i++) {
		if(left[i] != left[len - i - 1]){
			flag = 1; //false;
			break;
		}
	}
	if(flag) {
		printf("Yes\n");
		return;
	}
}

void p21() {
	printf("        10         2         8        16\n");
	char s[60];
	for(int i = 1; i <= 256; i++) {
		itoa(i, s, 2);
		printf("%10d%10s%10o%10X\n",i,s,i,i);
	}
}

double f(double x) {
	return x * x * x - x * x - 1; 
}

bool sign(double x) {
	return x >= 0;
}

void p24() {
	double left = 0, right = 3;
	double fleft = f(left);
	double fright = f(right);
	for(int i = 0; i < 30; i++) {
		double mid = (left + right) / 2;
		double fmid = f(mid);
		if(sign(fmid) == sign(fright)) {
			right = mid;
			fright = fmid;
		} else {
			left = mid;
			fleft = fmid;
		}
	}
	printf("%lf\n", (left + right) / 2);
}

int main()
{
	p20();
	p21();
	p24();
}