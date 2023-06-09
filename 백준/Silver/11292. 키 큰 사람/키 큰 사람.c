#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[11];
	float tall;
}PERSON;

int main(void) {
	int n;
	
	scanf("%d", &n);

	while (n != 0) {
		float max = 0.0;
		PERSON* arr = (PERSON*)calloc(n, sizeof(PERSON));
		
		for (int i = 0; i < n; i++) {
			scanf("%s %f", arr[i].name, &arr[i].tall);
			if (arr[i].tall > max) max = arr[i].tall;
		}

		for (int i = 0; i < n; i++)
			if (arr[i].tall == max) printf("%s ", arr[i].name);
		printf("\n");

		scanf("%d", &n);
	}

	return 0;
}