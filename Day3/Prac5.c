/*
�� �г� �л����� ���� ���� �ڵ�
(����ü ���)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct CLASS {
	int StudentNumber;
	double ClassAverage;
	double ClassDispersion;
	double ClassDeviation;
	int* StudentScore;
}CLASS;

int main() {
	srand((unsigned)time(NULL));
	int num_class;
	printf("number of classes: ");
	scanf_s("%d", &num_class);
	while (getchar() != '\n');

	CLASS* c = (CLASS*)malloc(sizeof(CLASS) * num_class);	//����ü �� ���� ��ŭ �Ҵ�
	if (c == NULL) exit(1);

	for (int i = 0; i < num_class; i++) {
		printf("number of students in class #%d: ", i + 1);
		scanf_s("%d", &c[i].StudentNumber);	//2���� �迭 ����
		while (getchar() != '\n');
		c[i].StudentScore = (int*)malloc(sizeof(int) * c[i].StudentNumber);	//�� �� �л� �� ��ŭ�� �޸� �Ҵ��� ���� �Է�
		for (int j = 0; j < c[i].StudentNumber; j++) {
			c[i].StudentScore[j] = rand() % 100 + 1;
			printf("%4d\n", c[i].StudentScore[j]);
		}
	}
	for (int i = 0; i < num_class; i++) {
		c[i].ClassAverage = 0;  // Initialize average
		for (int j = 0; j < c[i].StudentNumber; j++) {	//��� ���
			c[i].ClassAverage += c[i].StudentScore[j];
		}
		c[i].ClassAverage = c[i].ClassAverage / c[i].StudentNumber;
		for (int j = 0; j < c[i].StudentNumber; j++) {	//�л� �I ǥ������ ���
			c[i].ClassDispersion += (c[i].StudentScore[j] - c[i].ClassAverage) * (c[i].StudentScore[j] - c[i].ClassAverage);
		}
		c[i].ClassDispersion = c[i].ClassDispersion / c[i].StudentNumber;
		c[i].ClassDeviation = sqrt(c[i].ClassDispersion);
	}
	printf("%3s %7s %11s %11s %11s\n", "Class", "Student num", "Average", "Disersion", "Deviation");
	for (int i = 0; i < num_class; i++) {
		printf(" % 3d % 7d % 11.2lf % 11.2lf % 11.2lf\n",i + 1, c[i].StudentNumber, c[i].ClassAverage, c[i].ClassDispersion, c[i].ClassDeviation);
	}

	for (int i = 0; i < num_class; i++){
		free(c[i].StudentScore);
	}
	free(c);

}