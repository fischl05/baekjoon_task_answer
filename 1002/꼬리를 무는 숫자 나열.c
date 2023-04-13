#include <stdio.h>
#include <math.h>

int main(void){
	int a, b;
	int x, y;
	scanf("%d %d", &a, &b);
	
	a--;
	b--;
	
	x = abs((a / 4) - (b / 4));
	y = abs((a % 4) - (b % 4));
		
	printf("%d", x + y); 
	
	return 0;
}
