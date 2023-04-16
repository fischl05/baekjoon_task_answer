#include <stdio.h>

int main(void) {
	int button[3] = { 300, 60, 10 };
	int out[3] = { 0, 0, 0 };

	int sec;
	scanf("%d", &sec);

	if (sec % 10 != 0) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		while (sec >= button[i]) {
			sec -= button[i];
			out[i]++;
		}
	}

	for (int i = 0; i < 3; i++)
		printf("%d ", out[i]);

	return 0;
}