#include <stdio.h>

const int LM = 500000;
int a[500005], t[500005], N, K, cnt, res;

void mSort(int s, int e) {
	if (s >= e) return;

	int m = (s + e) / 2;
	mSort(s, m);
	mSort(m + 1, e);

	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (a[i] <= a[j]) t[k++] = a[i++];
		else t[k++] = a[j++];
	}

	while (i <= m) t[k++] = a[i++];
	while (j <= e) t[k++] = a[j++];

	for (i = s; i <= e; ++i) {
		a[i] = t[i];
		if (++cnt == K) res = a[i];
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

	res = -1;
	mSort(0, N - 1);

	printf("%d\n", res);
	return 0;
}