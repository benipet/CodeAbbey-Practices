#include <stdio.h>
#include <stdlib.h>


typedef struct _CASES cases;


cases* init_container(int N);
int input_cases(cases* container, int size);
void display_sums(cases* container, int size);

struct _CASES {
	int num1;
	int num2;
};



int main(void) {
	int size = 3;
	int i = 0;
	cases* coll = init_container(size);

	size = input_cases(coll, size);
	display_sums(coll, size);
	

	return 0;
}

cases* init_container(int N) {
	cases* container = (cases*)malloc(sizeof(cases) * N);
	return container;

}

int input_cases(cases* container, int size) {
	int i = 0;
	size = size - 1;

	printf("Please enter the cases of the number pairs!\n");
	for (i;i <= size; i++) {
		printf("Input pair %d: ", i + 1);
		scanf_s("%d %d", &container[i].num1, &container[i].num2);

	}
	return size;
}

void display_sums(cases* container, int size) {
	int i = 0;

	for (i; i <= size; i++)
	{
		printf("%d ", container[i].num1 + container[i].num2);
	}

}