#include "class_Koch-Fractal.h"

KochFractal::KochFractal(int n) : n(n) {
	long long int alloc = Generate_number_of_grid_points();

	circumference = Generate_circumference_length();
	numGridPoints = Generate_number_of_grid_points();

	vectPoints.resize(circumference + 1);

	if (numGridPoints >= 0) {
		Generate_Fractal();
	}


}

KochFractal::~KochFractal() {

}





