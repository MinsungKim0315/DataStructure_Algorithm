/*
문자열 나누기
*/
#include <stdio.h> // main.c
#include <stdlib.h>
// 문자열을 기호로 나누어 반환하는 함수
// char** (반환값) : 나뉜 문자열을 저장한 포인터 배열의 시작 주소를 반환
// char* str : 나눌 문자열을 저장한 배열의 시작 주소
// char sign : 구분 기호
// int* cnt : 나뉜 문자열의 수량
char** split(char* str, char sign, int* cnt) {
    if (str == NULL) return NULL;

    char** ary = NULL;
    *cnt = 0; // 나눠질 문자열 수량 변수

    for (int end = 0; str[end] != '\0';) {
        (*cnt)++;
        ary = (char**)realloc(ary, sizeof(char*) * (*cnt)); // 문자열 저장 공간 할당

        int len = 0; // 한 블럭 문자열 길이
        for (int i = end; str[i] != sign && str[i] != '\0'; i++) len++;

        ary[(*cnt) - 1] = (char*)malloc(len + 1); // char ary[(*cnt) - 1][len + 1];

        for (int i = 0; i < len; i++) // 문자열 복사 : strcpy()
            ary[(*cnt) - 1][i] = str[end + i];

        ary[(*cnt) - 1][len] = '\0';

        if (str[end + len] == '\0') break;
        else end += len + 1;
    }
    return ary;
}
int main() {
    int cnt1 = 0;
    char** arr1 = split("Hello World! Welcome to the programming!", ' ', &cnt1);
    for (int i = 0; i < cnt1; i++) { printf("%s\n", arr1[i]); free(arr1[i]); }
    free(arr1);
    printf("--------------------\n");

    int cnt2 = 0;
    char** arr2 = split("Hi.C Language.I like it!", '.', &cnt2);
    for (int i = 0; i < cnt2; i++) { printf("%s\n", arr2[i]); free(arr2[i]); }
    free(arr2);
}
