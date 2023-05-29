#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main(void) {
	char str[51] = { 0 };
	char str_buf[51] = { 0 };
	char s[2] = { 0 };
	int len = 0, idx = -1, alpa[26] = { 0 };
	int cnt = 0;

	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
		alpa[str[i] - 'A'] += 1;

	for (int i = 0; i < 26; i++) {
		if (alpa[i] % 2 != 0) {
			cnt++;
			alpa[i] -= 1;
			idx = i;
		}
		if (cnt >= 2) {
			printf("I'm Sorry Hansoo\n");
			return 0;
		}
	}

	int j = 0;
	for (int i = 0; i < 26; i++) {
		while (alpa[i] > 0) {
			str_buf[j++] = 'A' + i;
			alpa[i] -= 2;
		}
	}
	memset(str, 0, len);
	strcpy(str, str_buf);
	reverse(str);

	s[0] = 'A' + idx;
	if (idx >= 0) strcat(str_buf, s);

	strcat(str_buf, str);

	j = 0;
	while (str_buf[j] == '\0') j++;

	printf("%s\n", str_buf + j);

	return 0;
}