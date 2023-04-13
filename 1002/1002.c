#include <stdio.h>
#include <math.h>

int main(void){
	int x1, y1, x2, y2, r1, r2;
	int n;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double d = sqrt((int)pow(x2 - x1, 2) + (int)pow(y2 - y1, 2));
		if(d == 0 && r1 == r2) printf("-1\n");
		else if(d > r1 + r2 || d < abs(r1 - r2)) printf("0\n");
		else if(d == r1 + r2 || d == abs(r1 - r2)) printf("1\n");
		else if(d > abs(r1 - r2) && d < r1 + r2) printf("2\n");
	}
	return 0;
}

