/*
최대공약수 알고리즘
호제법
	> a를 b로 나누고 그 나머지를 r이라 한다
	> r 이 0이 아니면 a = b. b = r에 대입 후 과정 1 반복
	> r 이 0이면 b가 최대공약수
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, r;

	printf("두 수 입력하시오: ");
	scanf_s("%d %d", &a, &b);

	while (1) {
		r = a % b;
		if (r == 0) break;
		else a = b; b = r;
	}
	printf("최대공약수 = %d", b);

}
