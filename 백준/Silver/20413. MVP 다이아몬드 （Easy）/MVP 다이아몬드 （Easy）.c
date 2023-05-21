#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, money = 0, out = 0;
	int grade[4] = { 0 };
	char* arr = NULL;

	scanf("%d", &n);

	for (int i = 0; i < 4; i++)
		scanf("%d", &grade[i]);

	arr = (char*)calloc(n + 1, sizeof(char));

	scanf("%s", arr);
	
	for (int i = 0; i < n; i++) {
		if (arr[i] == 'B') {
			out += grade[0] - money - 1;
			money = grade[0] - money - 1;
		}
		else if (arr[i] == 'S') {
			out += grade[1] - money - 1;
			money = grade[1] - money - 1;
		}
		else if (arr[i] == 'G') {
			out += grade[2] - money - 1;
			money = grade[2] - money - 1;
		}
		else if (arr[i] == 'P') {
			out += grade[3] - money - 1;
			money = grade[3] - money - 1;
		}
		else if (arr[i] == 'D') {
			out += grade[3];
			money = grade[3];
		}
	}
	printf("%d", out);

	return 0;
}