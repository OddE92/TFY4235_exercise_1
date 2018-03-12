#include "class_Koch-Fractal.h"
#include <cmath>

using std::cout;
using std::endl;

/**** GENERATES CIRCUMFERENCE LENGTH FOR nTH ITERATION ****/
long long int KochFractal::Generate_circumference_length(){
	return((int)pow(2, 3*n+2));
}//End Generate_Circumference_length

/**** GENERATES NUMBER OF GRID POINTS FOR nTH ITERATION ****/
/**** The number is given on the form AxA where A is returned ****/
long long int KochFractal::Generate_number_of_grid_points() {

	long long int GridPoints = -1;

	if (n == 0) {
		GridPoints = 2;
	}
	else if (n >= 1) {
		GridPoints = 6;

		for (int i = 1; i < n; i++) {
			GridPoints = 4 * GridPoints + 2;
		}//End For
	}
	else {
		cout << "'n' is not valid." << endl;
	}//End if

	return(GridPoints);
}//End Generate_number_of_grid_points

 /**** GENERATES THE COMPLETE FRACTAL ****/
void KochFractal::Generate_Fractal() {
	int i, j, deltaVect_j;

	Generate_Square();

	for (i = 1; i <= n; i++) {
		deltaVect_j = Generate_deltaVect(i-1);

		for (j = 0; j < circumference - 1; j += deltaVect_j) {
			Generate_Segment(j, i);
		}
	}

}

/**** GENERATES THE BASE SQUARE ****/
void KochFractal::Generate_Square() {
	int deltaVect = circumference / 4;			//Finds the step between the base square points in the vector
	int deltaGrid = Generate_deltaGrid(n);

	vectPoints[0].x = 0;
	vectPoints[0].y = 0;
	vectPoints[0].dir = 'r';

	vectPoints[deltaVect].x = deltaGrid;
	vectPoints[deltaVect].y = 0;
	vectPoints[deltaVect].dir = 'd';

	vectPoints[2*deltaVect].x = deltaGrid;
	vectPoints[2*deltaVect].y = -deltaGrid;
	vectPoints[2*deltaVect].dir = 'l';

	vectPoints[3*deltaVect].x = 0;
	vectPoints[3*deltaVect].y = -deltaGrid;
	vectPoints[3*deltaVect].dir = 'r';
}//End Generate_Square

/**** GENERATES THE SEGMENT FOR THE kTH LEVEL ****/
void KochFractal::Generate_Segment(int vectStartPos, int k) {
	int deltaGrid = Generate_deltaGrid(n-k);
	int deltaVect = Generate_deltaVect(k);
	int i;

	switch (vectPoints[vectStartPos].dir){
	case 'r':
		for (i = 0; i < 7; i++) {
			vectStartPos = Generate_next_segment_point_right(vectStartPos, deltaVect, deltaGrid, i);
		}
	break;
	case 'l':
		for (i = 0; i < 7; i++) {
			vectStartPos = Generate_next_segment_point_left(vectStartPos, deltaVect, deltaGrid, i);
		}
	break;
	case 'u':
		for (i = 0; i < 7; i++) {
			vectStartPos = Generate_next_segment_point_up(vectStartPos, deltaVect, deltaGrid, i);
		}
	break;
	case 'd':
		for (i = 0; i < 7; i++) {
			vectStartPos = Generate_next_segment_point_down(vectStartPos, deltaVect, deltaGrid, i);
		}
	break;
	default:
		break;
	}
}

/**** GENERATES THE STEP IN THE VECTOR FOR THE kTH LEVEL ****/
int KochFractal::Generate_deltaVect(int k) {
	return(circumference / (int)pow(2, 3 * k + 2));
}

/**** GENERATES THE STEP BETWEEN GRIDPOINTS FOR THE kTH LEVEL ****/
int KochFractal::Generate_deltaGrid(int k) {
	
	int deltaGrid = pow(4, k);

	return(deltaGrid);
}

/**** GENERATES THE NEXT POINT AND RETURNS THE NEXT vectStartPos ****/
/**** There are four different version, 
one for each direction of the segment****/
int KochFractal::Generate_next_segment_point_right(int vectStartPos, int deltaVect, int deltaGrid, int i) {
	switch (i) {
	case 0:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
	break;
	case 1: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
	break;
	case 2: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
	break;
	case 3: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
	break;
	case 4: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
	break;
	case 5: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
	break;
	case 6: 
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
	break;
	default: return(vectStartPos);
	}
	return(vectStartPos + deltaVect);
}//End Generate_next_segment_point_right

int KochFractal::Generate_next_segment_point_left(int vectStartPos, int deltaVect, int deltaGrid, int i) {
	switch (i) {
	case 0:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
		break;
	case 1:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 2:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
		break;
	case 3:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
		break;
	case 4:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 5:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
		break;
	case 6:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	default: return(vectStartPos);
	}
	return(vectStartPos + deltaVect);
}//End Generate_next_segment_point_left

int KochFractal::Generate_next_segment_point_up(int vectStartPos, int deltaVect, int deltaGrid, int i) {
	switch (i) {
	case 0:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 1:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
		break;
	case 2:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
		break;
	case 3:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
		break;
	case 4:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
		break;
	case 5:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y + deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 6:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'u';
		break;
	default: return(vectStartPos);
	}
	return(vectStartPos + deltaVect);
}//End Generate_next_segment_point_up

int KochFractal::Generate_next_segment_point_down(int vectStartPos, int deltaVect, int deltaGrid, int i) {
	switch (i) {
	case 0:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
		break;
	case 1:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
		break;
	case 2:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 3:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'l';
		break;
	case 4:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x - deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
		break;
	case 5:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y - deltaGrid;
		vectPoints[vectStartPos + deltaVect].dir = 'r';
		break;
	case 6:
		vectPoints[vectStartPos + deltaVect].x = vectPoints[vectStartPos].x + deltaGrid;
		vectPoints[vectStartPos + deltaVect].y = vectPoints[vectStartPos].y;
		vectPoints[vectStartPos + deltaVect].dir = 'd';
		break;
	default: return(vectStartPos);
	}
	return(vectStartPos + deltaVect);
}//End Generate_next_segment_point_down

/********** END OF NEXT POINT GENERATORS **********/
/**************************************************/