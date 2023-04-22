#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	char num[11] = { 0 };
	int len = 0;

	scanf("%s", num);

	len = strlen(num);

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (num[j] < num[i]) swap(&num[i], &num[j]);
	
	printf("%s", num);

	return 0;
}