#include <stdio.h>

int main(void){
	long long int a, b;
	
	scanf("%lld %lld", &a, &b);
	a = a - b;
	if(a < 0) a *= -1;	
	printf("%lld", a); 
	
	return 0;
}
