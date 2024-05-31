#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	int buffer[2];

	FILE* stream;

	stream = fopen("input.txt", "r");

	fscanf(stream, "%d %d", &buffer[0], &buffer[1]);

	fclose(stream);

	printf("%d %d", buffer[0], buffer[1]);


	int sum = buffer[0] + buffer[1];


	stream = fopen("output.txt", "w");

	fprintf(stream, "%d", sum);
	fprintf(stream, "%d\n%d", sum, sum);

	fclose(stream);

	return 0;

}