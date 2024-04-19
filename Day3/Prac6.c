/*
���ڿ� ������
*/
#include <stdio.h> // main.c
#include <stdlib.h>
// ���ڿ��� ��ȣ�� ������ ��ȯ�ϴ� �Լ�
// char** (��ȯ��) : ���� ���ڿ��� ������ ������ �迭�� ���� �ּҸ� ��ȯ
// char* str : ���� ���ڿ��� ������ �迭�� ���� �ּ�
// char sign : ���� ��ȣ
// int* cnt : ���� ���ڿ��� ����
char** split(char* str, char sign, int* cnt) {
    if (str == NULL) return NULL;

    char** ary = NULL;
    *cnt = 0; // ������ ���ڿ� ���� ����

    for (int end = 0; str[end] != '\0';) {
        (*cnt)++;
        ary = (char**)realloc(ary, sizeof(char*) * (*cnt)); // ���ڿ� ���� ���� �Ҵ�

        int len = 0; // �� �� ���ڿ� ����
        for (int i = end; str[i] != sign && str[i] != '\0'; i++) len++;

        ary[(*cnt) - 1] = (char*)malloc(len + 1); // char ary[(*cnt) - 1][len + 1];

        for (int i = 0; i < len; i++) // ���ڿ� ���� : strcpy()
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
