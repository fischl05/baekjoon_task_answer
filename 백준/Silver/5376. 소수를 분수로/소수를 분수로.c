#include <stdio.h>
#include <stdlib.h>

long long int lcm(long long int a, long long int b) {
	if (a % b == 0) return b;
	else {
		return lcm(b, a % b);
	}
}

int main(void) {
	int n;
	
	scanf("%d", &n);

	while (n--) {
		long long son = 0, mother = 1;
		long long int max = 0, min = 0;
		int cnt = 0, i;
		int num = 0;
		char str[101] = { 0 };

		scanf("%s", str);

		int check = 0;
		for (i = 0; i < 101; i++) {
			if (str[i] == 0) break;
			if (check > 0) cnt++;
			else {
				if (str[i] >= '0' && str[i] <= '9') {
					num *= 10;
					num += str[i] - '0';
				}
			}
	
			if (str[i] >= '0' && str[i] <= '9') {
				son *= 10;
				son += str[i] - '0';
			}

			if (str[i] == '(') check = i;
			else if (str[i] == ')') break;
		}

		if (check == 0) {
			for (int j = 0; j < i - 2; j++) {
				mother *= 10;
			}
			son = atoi(str + 2);
			max = mother > son ? mother : son;
			min = mother > son ? son : mother;
			long long int a = lcm(max, min);
			mother /= a;
			son /= a;
			printf("%lld/%lld\n", son, mother);
		}
		else {
			mother = 9;
			for (int j = 1; j < cnt - 1; j++) {
				mother *= 10;
				mother += 9;
			}
			for (int j = 1; j < i - cnt - 1; j++) {
				mother *= 10;
			}
			son -= num;
			max = mother > son ? mother : son;
			min = mother > son ? son : mother;
			long long int a = lcm(max, min);
			mother /= a;
			son /= a;
			printf("%lld/%lld\n", son, mother);
		}
	}

	return 0;
}