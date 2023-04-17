#include <stdio.h>

int main(void) {
	int spot[3];
	for (int i = 0; i < 3; i++)
		spot[i] = 0;

	//while (1) {
		for (int i = 0; i < 3; i++)
			scanf("%d", &spot[i]);

		printf("%d\n", spot[1] - spot[0] - 1 > spot[2] - spot[1] - 1 ? spot[1] - spot[0] - 1 : spot[2] - spot[1] - 1);
	//}

	return 0;
}