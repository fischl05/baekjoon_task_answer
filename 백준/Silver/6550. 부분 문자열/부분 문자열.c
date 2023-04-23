#include <stdio.h>
#include <string.h>

char sstr[100001];
char tstr[100001];

int main(void) {
	while (scanf("%s %s", sstr, tstr) != EOF) {
		int len1 = strlen(sstr);
		int len2 = strlen(tstr);
		int cnt = 0, idx = 0;
		if (len2 < len1) printf("No\n");
		else {
			for (int i = 0; i < len1; i++) {
				int j = 0;
				for (j = idx; j < len2; j++)
					if (sstr[i] == tstr[j]) {
						cnt++;
						idx = j + 1;
						break;
					}
				if (j >= len2) break;
			}

			if (cnt >= len1) printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}