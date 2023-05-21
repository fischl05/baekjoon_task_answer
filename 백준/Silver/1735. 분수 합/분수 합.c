#include <stdio.h>

int gcm(int a, int b) {
	if (a % b == 0) return b;
	return gcm(b, a % b);
}

int main(void) {
	int son[2] = { 0 };
	int fa[2] = { 0 };
	
	int out[2] = { 0 };

	for (int i = 0; i < 2; i++)
		scanf("%d %d", &son[i], &fa[i]);
	
	out[0] = son[0] * fa[1] + son[1] * fa[0];
	out[1] = fa[0] * fa[1];

	int min = out[0] > out[1] ? out[1] : out[0];
	int max = out[0] > out[1] ? out[0] : out[1];
	
	int g_num = gcm(max, min);

	printf("%d %d", out[0] / g_num, out[1] / g_num);

	return 0;
}