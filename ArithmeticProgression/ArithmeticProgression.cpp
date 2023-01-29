#include <stdio.h>
#include <stdlib.h>

//#8 Arithmetic Progression
//Problem: CodeAbbey

//Program: Calculate the sum of members of arithmetic sequence
/*
* Input: A B N
* A - first value
* B - step size
* N - First value
* Example:
* 5 2 3
* 5 + 7 + 9 = 21
* 3 0 10
* 3 + 3 + 3...+3 = 30

*/

//Init the test case
int* init_testcase(void);
//Arithmetic Progression Function
int prog_arithmetic(int firstVal, int stepSize, int numVal);

int main(void)
{
	
	int* t = init_testcase();
	int r = prog_arithmetic(t[0], t[1], t[2]);
	printf("%d", r);
	
	free(t);

	return 0;
}

int* init_testcase(void) {
	int* container = (int*)malloc(sizeof(int) * 3);
	
	printf("Please enter the:\n A - First Value of Sequence, B - step size, N - number of first values\n");
	printf("Example: 5 2 3\n");
	scanf_s("%d %d %d", &container[0], &container[1], &container[2]);


	return container;


}

int prog_arithmetic(int firstVal, int stepSize, int numVal) {
	int i;
	int currVal = firstVal;
	int prog=0;
	

	for (i = 0; i < numVal; i++)
	{
		prog += currVal;
		currVal += stepSize;
	}

	return prog;

}