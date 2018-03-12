#include "class_Koch-Fractal.h"
#include <stdio.h>

using std::cout; using std::cin; using std::endl;

int main() {
	int n = 0;
	long long int numGripPoints = 0;

	while (n > -1) {

		cout << "Set fractal level n: ";
		cin >> n;
		cout << endl;

		KochFractal testFractal(n);

		cout << "Grid points: " << testFractal.numGridPoints << endl;
		cout << "Circumference: " << testFractal.circumference << endl << endl;
	}//End while test

	system("PAUSE");
	
	return(0);
}//End main