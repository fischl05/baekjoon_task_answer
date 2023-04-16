#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, out = 0, max = 0;

	scanf("%d", &n);

	int* score = (int*)calloc(sizeof(int), n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &score[i]);

	for (int j = 1; j < n; j++)
		if (max < score[j]) max = score[j];

	while(score[0] <= max){
		max = 0;
		for (int j = 1; j < n; j++)
			if (max < score[j]) max = score[j];

		for (int j = 1; j < n; j++) {
			if (score[j] == max) {
				score[j] -= 1;
				score[0] += 1;
				out += 1;
				max = 0;
				for (int z = 1; z < n; z++)
					if (max < score[z]) max = score[z];
				if (score[0] > max) break;
			}
		}
	}
	printf("%d", out);

	return 0;
}