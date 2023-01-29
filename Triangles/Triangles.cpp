#include <stdio.h>

/*
	#9 Problem: Triangles
	Code Abbey
*/

int isTriangle(int a, int b, int c);

int main(void) {
	int a, b, c;
	printf("Please enter the sides of the triangle\n");
	scanf_s("%d %d %d", &a, &b, &c);
	printf("%d", isTriangle(a, b, c));
	
	return 0;
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