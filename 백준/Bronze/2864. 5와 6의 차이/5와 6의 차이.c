#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int min, max;
	char num1[20] = {0};
	char num2[20] = {0};
	
	scanf("%s %s", num1, num2);
	
	int len = strlen(num1);
	for(int i = 0 ; i < len ; i++)
		if(num1[i] == '5') num1[i] = '6';
		
	len = strlen(num2);
	for(int i = 0 ; i < len ; i++)
		if(num2[i] == '5') num2[i] = '6';
	max = atoi(num1) + atoi(num2);
	
	len = strlen(num1);
	for(int i = 0 ; i < len ; i++)
	if(num1[i] == '6') num1[i] = '5';
		
	len = strlen(num2);
	for(int i = 0 ; i < len ; i++)
		if(num2[i] == '6') num2[i] = '5';
	min = atoi(num1) + atoi(num2);

	printf("%d %d", min, max);
		
	return 0;
}