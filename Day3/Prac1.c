/*
N���� �л� ���� ���� �ڵ�
	> N���� �л� �� �Է�
	> ������ �޸� ���� N�� �Ҵ�
	> N���� ���� �Է�(1~100��)[rand() ���]
	> N���� ����, ���, ����, �л�, ǥ������ ���
		--> ���� = ������ - ���
		--> �л� = (��� ������ ���� ������ ���� ��) / N(�л���)
		--> ǥ������ = sqrt(�л�)
��� ���
�л��� : 10
  1��         56
  2��         76
 ��            ��
10��         75
---------------
����          415
���          41.54
�л�          654
ǥ������   25.57
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
	int cnt = 0;
	printf("�л� ��: ");
	scanf("%d", &cnt);

	int* student = (int*)malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++) {
		student[i] = rand() % 100 + 1;
		printf("%d\n", student[i]);
	}
	printf("\n");

	int total = 0; 
	double temp = 0, average = 0, variance = 0, deviation = 0;

	for (int i = 0; i < cnt; i++) {
		total = total + student[i];
	}
	average = total / cnt;

	for (int i = 0; i < cnt; i++) {
		temp += (student[i] - average) * (student[i] - average);
	}
	variance = temp / cnt;
	deviation = sqrtf(variance);

	printf("total: %d\naverage: %lf\n", total, average);
	printf("variance: %lf\ndeviation: %lf", variance, deviation);

	return 0;
}