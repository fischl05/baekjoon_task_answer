#include <stdio.h>
#include <string.h>

int main(void) {
	char str[3];

	scanf("%s", str);
	
	switch (str[0]) {
	case 'A':
		if (str[1] == '+') printf("4.3");
		else if (str[1] == '0') printf("4.0");
		else if (str[1] == '-') printf("3.7");
		break;
	case 'B':
		if (str[1] == '+') printf("3.3");
		else if (str[1] == '0') printf("3.0");
		else if (str[1] == '-') printf("2.7");
		break;
	case 'C':
		if (str[1] == '+') printf("2.3");
		else if (str[1] == '0') printf("2.0");
		else if (str[1] == '-') printf("1.7");
		break;
	case 'D':
		if (str[1] == '+') printf("1.3");
		else if (str[1] == '0') printf("1.0");
		else if (str[1] == '-') printf("0.7");
		break;
	case 'F':
		printf("0.0");
		break;
	}

	return 0;
}