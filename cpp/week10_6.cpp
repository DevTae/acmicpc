#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN(a,b) ((a > b) ? b : a)
#define MAX(a,b) ((a > b) ? a : b)

struct square {
	int x;
	int y;
	int x2;
	int y2;
};

int main(void) {

	square sq[2];

	for (int i = 0; i < 2; i++) {
		scanf("%d %d %d %d", &sq[i].x, &sq[i].y, &sq[i].x2, &sq[i].y2);
	}

	printf("%d %d %d %d", MIN(sq[0].x, sq[1].x), MIN(sq[0].y, sq[1].y), MAX(sq[0].x2, sq[1].x2), MAX(sq[0].y2, sq[1].y2));

	return 0;

}