#include <stdio.h>

int main(void){
	int a, b, v;
	int day = 0, m = 0;
	
	scanf("%d %d %d", &a, &b, &v);
	
	if((v-b) % (a-b) != 0)
		printf("%d", (v-b)/(a-b) + 1);
	else
		printf("%d", (v-b)/(a-b));
	
	return 0;
}
