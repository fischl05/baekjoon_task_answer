#include <stdio.h>
#include <string.h>

char str[1000001];

int main(void) {
	int out = 0;

	//fgets(str, 1000001, stdin);
	scanf("%[^\n]s", str);

	int len = strlen(str);

	if (len == 1 && str[0] == ' ') {
		printf("0\n");
		return 0;
	}
	//else {
		for (int i = 1; i < len - 1; i++) {
			if (str[i] == ' ' && str[i - 1] != ' ' && i + 1 <= len - 1) out++;
		}
		printf("%d", out + 1);
	//}

	return 0;
}