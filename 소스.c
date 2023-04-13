#include <stdio.h>
#include <string.h>

int main(void) {
    int arr[10];
    int number[51];
    int i, j, max = 0, frev_num = 10;

    memset(arr, 0, 10);
    memset(number, 0, 51);

    max = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        max += arr[i];
    }

    for (i = 0; i < 10; i++) {
        if (arr[i] > max - arr[i]) {
            if (i != 0) arr[i] = max - arr[i] + 1;
            else arr[i] = max - arr[i];
        }
    }

    max = 0;
    for (i = 0; i < 10; i++) max += arr[i];
    if (max == 0) {
        printf("0");
        return 0;
    }

    for (i = 0; i < max; i++) {
        if ((max - i) % 2) { //남아 있는 숫자의 개수가 홀수 일 때
            for (j = 0; j < 10; j++) {
                if (arr[j] > (max - i) - arr[j]) {
                    number[i] = j;
                    arr[j]--;
                    frev_num = j;
                    i++;
                    break;
                }
            }
        }
        for (j = 9; j >= 0; j--) {
            if (arr[j] && frev_num != j) {
                number[i] = j;
                arr[j]--;
                frev_num = j;
                break;
            }
        }
    }
    
    for (i = 0; i < max; i++) {
        printf("%d", number[i]);
    }

    return 0;
}