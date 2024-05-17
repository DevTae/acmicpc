#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char name[21];
	char school[21];
	int grade;
};

int main(void) {

	student stu;

	scanf("%s", &stu.name);
	scanf("%s", &stu.school);
	scanf("%d", &stu.grade);

	printf("Name : %s School : %s Grade : %d\n", stu.name, stu.school, stu.grade);

	return 0;

}