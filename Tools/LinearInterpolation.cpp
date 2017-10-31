#include "LinearInterpolation.h"

LinearInterpolation::LinearInterpolation()
{
}

LinearInterpolation::~LinearInterpolation()
{
}

VectorXd LinearInterpolation::loadTable(MatrixXd)
{
	return VectorXd();
}

Float64 LinearInterpolation::searchIndex(VectorXd Vector,
										 Float64 Value)
{
	Int32 index = 0;

	if (Value >= Vector(index)) {
		while (index < Vector.size() && Value >= Vector(index)) {
			index = index + 1;
		}
		index = index - 1;
	}
	else {
		while (Value < Vector(index) && index >0) {
			index = index - 1;
		}
	}
	return index;
}

Float64 LinearInterpolation::biLinearInterpolation(VectorXd Vector1,
												   VectorXd Vector2,
												   MatrixXd Table,
												   Float64 Value1,
												   Float64 Value2)
{

	index1 = searchIndex(Vector1,
						 Value1);

	dx = (Value1 - Vector1(index1)) / (Vector1(index1 + 1) - Vector1(index1));
	dx_inv = 1 - dx;

	index2 = searchIndex(Vector2,
		Value2);

	dy = (Value2 - Vector2(index2)) / (Vector2(index2 + 1) - Vector2(index2));
	dy_inv = 1 - dy;

	interpolationValue =	dx_inv	*dy_inv	*Table(index1, index2) +
							dx		*dy_inv	*Table(index1 + 1, index2) +
							dy		*dx_inv	*Table(index1, index2 + 1) +
							dx		*dy		*Table(index1 + 1, index2 + 1);

	return interpolationValue;
}
