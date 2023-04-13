#include <stdio.h>

int main(void){
	int a[3];
	
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	if(a[0] == a[1] && a[1] == a[2])
		printf("%d", 10000 + a[0] * 1000);
	
	else if(a[0] == a[1] || a[0] == a[2] || a[1] == a[2]){
		if(a[0] == a[1]) printf("%d", 1000 + a[0] * 100);
		else if(a[0] == a[2]) printf("%d", 1000 + a[0] * 100);
		else if(a[1] == a[2]) printf("%d", 1000 + a[1] * 100);
	}
	
	else if(a[0] != a[1] && a[0] != a[1] && a[1] != a[2]){
		int max = 0, i = 0;
		for(i = 0 ; i < 3 ; i++)
			if(max < a[i]) max = a[i];
		printf("%d", max * 100);		
	}
	
	return 0;
}
