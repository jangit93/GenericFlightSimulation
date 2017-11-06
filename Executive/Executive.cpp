#include"readInData.h"
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

		readInData *test = new readInData;

		//MatrixXd CL = test->readInTable("CL.txt");
		Float64  mass		= test->readInParameter("mass", "Aircraft.txt");
		Float64  I_x		= test->readInParameter("I_X", "Aircraft.txt");
		Float64	 I_y		= test->readInParameter("I_Y", "Aircraft.txt");
		Float64  I_z		= test->readInParameter("I_Z", "Aircraft.txt");
		Float64  I_zx		= test->readInParameter("I_zx", "Aircraft.txt");
		Float64  wingarea	= test->readInParameter("wing_area", "Aircraft.txt");
		Float64  wingspan	= test->readInParameter("wing_span", "Aircraft.txt");
		Float64  MAC		= test->readInParameter("MAC", "Aircraft.txt");
		Float64  X_CG		= test->readInParameter("X_CG", "Aircraft.txt");
		Float64  Y_CG		= test->readInParameter("Y_CG", "Aircraft.txt");
		Float64  Z_CG		= test->readInParameter("Z_CG", "Aircraft.txt");
		
		
	LinearInterpolation *Interp = new LinearInterpolation;
	Atmopshere *Atmo			= new Atmopshere;

	Atmo->initAtmosphere();
	Atmo->updateAtmosphere(1);

	typedef MatrixXd matrix;



	time1 += clock() - tstart;     // end
	time1 = time1 / CLOCKS_PER_SEC;  // rescale to seconds

	cout << "Simulationszeit = " << time1 << " sec." << endl;

	system("Pause");

}

