#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int coe[26];

int pow_ten(int n) {
	int return_value = 1;
	for (int i = 0; i < n; i++) {
		return_value *= 10;
	}
	return return_value;
}

void reverse(char arr[]) {
	int len = strlen(arr) - 1;
	for (int i = 0; i <= len / 2; i++) {
		char temp = arr[i];
		arr[i] = arr[len - i];
		arr[len - i] = temp;
	}
}

int compare_item(int* a, int* b) {
	return *b - *a;
}

int main(void) {
	int n, sum = 0;

	scanf("%d", &n);

	char** string = (char**)calloc(sizeof(char*), n);
	for (int i = 0; i < n; i++)
		string[i] = (char*)calloc(sizeof(char), 11);

	for (int i = 0; i < n; i++) {
		scanf("%s", string[i]);
		reverse(string[i]);
	}

	for (int i = 0; i < n; i++) {
		int len = strlen(string[i]);
		for (int j = 0; j < len; j++) {
			if (string[i][j] - 'A' >= 0)
				coe[string[i][j] - 'A'] += pow_ten(j);
		}
	}
	qsort((int*)coe, 26, sizeof(int), compare_item);
	
	for (int i = 0; i < 26; i++) {
		sum += (coe[i] * (9 - i));
	}
	printf("%d", sum);

	for (int i = 0; i < n; i++)
		free(string[i]);
	free(string);

	return 0;
}