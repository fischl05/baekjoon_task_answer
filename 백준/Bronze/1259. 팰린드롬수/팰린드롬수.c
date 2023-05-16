#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[7] = { 0 };

	scanf("%s", arr);
	while (arr[0] != '0') {
		int len = strlen(arr);
		int i = 0;
		for (i = 0; i < len / 2; i++) {
			if (arr[i] != arr[len - i - 1]) break;
		}
		if (i >= len / 2) printf("yes\n");
		else printf("no\n");
		
		scanf("%s", arr);
	}

	return 0;
}