#include <stdio.h>

typedef struct point {
	int x;
	int y;
}Point;

int get_line_parameter(Point p1, Point p2, float* slope, float* yintercept);

int main() {
	Point pt1, pt2;
	while (1) {
		printf("pt1 좌표 입력: ");
		scanf_s("%d %d", &pt1.x, &pt1.y);
		printf("pt2 좌표 입력: ");
		scanf_s("%d %d", &pt2.x, &pt2.y);
		float slp = 0, yinter = 0;
		if (get_line_parameter(pt1, pt2, &slp, &yinter) == 0)
			printf("기울기: %.2f y절편: %.2f\n\n", slp, yinter);
		else
			printf("Error!\n\n");
	}
	return 0;
}
int get_line_parameter(Point p1, Point p2, float* slope, float* yintercept) {
	if (p2.x == p1.x)
		return -1;
	*slope = ((float)p2.y - p1.y) / (p2.x - p1.x);
	*yintercept = p1.y - (*slope) * p1.x;
	return 0;
}
