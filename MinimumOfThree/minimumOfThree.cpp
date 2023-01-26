/*

Problem 5 - Minimum of Three
Code Abbey

*/

#include <stdio.h>
#include <stdlib.h>

//Determine the number of desired case
int get_caseNumber(void);
//Initialize the container
int* init_container(int size);
//Input the number cases
void input_cases(int* container, int size);
//Returns the smaller number
int get_min(int x, int y);
//Display the minimum results
void display_min(int* container, int size);

int main(void)
{
	int N=0;			//the number of cases
	int size=0;		//the size of the container

	//User initialized N
	N = get_caseNumber();
	size = N - 1;
	//Initialize the container
	int* container = init_container(size);
	//Call the input cases function
	input_cases(container, size);
	//display cases
	display_min(container, size);

	return 0; 
}

int get_caseNumber(void) {
	int N;
	printf("Enter how many case you want!\n");
	scanf_s("%d", &N);
	return N;

}

int* init_container(int size) {
	int* container = (int*)malloc(sizeof(int) * size);
	return container;
}

void input_cases(int* container, int size) {
	int i;
	int x, y, z;
	printf("Please enter three numbers!:\n");
	for (i = 0; i <= size; i++) {
		printf("(%d): ", i + 1);
		scanf_s("%d %d %d", &x, &y, &z);
		container[i] = get_min(x, y);
		container[i] = get_min(container[i], z);
	}
}

int get_min(int x, int y)
{
	return x < y ? x : y;
}

void display_min(int* container, int size) {
	int i;

	for (i = 0; i <= size; i++) {
		printf("%d ", container[i]);

	}
}
