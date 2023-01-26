/*

Problem 4 - Minimum of Two
Code Abbey 

*/

#include <stdio.h>
#include <stdlib.h>

//Returns the smaller the smaller number
int get_min(int x, int y);
//Initialize the container
int* init_container(int size);
//Input the number cases
void input_cases(int* container, int size);
//Display the minimum results
void display_min(int* container, int size);
//Determine the number of desired case
int get_caseNumber(void);

int main(void)
{
	int N;			//the number of cases
	int size;		//the size of the container

	//User initialized N
	N = get_caseNumber();
	size = N - 1;
	//Initialize the container
	int* container = init_container(size);
	//Call the input cases function
	input_cases(container, size);
	//display cases
	display_min(container, size);

	free(container);
	return 0;
}


int* init_container(int size) {
	int* container = (int*)malloc(sizeof(int) * size);
	return container;
}


int get_caseNumber(void) {
	int N;
	printf ("Enter how many case you want!\n");
	scanf_s("%d", &N);
	return N;

}

void display_min(int* container, int size) {
	int i;

	for (i = 0; i <= size; i++) {
		printf("%d ", container[i]);

	}
}

void input_cases(int* container, int size) {
	int i;
	int x, y;
	printf("Please enter two numbers!:\n");
	for (i = 0; i <= size; i++) {
		printf("(%d): ", i + 1);
		scanf_s("%d %d", &x, &y);
		container[i] = get_min(x, y);
	}
}




int get_min(int x, int y)
{
	return x < y ?  x : y;
}