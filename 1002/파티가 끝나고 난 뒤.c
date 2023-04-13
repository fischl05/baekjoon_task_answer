#include <stdio.h>

int main(void){
	int num, area;
	int num_arr[5];
	
	scanf("%d %d", &num, &area);
	scanf("%d %d %d %d %d", &num_arr[0], &num_arr[1], &num_arr[2], &num_arr[3], &num_arr[4]);
	
	int i;
	for(i = 0 ; i < 5 ; i++){
		printf("%d ", num_arr[i] - num * area);
	} 
	
	return 0;
} 
