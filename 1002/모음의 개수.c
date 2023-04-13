#include <stdio.h>
#include <string.h>

int main(void){
	char string[257];	
	memset(string, 0, sizeof(string));

	while(1){
		int i, res = 0;
		gets(string);
//		if(strcpy(string, "#")) break;
		if(string[0] == '#') break;
		
		for(i = 0 ; i < strlen(string) ; i++){
			if(string[i] == 'a' || string[i] == 'A') res++;
			if(string[i] == 'e' || string[i] == 'E') res++;
			if(string[i] == 'i' || string[i] == 'I') res++;
			if(string[i] == 'o' || string[i] == 'O') res++;
			if(string[i] == 'u' || string[i] == 'U') res++;
		}
		printf("%d\n", res);
	} 
	return 0;
}
