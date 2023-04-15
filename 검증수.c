#include <stdio.h>

int main(void){
	int arr[5];
	int res = 0, i;
	
	for(i = 0 ; i < 5 ; i++){
		scanf("%d", &arr[i]);
		res += arr[i] * arr[i];
	} 
	
	res %= 10;
	printf("%d", res);
	 
	return 0;
}
