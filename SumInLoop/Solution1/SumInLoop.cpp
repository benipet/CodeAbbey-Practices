#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int* init_container(int size);

int main(void) {
	int size;
	int cases;
	int sum = 0;
	printf("Please enter the use case!");
	scanf_s("%d", &size);
	size = size - 1;
	int* arr = init_container(size);

	int i = 0;

	for (i; i <= size; i++) {
		printf("The case %d: ", i+1);
		scanf_s("%d", &cases);
		arr[i] = cases;

	}
	
	for (i = 0; i <= size; i++) {
		sum = sum + arr[i];
	}
	printf("The sum of loop: %d", sum);
	

	return 0;
}


int* init_container(int size) {
	int* container = (int*)malloc(sizeof(int)*size);
	return container;
}