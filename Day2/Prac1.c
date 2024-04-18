#include<stdio.h>
int main() {
	int A = 65;
	int* pA = &A;
	int** ppA = &pA;
	int*** pppA = &ppA;

	printf(" %10s ( %-13s ): %d \n", "A", "= A 값", A);
	printf(" %10s ( %-13s ): %p \n\n", "&A", "= A 주소", &A);
	printf(" %10s ( %-13s ): %d \n", "*pA", "= A 값", *pA);
	printf(" %10s ( %-13s ): %p \n", "pA", "= pA 값", pA);
	printf(" %10s ( %-13s ): %p \n\n", "&pA", "= pA 주소", &pA);
	printf(" %10s ( %-13s ): %d \n", "**ppA", "= A 값", **ppA);
	printf(" %10s ( %-13s ): %p \n", "*ppA", "= pA 값", *ppA);
	printf(" %10s ( %-13s ): %p \n", "ppA", "= ppA 값", ppA);
	printf(" %10s ( %-13s ): %p \n\n", "&ppA", "= ppA 주소", &ppA);
	printf(" %10s ( %-13s ): %d \n", "***pppA", "= A 값", ***pppA);
	printf(" %10s ( %-13s ): %p \n", "**pppA", "= pA 값", **pppA);
	printf(" %10s ( %-13s ): %p \n", "*pppA", "= ppA 값", *pppA);
	printf(" %10s ( %-13s ): %p \n", "pppA", "= pppA 값", pppA);
	printf(" %10s ( %-13s ): %p \n\n", "&pppA", "= pppA 주소", &pppA);
}