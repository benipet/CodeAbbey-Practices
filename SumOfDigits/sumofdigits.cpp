#include <stdio.h>
#include <stdlib.h>

/*code abbey*/
/*Sum Of Digits*/

int sumOfDigit(int a, int b, int c);
int* test(int t);

int main(void) {
	FILE* fp;
	int i=0;
	int t = 2;
	int* tests=0;

	fopen_s(&fp, "test.txt", "w");

	printf("Please enter how many test you want: ");
	scanf_s("%d", &t);

	tests = test(t);
	
	for (i = 0; i < t; i++) {
		printf("test %d->%d\n", i+1, *(tests + i));
		fprintf_s(fp, "test %d->%d\n", i+1, *(tests+i));
	}

	free(tests);
	fclose(fp);
	return 0;
}

int* test(int t) {
	int* results = (int*)calloc(t, sizeof(int));
	int i = 0;
	int a, b, c;

	for (i; i < t; i++) {
		printf("Enter the three tested number with space separated (a b c): ");
		scanf_s("%d %d %d", &a, &b, &c);
		*(results + i) = sumOfDigit(a, b, c);
	}

	return results;
}


int sumOfDigit(int a, int b, int c) {

	int number = a * b + c;
	int sdig=0;

	while (number >= 1) {
		sdig = sdig + (number % 10);
		number /= 10;
	}

	return sdig;
}