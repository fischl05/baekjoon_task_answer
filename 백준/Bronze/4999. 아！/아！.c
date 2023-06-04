#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1001] = { 0 }, input[1001] = { 0 };

	scanf("%s %s", input, str);
	
	if (strlen(input) >= strlen(str)) printf("go\n");
	else printf("no\n");

	return 0;
}