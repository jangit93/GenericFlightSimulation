#ifndef __Atmopshere
#endif	__Atmopshere

#define __Atmopshere

#include <math.h>
#include <iostream>
#include"Constants.h"

typedef double Float64;

class Atmopshere
{
public:

	Atmopshere();

	~Atmopshere();

	void	initAtmosphere();

	void	updateAtmosphere(Float64 Altitude);

private:
	Float64	Temperature;	// [K]
	Float64 Pressure;       //[Pa]
	Float64	rho;			//[Kg / m³]
	Float64 speedOfSound;   //[m / s]
	


};
