#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {
	char str[21];
	int len = 0, num = 0;

	scanf("%s", str);
	len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			num += str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			num += str[i] - 'A' + 27;
	}
	
	if (num > 2) {
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				printf("It is not a prime word.\n");
				return 0;
			}
		}
	}
	printf("It is a prime word.\n");

	return 0;
}