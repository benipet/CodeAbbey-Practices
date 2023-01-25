#include <stdio.h>
#include <stdlib.h>

int define_caseN(void);
int* init_sumList(int size);
void input_cases(int* coll, int size);
void display_sums(int* coll, int size);

int main(void) {
	int N=0;
	int i;
	int size;
	

	N = define_caseN();
	size = N - 1;
	int* sums = init_sumList(size);
	input_cases(sums, size);
	display_sums(sums, size);
	
	

	return 0;
}

int define_caseN(void) {
	int N;
	printf("Please Enter the N cases!\n");
	scanf_s("%d", &N);
	return N;

}

int* init_sumList(int size) {
	int* container = (int*)malloc(sizeof(int) * size);
	return container;

}

void input_cases(int* coll, int size) {
	int i;
	int num1, num2;

	printf("Please enter the pairs!\n");
	for (i = 0; i <= size; i++) {
		printf("Enter pair %d: ", i + 1);
		scanf_s("%d %d", &num1, &num2);
		coll[i] = num1 + num2;
	}
}

void display_sums(int* coll, int size) {
	int i = 0;

	for (i; i <= size; i++) {
		printf("%d ", coll[i]);
	}

}