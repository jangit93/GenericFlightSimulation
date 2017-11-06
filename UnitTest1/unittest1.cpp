#include "stdafx.h"
#include "CppUnitTest.h"

#include"Atmosphere.h"
#include"readInData.h"
#include <C:\Users\janol\Desktop\Studium\Master_Luft und Raumfahrttechnik\2.Fachsemester\Effizient Programmieren\Programierprojekt\GenericFlightSimulation\EIGENDIR\Eigen\dense>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Atmosphere_test)
		{
			Atmopshere test;
			double rhot = 1.2264962070792322;
			Assert::AreEqual(test.updateAtmosphere(1), 1.2264962070792322);
			// TODO: Testcode hier eingeben
		}

		TEST_METHOD(readInParameter_test)
		{
			readInData test;
			
			test.setPath("../../Input/");
			Assert::AreEqual(test.readInParameter("wing_span", "Aircraft.txt") , 9.1);
			// TODO: Testcode hier eingeben
		}

		TEST_METHOD(readInTable_test)
		{
			readInData test;
			MatrixXd m(3, 3);
			m(0, 0) = -0.723;
			m(0, 1) = -0.727;
			m(0, 2) = -0.733;

			m(1, 0) = -0.449;
			m(1, 1) = -0.452;
			m(1, 2) = -0.456;

			m(2, 0) = -0.185 ;
			m(2, 1) = -0.186 ;
			m(2, 2) = -0.188;

			int counter = 0;
			test.setPath("../../Input/");

			MatrixXd check = test.readInTable("testMatrix.txt");
			
			for (int i = 0; i < 3; i++) {
				for (int i2 = 0; i2 < 3; i2++) {
					if (check(i, i2) == m(i, i2)) {
						counter = counter + 1;
					}
				}
			}
			Assert::AreEqual(counter,9);
			// TODO: Testcode hier eingeben
		}

	};
}