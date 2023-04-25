#include <stdio.h>

int main(void) {
	int arr[5] = { 0 };
	int box_cnt = 0;

	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (int i = 4; i >= 0;) {
		int box = 0;
		while (box + i + 1 <= 5 && arr[i] > 0) {
			box = box + i + 1;
			arr[i]--;
		}
		int j = i - 1;
		while (j >= 0) {
			if (box + j + 1 <= 5 && arr[j] > 0) {
				box = box + j + 1;
				arr[j]--;
			}
			else j--; 
		}
		if(box > 0) box_cnt++;
		if (arr[i] == 0) i--;
	}

	printf("%d", box_cnt);

	return 0;
}