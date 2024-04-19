/*
한 학년 학생들의 성적 종합 코드
(구조체 사용)
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

	CLASS* c = (CLASS*)malloc(sizeof(CLASS) * num_class);	//구조체 반 개수 만큼 할당
	if (c == NULL) exit(1);

	for (int i = 0; i < num_class; i++) {
		printf("number of students in class #%d: ", i + 1);
		scanf_s("%d", &c[i].StudentNumber);	//2차원 배열 생성
		while (getchar() != '\n');
		c[i].StudentScore = (int*)malloc(sizeof(int) * c[i].StudentNumber);	//각 반 학생 수 만큼의 메모리 할당해 점수 입력
		for (int j = 0; j < c[i].StudentNumber; j++) {
			c[i].StudentScore[j] = rand() % 100 + 1;
			printf("%4d\n", c[i].StudentScore[j]);
		}
	}
	for (int i = 0; i < num_class; i++) {
		c[i].ClassAverage = 0;  // Initialize average
		for (int j = 0; j < c[i].StudentNumber; j++) {	//평균 계산
			c[i].ClassAverage += c[i].StudentScore[j];
		}
		c[i].ClassAverage = c[i].ClassAverage / c[i].StudentNumber;
		for (int j = 0; j < c[i].StudentNumber; j++) {	//분산 밒 표준편차 계산
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