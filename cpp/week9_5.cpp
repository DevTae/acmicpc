#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[100];


int len() {
	int i = 0;

	while (str[i] != '\0') i++;

	return i;
}

void del(int i) {

	if (i > len() - 1) i = len() - 1;

		while (str[i + 1] != '\0') {
			str[i] = str[i + 1];
			i++;
		}

	str[i] = '\0';

}

int main(void) {
	
	scanf("%s", &str);

	while (len() > 1) {
		int i;

		scanf("%d", &i);

		del(i-1);

		printf("%s\n", str);
	}

	

}