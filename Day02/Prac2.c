#include<stdio.h>
#define Max 5
int main() {
    int ary[Max] = { 10 , 20 , 30 , 40 , 50 };
    int* pAry[Max] = { &ary[0] , &ary[1] , &ary[2] , &ary[3] , &ary[4] };
    for (int i = 0; i < Max; i++) printf("%3d ", ary[i]);
    printf("\n");
    for (int i = 0; i < Max; i++) printf("%3d ", *pAry[i]);
    printf("\n\n");

    int score[Max + 1][Max + 1] = { 0 }, key = 0;
    int* pScore = &score[0][0];
    int* pSarr[Max + 1] = { score[0] , score[1] , score[2] , score[3] , score[4] , score[5] };
    int** ppScore = pSarr;

    for (int i = 0; i < Max; i++)
        for (int j = 0; j < Max; j++) score[i][j] = ++key;  //2차원 배열 숫자 채우는 법

    for (int i = 0; i < Max + 1; i++) {
        for (int j = 0; j < Max + 1; j++) printf("%3d ", score[i][j]);
        printf("\n");
    } printf("\n");

    for (int i = 0; i < Max + 1; i++) printf("%3d ", *(pScore + i));
    printf("\n\n");

    for (int i = 0; i < Max + 1; i++) {
        printf("%3d ", *pSarr[i]);
        printf("\n");
    } printf("\n");
    return 0;


    /*ary[i] == *(ary + i);
    ppScore[i][j] == (*(ppScore + i))[j] == (*(ppScore[i] + j)) == (*(*(ppScore + i) + j));*/
    for (int i = 0; i < Max + 1; i++) {
        for (int j = 0; j < Max + 1; j++) printf("%3d ", ppScore[i][j]);
        printf("\n");
    } printf("\n");
    for (int i = 0; i < Max + 1; i++) {
        for (int j = 0; j < Max + 1; j++) printf("%3d ", (*(ppScore + i))[j]);
        printf("\n");
    } printf("\n");
    for (int i = 0; i < Max + 1; i++) {
        for (int j = 0; j < Max + 1; j++) printf("%3d ", (*(ppScore[i] + j)));
        printf("\n");
    } printf("\n");
    for (int i = 0; i < Max + 1; i++) {
        for (int j = 0; j < Max + 1; j++) printf("%3d ", (*(*(ppScore + i) + j)));
        printf("\n");
    } printf("\n");
}
