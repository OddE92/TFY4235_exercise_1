#include <iostream>
#include <fstream>

#include "class_Koch-Fractal.h"

void KochFractal::write_to_file() {
	std::ofstream outFile;

	outFile.open("KochFractal.dat", std::ofstream::out | std::ofstream::trunc);
	//outFile.open("KochFractal.bin", std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < vectPoints.size(); i++) {
		outFile << vectPoints[i].x << " " << vectPoints[i].y << '\n';
	}

	//for (auto& p : vectPoints) {
	//	outFile.write(reinterpret_cast<char*>(&p), 2 * sizeof(int));
	//}

	outFile.close();
}