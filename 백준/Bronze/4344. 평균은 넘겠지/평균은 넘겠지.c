#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num, sum = 0;
		float avr = 0.0, out = 0.0;
		scanf("%d", &num);

		int* score = (int*)calloc(sizeof(int), num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		avr = (float)sum / (float)num;

		int person = 0;
		for(int j = 0 ; j < num ; j++){
			if (score[j] > avr) person++;
		}
		out = (float)person / (float)num * 100;
		printf("%0.3f%%\n", out);

		free(score);
	}

	return 0;
}