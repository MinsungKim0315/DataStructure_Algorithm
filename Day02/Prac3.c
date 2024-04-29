#include <stdio.h>
#include <stdlib.h>

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }
int Mul(int x, int y) { return x * y; }
int Div(int x, int y) { return x / y; }
int Call(int x, int y, int(*pF)(int, int)) { return pF(x, y); }

int main() {
	while (1)
	{
		int a = 0, b = 0;
		char c = 0;
		char arr[50];
		printf("예시( 3 + 5) 입력: ");
		gets_s(arr, 50);
		for (int i = 0; arr[i] != '\0'; i++) {
			if ('0' <= arr[i] && arr[i] <= '9' && c == 0) {
			//'0' <= arr[i] <= '9'라고 사용하면 안됌 --> '0' <= arr[i]만 처리하고 넘어감
				//a = (int)(arr[i]) - '0';
				//a = (int)(arr[i])만 쓰면 arr[i]가 '3'이면 '3'의 ASCII값이 들어감; 따라서 -'0'필요
				//하지만 이 방법은 10 미만 정수만 해결 가능
				a = a * 10 + arr[i] - '0';	//이렇게 해야 자릿수 처리 가능
			}
			else if ('0' <= arr[i] && arr[i] <= '9' && c != 0) {
				b = b * 10 + arr[i] - '0';
			}
			else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
			{
				c = arr[i];
			}
		}

		int (*pF)(int, int) = NULL;
        
		switch (c) {
		case '+': pF = Add; break; // add 함수 이름 == 메모리 시작 주소
		case '-': pF = Sub; break;
		case '*': pF = Mul; break;
		case '/': pF = Div; break;
		default: printf("Error\n"); exit(0);
		}
		printf("\n계산 결과 값 : %5d %c %5d = %5d \n", a, c, b, Call(a, b, pF));
	}
	return 0;
}
