#include "class_Koch-Fractal.h"

/**** TESTS IF A POINT IS INSIDE, OUTSIDE OR ON THE BORDER ****/
/*
Returns:	-1	- Point is outside
			0	- Point is on the border
			1	- Point is inside
*/
int KochFractal::test_point_position_cn(points testPoint) {
	int cn = 0;

	for (int i = 0; i < vectPoints.size() - 1; i++) {

						//Check if point is equal to a fractal point
		if ((testPoint.x == vectPoints[i].x) && (testPoint.y == vectPoints[i].y)) {
			return 0;	
		} else if (		//Check if crossing
			(vectPoints[i].x > testPoint.x) && (
				//Check downwards, exclude start point
					(testPoint.y < vectPoints[i].y && testPoint.y >= vectPoints[i + 1].y) ||
				//Check upwards, exclude end point
					(testPoint.y >= vectPoints[i].y && testPoint.y < vectPoints[i + 1].y) 
				)
			) {
			cn++;
		} else if (		//Check if point is y border
			(vectPoints[i].x == testPoint.x) && (
				(testPoint.y < vectPoints[i].y && testPoint.y > vectPoints[i + 1].y) ||
				(testPoint.y > vectPoints[i].y && testPoint.y < vectPoints[i + 1].y) 
				)
			){
			return 0;
		} else if (		//Check if point is x border
			(vectPoints[i].y == testPoint.y) && (
				(testPoint.x < vectPoints[i].x && testPoint.x > vectPoints[i + 1].x) ||
				(testPoint.x > vectPoints[i].x && testPoint.x < vectPoints[i + 1].x)
				)
			) {
			return 0;
		}//End if
	}//End for i

	if (cn % 2) {		//Returns 1 (inside) when cn is NOT divisible by 2
		return 1;
	}
	else {
		return -1;
	}
}
/**** END CROSSING NUMBER TEST****/
/**** WINDING NUMBER TEST ****/
/* Same returns as CN test */
int KochFractal::test_point_position_wn(points testPoint) {
	int wn = 0;
	for (int i = 0; i < vectPoints.size() - 1; i++) {
		if ((testPoint.x == vectPoints[i].x) && (testPoint.y == vectPoints[i].y)) {
			return 0;
		} else if (		//Check if crossing down
			(vectPoints[i].x > testPoint.x) && (
				(testPoint.y <= vectPoints[i].y && testPoint.y > vectPoints[i + 1].y) ||
				(testPoint.y < vectPoints[i].y && testPoint.y >= vectPoints[i + 1].y)
				)
			) {
			wn++;
		} else if (		//Check if crossing up
			(vectPoints[i].x > testPoint.x) && (
				(testPoint.y >= vectPoints[i].y && testPoint.y < vectPoints[i + 1].y) ||
				(testPoint.y > vectPoints[i].y && testPoint.y <= vectPoints[i + 1].y)
				)
			) {
			wn--;
		} else if (		//Check if point is on border
			(vectPoints[i].x == testPoint.x) && (
				(testPoint.y < vectPoints[i].y && testPoint.y > vectPoints[i + 1].y) ||
				(testPoint.y > vectPoints[i].y && testPoint.y < vectPoints[i + 1].y)
				)
			) {
			return 0;
		} else if (		//Check if point is x border
			(vectPoints[i].y == testPoint.y) && (
				(testPoint.x < vectPoints[i].x && testPoint.x > vectPoints[i + 1].x) ||
				(testPoint.x > vectPoints[i].x && testPoint.x < vectPoints[i + 1].x)
				)
			) {
			return 0;
		}//End if
	}//End for i

	if (wn == 0) {
		return -1;
	}
	else {
		return 1;
	}
	return 0;
}