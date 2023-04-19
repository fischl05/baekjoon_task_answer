#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	float avr = 0.0;
	float sum = 0.0;

	for (int i = 0; i < 20; i++) {
		char str[51];
		char grade[3] = { 0 };
		float score = 0.0;
		scanf("%s %f %s", str, &score, grade);
		if (!strcmp(grade, "A+")) {
			avr += score * 4.5;
			sum += score;
		}
		else if (!strcmp(grade, "A0")) {
			avr += score * 4.0;
			sum += score;
		}
		else if (!strcmp(grade, "B+")) {
			avr += score * 3.5;
			sum += score;
		}
		else if (!strcmp(grade, "B0")) {
			avr += score * 3.0;
			sum += score;
		}
		else if (!strcmp(grade, "C+")) {
			avr += score * 2.5;
			sum += score;
		}
		else if (!strcmp(grade, "C0")) {
			avr += score * 2.0;
			sum += score;
		}
		else if (!strcmp(grade, "D+")) {
			avr += score * 1.5;
			sum += score;
		}
		else if (!strcmp(grade, "D0")) {
			avr += score * 1.0;
			sum += score;
		}
		else if (!strcmp(grade, "F")) {
			avr += score * 0.0;
			sum += score;
		}
		else continue;
	}
	if (sum == 0.0) printf("0.000000\n");
	else printf("%.6f\n", avr / sum);

	return 0;
}