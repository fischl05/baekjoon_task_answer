#include <stdio.h>
#include <string.h>

int main(void) {
	char str[10];

	scanf("%s", str);

	if (!strcmp(str, "SONGDO")) printf("HIGHSCHOOL");
	else if (!strcmp(str, "CODE")) printf("MASTER");
	else if (!strcmp(str, "2023")) printf("0611");
	else if (!strcmp(str, "ALGORITHM")) printf("CONTEST");

	return 0;
}