/*
	#7 - Fahrenheit to Celsius
	Code Abbey Problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // :-)
typedef struct _TEMPERATURE temp;

//This is the temperature structure what stores the records in fahrenheit and celsius

struct _TEMPERATURE {
	int fahrenheit;
	int celsius;
};

//Initialize the number of records we want to store
temp* init_recordContainer(int size);
//Calculate and returns the temperature in celsius
int get_celsius(int fahrenheit);
//Get the desired recodrds
int get_recordCases(void);
//Input the records
void input_temperatures(temp* container, int size);
//Display the temperatures
void display_tmprecords(temp* container, int size);

int main(void)
{
	int N;
	int size;

	N = get_recordCases();
	size = N - 1;
	//Allocate the container
	temp* container = init_recordContainer(size);
	//Input the records
	input_temperatures(container, size);
	//Display the records
	display_tmprecords(container, size);

	

	return 0;
}




temp* init_recordContainer(int size) {

	temp* container = (temp*)malloc(sizeof(temp) * size);
	return container;

}


int get_recordCases(void) {
	int n;
	printf("Enter the number of records!\n");
	scanf_s("%d", &n);
	return n;
}

void input_temperatures(temp* container, int size) {
	int i;
	int f;

	printf("Please enter the temperatures in fahenheit!\n");
	for (i=0; i <= size; i++) {
		printf("(%d): ", i + 1);
		scanf_s("%d", &f);
		container[i].fahrenheit = f;
		container[i].celsius = get_celsius(f);
	}

}

void display_tmprecords(temp* container, int size) {
	int i = 0;
	for (i; i <= size; i++) {
		printf("%d Fahernheit is %d Celsius\n", container[i].fahrenheit, container[i].celsius);
	}

}


int get_celsius(int fahrenheit) {
	float C = ((float)fahrenheit - 32) * 5 / 9;
	round(C);
	return (int)C;

}