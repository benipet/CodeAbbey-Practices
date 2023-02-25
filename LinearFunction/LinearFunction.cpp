/*
	#10 - The Linear Function
	Code Abbey
*/

#include<stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct _point point;
typedef struct _position pos;

struct _point {
	int x;
	int y;
};

struct _position {
	point* position;
	int slope;
	int step;
};

//Function initialize a point
point* init_point(int x, int y);

//Calculate the slope between two points
int calc_slope(point* p1, point* p2);

//Get best position
pos* get_bestPos(point* p1, point* p2, int slope);

//find_b
int find_b(pos* position);


int main(void) {
	point* p1 = init_point(0,0);
	point* p2 = init_point(1,1);

	//calculate the slope
	int slope = calc_slope(p1, p2);
	//get the closest point to the y-axis
	pos* closeY = get_bestPos(p1, p2, slope);
	//find the b value
	int b = find_b(closeY);
	
	printf("a: %d\nb: %d\n", slope, b);
	printf("f(x)=%dx+%d\n", slope, b);
	


	free(p1);
	free(p2);
	free(closeY);
	return 0;
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
	int y=position->position->y;
	if (currX == 0) {
		return y=position->position->y;
	}
	
	while (currX != 0) {
		y = y + position->step * position->slope;
		currX = currX+position->step;
	}


	return y;

}