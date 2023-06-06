#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, curx, cury, next = 0, count = 0, max = 1, cnum = 0;
	int num, idxx = 0, idxy = 0;
	int** arr = NULL;

	// 위쪽, 오른쪽, 아래쪽, 왼쪽 순으로 좌표가 이동 그에 맞게 변수 저장
	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	scanf("%d", &n);
	scanf("%d", &num);
	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)calloc(n, sizeof(int));

	curx = n / 2;
	cury = n / 2;

	for (int i = 0; i < n * n; i++) {
		arr[cury][curx] = i + 1;
		
		if (num == i + 1) {
			idxx = curx + 1;
			idxy = cury + 1;
		}

		// 방향 이동
		cury += dy[next % 4];
		curx += dx[next % 4];
		count++;

		// 방향 이동이 최대값 만큼 이동하면 방향 전환
		if (count == max) {
			next++;
			count = 0;
			cnum++;
		}
		
		// 전환이 2번되면 이동 거리가 1씩 늘어남
		if (cnum == 2) {
			max++;
			cnum = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("%d %d\n", idxy, idxx);

	return 0;
}
