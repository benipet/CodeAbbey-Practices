#include <stdio.h>

/*
	#9 Problem: Triangles
	Code Abbey
*/

int isTriangle(int a, int b, int c);
int input_triplets(void);

int main(void) {
	int N;
	int i;
	int a, b, c;

	N = input_triplets();

	if (N > 0) {
		for (i=1; i <= N; i++) {
			printf("Please enter the sides of the triangle\n");
			scanf_s("%d %d %d", &a, &b, &c);
			printf("%d\n", isTriangle(a, b, c));

		}
		
	}

	
	
	
	return 0;
}

int input_triplets(void) {
	int N;

	printf("Please enter how many triplets you want!\n");
	scanf_s("%d", &N);

	return N;

}

int isTriangle(int a, int b, int c) {
	if (a + b < c)
		return 0;
	else if (a + c < b)
		return 0;
	else if (c + b < a)
		return 0;
	else
		return 1;

}