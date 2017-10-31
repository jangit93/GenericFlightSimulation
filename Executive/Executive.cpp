#include"readInTables.h"
#include"LinearInterpolation.h"
#include"Atmosphere.h"
#include"LogData.h"
#include<Map>
#include<math.h>
#include <time.h> 

int main(int argv, char* argc[])
{
	double time1 = 0.0, tstart;      // time measurment variable

		tstart = clock();              // start 

	readInTables *readIn		= new readInTables;
	LinearInterpolation *Interp = new LinearInterpolation;
	Atmopshere *Atmo			= new Atmopshere;

	Atmo->initAtmosphere();
	Atmo->updateAtmosphere(1);

	typedef MatrixXd matrix;

	matrix CL;
	matrix CD;
	matrix AOA;
	matrix Mach;


	CL		= readIn->readInTable("CL.txt");
	CD		= readIn->readInTable("CD.txt");
	AOA		= readIn->readInVector("AoA.txt");
	Mach	= readIn->readInVector("Ma.txt");

	Float64 CA = Interp->biLinearInterpolation(AOA,
											   Mach,
											   CL,
											   2,
											   0.31);

	Float64 CW = Interp->biLinearInterpolation(AOA,
											   Mach,
											   CD,
											   2,
											    0.31);

	std::cout << "Aufriebsbeiwert: " << CA << std::endl;
	std::cout << '\n' << std::endl;
	std::cout << "Widerstandsbeiwert: " << CW << std::endl;
	std::cout << '\n' << std::endl;


	time1 += clock() - tstart;     // end
	time1 = time1 / CLOCKS_PER_SEC;  // rescale to seconds

	cout << "Simulationszeit = " << time1 << " sec." << endl;

	system("Pause");

}

