/*
N명의 학생 정보를 구조체 저장
  > N명의 학생 수 입력
  > 구조체[score] 메모리 공간 N개 할당
  > kor, eng, math 임의 점수(1~100)입력
  > 임시 공간에 이름 입력(문자열)
  > name 멤버에 문자열 길이만큼 동적 할당
  > N 명의 이름: 총점, 평균값 출력
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct score{
	char *name;
	int kor, eng, math, total;
}score;

void input(score *pS, int number);
void output(score *pS, int number);
void freeMemory(score *pS, int number);

int main(){
	srand((unsigned)time(NULL));
	int number;
	//N명의 학생 수 입력
	printf("input student number: ");
	scanf("%d", &number);
	while (getchar() != '\n');	//scanf 의해 발생하는 개행문자 제거

	//구조체[score] 메모리 공간 N개 할당
	score *s = (score *)malloc(sizeof(score) * number);
	if(s == NULL) exit(1);

	input(s, number);
	output(s, number);
	freeMemory(s, number);

	return 0;
}
void input(score *pS, int number){
	//kor, eng, math 임의 점수(1~100)입력
	for(int i = 0; i < number; i++){
		pS[i].kor = rand()%100 + 1;
		pS[i].eng = rand()%100 + 1;
		pS[i].math = rand()%100 + 1;

	//사용자로부터 이름 입력 받기
		char buf[1000];
		printf("input name: ");
		gets(buf);
		int len = strlen(buf);
		pS[i].name = (char*)malloc(sizeof(char) * (len + 1));
		if(pS[i].name == NULL) exit(1);
		for(int j = 0;j < len+1;j++){
			pS[i].name[j] = buf[j];
		}
		pS[i].total = pS[i].kor + pS[i].eng + pS[i].math;
		printf("\n %3dth input \n", i + 1);
		printf("Korean : %3d \n", pS[i].kor);
		printf("English : %3d \n", pS[i].eng);
		printf("Math : %3d \n", pS[i].math);
		printf("Name : %s \n", pS[i].name);
		printf("Total : %3d \n", pS[i].total);
	}

}

void output(score* pS, int number) {
  printf("\n\n *** Total & Average ***\n");
  for (int i = 0; i < number; i++) {
    printf("%3dth. Name : %-15s  ", i + 1, pS[i].name);
    printf("Total : %3d  Average : %3.2lf \n", pS[i].total, (double)pS[i].total / 3);
  }
  printf("\n");
}
void freeMemory(score* pS, int number) {
  for (int i = 0; i < number; i++)
    free(pS[i].name); 
  free(pS);
}
