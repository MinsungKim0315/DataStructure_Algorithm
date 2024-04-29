// 감법 이용한 최대공약수 구하기
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b;
	printf("insert two numbers: ");
	scanf_s("%d %d", &a, &b);

	int t = 0;

	if (a > b) t = b;
	else t = a;

	while (t > 1) {
		if (a % t == 0 && b % t == 0) {
			printf("최대공약수 = %d", t);
			break;
		}
		else {
			t--;
		}
	}
	/*
	while(1){
	if((a % t == 0) && (b % t == 0); break;
	t--;
	}
	*/
}
