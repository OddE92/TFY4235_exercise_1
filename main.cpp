#include "class_Koch-Fractal.h"
#include <stdio.h>
#include <iomanip>
#include <ctime>

#include <mkl_lapack.h>

using std::cout; using std::cin; using std::endl; using std::vector;

int main() {
	int n;
	long long int numGripPoints = 0;

	char cont;

	double duration;

	/**** LAPACK DPOSV INPUTS ****/
	vector<double> A, lambda_I; //A is the LHS matrix, lamdba_I signifies lambda*I were I=Identity matrix
	char UPLO = 'U';
	int NRHS;	//Number of columns in the RHS matrix, := numGridPoints
	int LDA;	//Leading Dimension of the array A, = numGridPoints for my use
	int LDB;	//Leading Dimension of the array B, = numGridPoints for my use
	int INFO;	//Output: = 0 for success, < 0 if i-th element had illegal value, > 0 couldn't complete.
	/**** END OF LAPACK IN/OUTPUTS ****/

	points testPoint;

	std::clock_t start;

	do {

		cout << "Set fractal level n: ";
		cin >> n;
		cout << endl;
		if (n > -1) {
			KochFractal testFractal(n);

			cout << "Grid points: " << testFractal.numGridPoints << endl;
			cout << "Circumference: " << testFractal.circumference << endl << endl;

			A.reserve(pow((testFractal.numGridPoints) / 2, 2));
			lambda_I.reserve(pow((testFractal.numGridPoints) / 2, 2));

			testFractal.create_grid_n(n + 1);

			start = std::clock();
			testFractal.write_to_file();
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

			cout << endl << "Fractal has been written to KochFractal.dat in " << duration << " seconds" << endl << endl;
		}

		if (n > -1) {
			//Create array A and lambda_I
		}
	} while (n > -1);//End while test

	system("PAUSE");
	
	return(0);
}//End main


/**** TEST PARTS ****/
/* Test GLS matrix, set and write
for (int i = 0; i < 4; i++) {
for (int j = 0; j < 4; j++) {
gsl_matrix_set(testMat, i, j, (double)i*j);
}
}

for (int i = 0; i < 4; i++) {
for (int j = 0; j < 4; j++) {
cout << std::setw(3) << gsl_matrix_get(testMat, i, j);
}
cout << endl;
}
*/
/* test if a point is inside, outside or on the border
do {
cout << "Choose x and y coordinates: x = ";
cin >> testPoint.x;
cout << "y = ";
cin >> testPoint.y;
cout << endl;
cout << "Test point cn: " << testFractal.test_point_position_cn(testPoint) << endl;
cout << "Test point wn: " << testFractal.test_point_position_wn(testPoint) << endl;
cout << endl << "Try one more point? (y/n): ";
cin >> cont;
cout << endl;
} while (cont == 'y');
*/