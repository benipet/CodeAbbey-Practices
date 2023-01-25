#include <stdio.h>

int* init_container(int size);

int main(void) {
	int sum;
	int N;
	int cases;
	int i;

	printf("Please enter how many cases you wish!");
	scanf_s("%d", &N);
	N = N - 1;
	sum = 0;

	for (i = 0; i <= N; i++) {
		printf("case %d: ", i+1);
		scanf_s("%d", &cases);
		sum += cases;
	}

	printf("%d", sum);

	return 0;
}