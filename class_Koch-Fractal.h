#ifndef KOCH_FRACTAL
#define KOCH_FRACTAL

#include <iostream>
#include <vector>

struct points {
	int x, y;
	char dir;
};

class KochFractal {
	public:
		KochFractal (int);
		~KochFractal ();

		int circumference, numGridPoints;

		std::vector<points> vectPoints;

	private:
		int n;

		long long int Generate_circumference_length();
		long long int Generate_number_of_grid_points();

		void Generate_Fractal();
		void Generate_Square();
		void Generate_Segment(int, int);
		int Generate_deltaVect(int);
		int Generate_deltaGrid(int);
		int Generate_next_segment_point_right(int, int, int, int);
		int Generate_next_segment_point_left(int, int, int, int);
		int Generate_next_segment_point_up(int, int, int, int);
		int Generate_next_segment_point_down(int, int, int, int);

};


#endif