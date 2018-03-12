#include "class_Koch-Fractal.h"

KochFractal::KochFractal(int n) : n(n) {
	circumference = Generate_circumference_length();
	numGridPoints = Generate_number_of_grid_points();

	vectPoints.resize(circumference);

	if (numGridPoints >= 0) {
		Generate_Fractal();
	}

}

KochFractal::~KochFractal() {

}





