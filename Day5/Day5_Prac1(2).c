// ���� �̿��� �ִ����� ���ϱ�
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
			printf("�ִ����� = %d", t);
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