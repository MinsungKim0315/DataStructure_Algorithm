/*
나선형 2차원 배열 만들기
  N == 4
 1  2  3 4
12 13 14 5
11 16 15 6
10  9  8 7
*/
#include<stdio.h>
#include<stdlib.h>

void print(int** square, int n){	//생성한 2차원 배열 출력
	for (int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%5d", square[i][j]);
		}printf("\n");
	}printf("\n");
}

int** sprial(int n){
	int** square = (int**)malloc(n * sizeof(int*));	//2차원 배열 형태로 메모리 할당
	for(int i = 0; i < n; i++){
		square[i] = (int*)malloc(n * sizeof(int));
	}
	int key = 1;
	//down:3 -> left:3 -> up:2 -> right:2 -> down:1 -> left:1
	int x = n-1, y = 0;

	// for (int i = 0; i < 3; i++){	//down
	// 	square[++y][x] = key++;
	// }
	// for(int i = 0; i < 3; i++){		//left
	// 	square[y][--x] = key++;
	// }
	// for(int i = 0;i < 2; i++){		//up
	// 	square[--y][x] = key++;
	// }
	// for(int i = 0;i < 2; i++){		//right
	// 	square[y][++x] = key++;
	// }
	// for(int i = 0;i < 1;i++){		//down
	// 	square[++y][x] = key++;
	// }
	// for(int i = 0;i < 1;i++){		//left
	// 	square[y][--x] = key++;
	// }
	//====================================
	//n-1부터 2번 씩 실행하고 1 줄어들어서 1이 될때까지 반복
	int dir = 0;
	char direction[] = {'D', 'L', 'U', 'R'};

	for(int i = 0; i < n; i++){
		square[0][i] = key++;
	}
	while(n--)
		for(int j = 0;j < 2;j++)
			switch (direction[(dir++) % 4]){
			case 'D': for (int i = 0; i < n;i++) square[++y][x] = key++; break;
			case 'L': for (int i = 0; i < n;i++) square[y][--x] = key++; break;
			case 'U': for (int i = 0; i < n;i++) square[--y][x] = key++; break;
			case 'R': for (int i = 0; i < n;i++) square[y][++x] = key++; break;
			}
	
	return square;
}

void freeSquare(int** square, int n){	//할당한 메모리 제거
	for (int i = 0; i < n;i++){
		free(square[i]);
	}
	free(square);
}

int main() {
	printf("[spiral 2-d array]\n");
	int** arr1 = sprial(4);
	print(arr1, 4);
	int** arr2 = sprial(5);
	print(arr2, 5);
	freeSquare(arr1, 4);
	freeSquare(arr2, 5);
}