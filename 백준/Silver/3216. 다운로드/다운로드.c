#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int len;
	int sec;
}DATA;

int main(void) {
	int n, out = 0;
	DATA* arr = NULL;

	scanf("%d", &n);
	arr = (DATA*)calloc(sizeof(DATA), n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].len, &arr[i].sec);
	
	out += arr[0].sec;
	for (int i = 1; i < n; i++) {
		arr[i].sec -= arr[i - 1].len;
		if (arr[i].sec < 0) {
			arr[i + 1].sec += arr[i].sec;
			arr[i].sec = 0;
		}
		out += arr[i].sec;
	}

	printf("%d", out);

	return 0;
}