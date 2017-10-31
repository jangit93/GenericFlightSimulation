#include"readInTables.h"
#include"LinearInterpolation.h"
#include<Map>
#include<math.h>



int main()
{ 
	readInTables *readIn = new readInTables;
	LinearInterpolation* Interp = new LinearInterpolation;
	
	
	typedef MatrixXd matrix;

	matrix CL;
	matrix CD;
	matrix AOA;
	matrix Mach;

	CL = readIn->readInTable("CL.txt");

	std::cout << CL << std::endl;
	std::cout << '\n' << std::endl;
	CD = readIn->readInTable("CD.txt");
	std::cout << '\n' << std::endl;
	std::cout << CD << std::endl;
	AOA = readIn->readInVector("AoA.txt");
	Mach = readIn->readInVector("Ma.txt");
	std::cout << '\n' << std::endl;
	std::cout << AOA << std::endl;
	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;
	

	Float64 CA = Interp->biLinearInterpolation(AOA,
		Mach,
		CL,
		2,
		0.31);

	std::cout << "Aufriebsbweirt: " << CA << std::endl;
	std::cout << '\n' << std::endl;
	/*VectorXd B(Map<VectorXd>(CL.data(), CL.cols()*CL.rows()));
	std::cout << B << std::endl;
	std::cout << '\n' << std::endl;
	std::cout << '\n' << std::endl;*/
	system("Pause");

}

