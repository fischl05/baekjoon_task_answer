#include <stdio.h>
#include <string.h>

int arr[10000];
int idx = -1;

void push(int data) {
	arr[++idx] = data;
}

int pop(void) {
	if (idx >= 0) {
		int rdata = arr[idx];
		arr[idx--] = 0;
		return rdata;
	}
	else return -1;
}

int size(void) {
	return idx + 1;
}

int empty(void) {
	if (idx >= 0) return 0;
	else return 1;
}

int top(void) {
	if (idx >= 0) return arr[idx];
	else return -1;
}

int main(void) {
	int n;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		char str[10];
		int data;
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			scanf("%d", &data);
			push(data);
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", top());
		}
	}

	return 0;
}