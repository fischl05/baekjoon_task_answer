#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m, sum = 0, out = 0;
	int* arr = NULL;

	scanf("%d %d", &n, &m);

	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	int start = 1; // 인출금액 1원부터 시작
	int last = sum;  //최대 인출금액은 입력된 사용할 돈의 합
	int cur_money; //현재 가진 돈

	while (start <= last) { //이분탐색 시작
		int check = 1; //현재 인출금액이 잘못된 것인지 확인
		int middle = (start + last) / 2; //전체 돈의 중간값 저장
		int cnt = 1; //인출 횟수를 1로 초기화

		cur_money = middle; //현재 돈을 middle로 초기화
		for (int i = 0; i < n; i++) { //전체 배열 검사
			if (arr[i] > middle) { //인출한 돈보다 하루 사용할 돈이 더 많으면 break후 넘김
				check = 0;
				break;
			}
			if (arr[i] > cur_money) { //하루 사용할 금액이 현재 돈보다 많으면 용돈 재인출 후 인출 횟수 증가
				cur_money = middle;
				cnt++;
			}
			cur_money -= arr[i]; //돈 사용
		}
		if (check == 0 || cnt > m) start = middle + 1; //인출 횟수가 많거나 사용한 돈이 더 많으면 돈을 더많이 인출
		else { //인출한 돈으로 사용가능하면 값 저장후 돈을 더 적게 하여 다시 검사 -> 최소값을 찾기 위한 것
			out = middle;
			last = middle - 1;
		}
	}

	printf("%d", out);

	free(arr);
	return 0;
}