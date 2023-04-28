#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1001] = { 0 };
	int len = 0, out = 0;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == 'Y') {
			out += 1;
			for (int j = i; j < len; j += i + 1) {
				if (str[j] == 'Y') str[j] = 'N';
				else if (str[j] == 'N') str[j] = 'Y';
			}
		}
	}
	printf("%d", out);

	return 0;
}