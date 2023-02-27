/*
	#10 - The Linear Function
	Code Abbey
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct _point point;
typedef struct _position pos;
typedef struct _output out;

struct _point {
	int x;
	int y;
};

struct _position {
	point* position;
	int slope;
	int step;
};

struct _output {
	int slope;
	int b;
};

//Function initialize a point
point* init_point(int x, int y);

//Calculate the slope between two points
int calc_slope(point* p1, point* p2);

//Get best position
pos* get_bestPos(point* p1, point* p2, int slope);

//find_b
int find_b(pos* position);

//Get the demanded input cases
int get_inputCases(void);

//Input the new coordinate
out* input_coordinates(int lineCases);

//Display Results
void display_results(out* resultList, int size);

int main(void) {
	//declaration of the input cases variable
	int n;
	//call the function what user inputted number of inputted line coordinate cases
	n = get_inputCases();
	//input the case coordinates, and returns the result
	out* result = input_coordinates(n);
	//display the results
	display_results(result, n);
	//free the memory from result
	free(result);

	return 0;
}

int get_inputCases(void) {
	int x;
	printf("Enter the case numbers!\n");
	scanf_s("%d", &x);
	return x;


}

out* input_coordinates(int lineCases) {
	int x1, y1, x2, y2;
	out* container = (out*)calloc(lineCases, sizeof(out));
	int i = 0;
	int slope;
	point* p1;
	point* p2;
	pos* bestPos;


	printf("Enter x1 y1 x2 y2 coordinates\n");
	for (i; i < lineCases; i++) {
		printf("%d->", i + 1);
		scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
		p1 = init_point(x1, y1);
		p2 = init_point(x2, y2);
		slope = calc_slope(p1, p2);
		bestPos = get_bestPos(p1, p2, slope);
		int b = find_b(bestPos);
		container[i].b = b;
		container[i].slope = slope;

		free(p1);
		free(p2);
		free(bestPos);
	}

	return container;
}

void display_results(out* resultList, int size) {
	int i = 0;
	for (i; i < size; i++)
	{
		printf("(%d %d) ", resultList[i].slope, resultList[i].b);
	}
}

point* init_point(int x, int y) {
	point* node = (point*)malloc(sizeof(point));
	node->x = x;
	node->y = y;
	return node;

}

int calc_slope(point* p1, point* p2) {
	int DY = p2->y - p1->y;
	int DX = p2->x - p1->x;
	return DY / DX;

}

pos* get_bestPos(point* p1, point* p2, int slope) {
	pos* best = (pos*)malloc(sizeof(pos));

	int x1 = abs(p1->x);
	int x2 = abs(p2->x);

	if (x1 < x2) {
		best->position = p1;
	}
	else {
		best->position = p2;
	}

	if (best->position->x < 0) {
		best->step = 1;
	}
	else
		best->step = -1;

	best->slope = slope;

	return best;

}

int find_b(pos* position) {
	int currX = position->position->x;
	int y = position->position->y;
	if (currX == 0) {
		return y = position->position->y;
	}

	while (currX != 0) {
		y = y + position->step * position->slope;
		currX = currX + position->step;
	}


	return y;

}