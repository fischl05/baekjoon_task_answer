#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start_time;
	int end_time;
}TIME;

int compare_item(const void* a, const void* b) {
	const TIME* p1 = a, * p2 = b;
	if (p1->end_time == p2->end_time) return p1->start_time > p2->start_time;
	return p1->end_time > p2->end_time;
}

int main(void) {
	int n, out = 0;

	scanf("%d", &n);

	TIME* time = (TIME*)calloc(sizeof(TIME), n);
	TIME* time_buf = (TIME*)calloc(sizeof(TIME), n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &time[i].start_time, &time[i].end_time);

	qsort((TIME*)time, n, sizeof(TIME), compare_item);

	//for (int i = 0; i < n; i++)
	//	printf("%d %d\n", time[i].start_time, time[i].end_time);

	time_buf[0] = time[0];
	int i = 1;
	for(i = 1 ; i < n ; i++){
		if (time[i].start_time >= time_buf[out].end_time) {
			if(out + 1 < n) time_buf[out + 1] = time[i];
			out++;
			if (out >= n) break;
		}
	}
	printf("%d", out + 1);

	free(time);
	free(time_buf);
	return 0;
}