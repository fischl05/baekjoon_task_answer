#include <stdio.h>

int main(void){
	int hour, min, sec;
	int isec;
	
	scanf("%d %d %d", &hour, &min, &sec);
	scanf("%d", &isec);
	
	while(isec >= 3600){
		isec -= 3600;
		hour += 1;
	}
	
	while(isec >= 60){
		isec -= 60;
		min += 1;
	}
	
	while(isec > 0){
		isec -= 1;
		sec += 1;
	}
	
	while(sec > 59){
		sec -= 60;
		min += 1;
	}
	while(min > 59) {
		min -= 60;
		hour += 1;
	}
	while(hour > 23) hour -= 24;
	
	printf("%d %d %d", hour, min, sec);
	
	return 0;
}
