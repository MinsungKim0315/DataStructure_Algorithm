/*
N명의 학생 성적 종합 코드
	> N명의 학생 수 입력
	> 정수형 메모리 공간 N개 할당
	> N개의 점수 입력(1~100점)[rand() 사용]
	> N명의 총점, 평균, 편차, 분산, 표준편차 출력
		--> 편차 = 원점수 - 평균
		--> 분산 = (모든 성적의 편차 제곱을 더한 값) / N(학생수)
		--> 표준편차 = sqrt(분산)
결과 출력
학생수 : 10
  1번         56
  2번         76
 …            …
10번         75
---------------
총점          415
평균          41.54
분산          654
표준편차   25.57
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
	int cnt = 0;
	printf("학생 수: ");
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
