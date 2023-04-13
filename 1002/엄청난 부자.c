#include <stdio.h>
#include <string.h>

void minus(char* a, char* b){
	int i = 0;
	for(i = strlen(b) - 1 ; i >= 0 ; i--){
		a[i] = a[i] - b[i] + '0';
		if(a[i] < '0'){
			a[i] += 10;
			a[i - 1]--;
		}
	}
}

void divide_sub(char* a, char* b, char* r, int index){
	while(a[index] > '0'){
		minus(a + index, b);
		r[index]++;
	}
	r[index] += '0';
}

void divide(char* a, char* b, char* r){
	int index = 0;
	int digit = strlen(a) - strlen(b);
	
	while(index <= digit)
		divide_sub(a, b, r, index++);
		
	r[index] = '\0';
	
	if(r[0] == '\0') { r[0] = '0'; r[1] = '\0'; }
}

int main(void){
	int number_pos = 0, res_pos = 0;
	char number[1001];
	char divide_num[1001];
	char result_num[1001];
	
	memset(number, 0, 1001);
	memset(divide_num, 0, 1001);
	memset(result_num, 0, 1001);
	
	memset(number, 0, sizeof(number));
	char ans[100];
	
	scanf("%s %s", number, divide_num);
	divide(number, divide_num, result_num);
	
	while(number[number_pos] == '0' && number[number_pos + 1] != '\0') number_pos++;
	while(result_num[res_pos] == '0' && result_num[res_pos + 1] != '\0') res_pos++;
	
	printf("%s\n%s", result_num + res_pos, number + number_pos);
	return 0;
}
