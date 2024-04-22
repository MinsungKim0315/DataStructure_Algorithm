// 동적할당 이용한 최대공약수 구하기
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b;
	printf("insert two numbers: ");
	scanf_s("%d %d", &a, &b);

	//선생님 코드
	/*int count1 = 0;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0) count1++;
	}
	int* List1 = (int*)malloc(sizeof(int) * count1);
	for (int i = 1, idx = 0; i <= a; i++) {
		if (a % i == 0) List1[idx++] = i;
	}
	int count2 = 0;
	for (int i = 1; i <= b; i++) {
		if (b % i == 0) count2++;
	}
	int* List2 = (int*)malloc(sizeof(int) * count2);
	for (int i = 1, idx = 0; i <= b; i++) {
		if (b % i == 0) List2[idx++] = i;
	}
	for (int i = 0; i < count1; i++) printf("%3d", List1[i]); printf("\n\n");
	for (int i = 0; i < count2; i++) printf("%3d", List2[i]); printf("\n\n");


	int len = 0;
	if (count1 > count2) {
		len = count2;
	}
	else {
		len = count1;
	}

	int count3 = 0;
	for (int idx1 = 0, idx2 = 0; idx1 < len && idx2 < len; ) {
		if (List1[idx1] == List2[idx2]) {
			count3++, idx1++, idx2++;
		}
		else if (List1[idx1] > List2[idx2]) idx2++;
		else idx1++;
	}
	int* List3 = (int*)malloc(sizeof(int) * count3);

	for (int idx1 = 0, idx2 = 0, idx3 = 0; idx1 < len && idx2 < len; ) {
		if (List1[idx1] == List2[idx2]) {
			List3[idx3] = List1[idx1];
			idx3++, idx1++, idx2++;
		}
		else if (List1[idx1] > List2[idx2]) idx2++;
		else idx1++;
	}
	for (int i = 0; i < count3; i++) printf("%3d", List3[i]); printf("\n\n");

	printf("result: %d", List3[count3 - 1]);*/

	int count1 = 0;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0) count1++;
	}
	int* List1 = (int*)malloc(sizeof(int) * count1);

	for (int i = 1, idx = 0; i <= a; i++) {
		if (a % i == 0) List1[idx++] = i;
	}

	int count2 = 0;
	for (int i = 1; i <= b; i++) {
		if (b % i == 0) count2++;
	}
	int* List2 = (int*)malloc(sizeof(int) * count2);

	for (int i = 1, idx = 0; i <= b; i++) {
		if (b % i == 0) List2[idx++] = i;
	}

	for (int i = 0; i < count2; i++) printf("%3d", List2[i]); printf("\n");
	for (int i = 0; i < count1; i++) printf("%3d", List1[i]); printf("\n");


	int count3 = 0;
	for (int i = 0, idx1 = 0, idx2 = 0; idx1 < count1 && idx2 < count2;) {
		if (List1[idx1] == List2[idx2])
			count3++, idx1++, idx2++;
		else if (List1[idx1] > List2[idx2]) idx2++;
		else idx1++;
	}
	int* List3 = (int*)malloc(sizeof(int) * count3);
	for (int i = 0, idx1 = 0, idx2 = 0, idx3  = 0; idx1 < count1 && idx2 < count2;) {
		if (List1[idx1] == List2[idx2])
		{
			List3[idx3] = List1[idx1];
			idx1++, idx2++, idx3++;
		}
		else if (List1[idx1] > List2[idx2]) idx2++;
		else idx1++;
	}

	for (int i = 0; i < count3; i++) printf("%3d", List3[i]); printf("\n");
	printf("최대 공약수 = %d", List3[count3-1]);

	free(List1);
	free(List2);
	free(List3);
}