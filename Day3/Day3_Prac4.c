/*
�� �г� �л����� ���� ���� �ڵ�
	> �г� �� �й� �� �Է�
	> �й� �� ��ŭ ������ �迭 �Ҵ�
		- 1���� �л��� �Է�
		- 1���� ������ ���� �Է�
		- 2���� �л��� �Է�
		- 2���� ������ ���� �Է�
		...
		- n���� �л��� �Է�
		- n�� ������ ���� �Է�
	> �й� �� ���� ���[��, �л���, ���, �л�]
	> int **score;
*/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand((unsigned)time(NULL));

	int num_class = 0;
	double diff = 0;
	printf("input class number: ");
	scanf_s("%d",&num_class);
	int** class = (int**)malloc(sizeof(int*) * num_class);
	int* students_per_class = (int*)malloc(sizeof(int) * num_class);
	int* student = (int*)malloc(sizeof(int) * num_class);
	double* average = (double*)malloc(sizeof(double) * num_class);
	double* deviation = (double*)malloc(sizeof(double) * num_class);

	for (int i = 0; i < num_class;i++) {
		printf("input student number: ");
		scanf_s("%d", &students_per_class[i]);
		class[i] = (int*)malloc(sizeof(int) * students_per_class[i]);
	}
	for(int i = 0; i < num_class;i++){
		for (int j = 0; j < students_per_class[i]; j++) {
			class[i][j] = rand() % 100 + 1;
			/*total += class[i][j];
			avg = total / students_per_class[i];
			diff += class[i][j] - avg;
			dev = diff / students_per_class[i];*/
		}
	}
	for (int i = 0; i < num_class; i++) {
		int total = 0;
		for (int j = 0; j < students_per_class[i]; j++) {
			total = total + class[i][j];
		}
		average[i] = (double)total / students_per_class[i];
	}
	for (int i = 0; i < num_class; i++) {
		diff = 0;
		for (int j = 0; j < students_per_class[i]; j++) {
			diff += (class[i][j] - average[i]) * (class[i][j] - average[i]);
		}
		deviation[i] = diff / students_per_class[i];
	}
	
	for (int i = 0; i< num_class; i++) {
		printf("class name: %d\n", i+1);
		printf("student number: %d, average: %.2f, devation: %.2f\n", students_per_class[i], average[i], deviation[i]);
	}
	free(class);
	free(students_per_class);
	free(average);
	free(deviation);
}