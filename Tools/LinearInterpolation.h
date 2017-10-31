#pragma once

#include <vector>
#include <C:\Users\janol\source\repos\Project4\Project4\Debug\EIGENDIR\EIGEN\Dense>
#include<math.h>


using Eigen::MatrixXd;
using Eigen::Vector3f;
using Eigen::MatrixX2f;
using Eigen::VectorXd;
using Eigen::Map;

typedef double Float64;
typedef int    Int32;

class LinearInterpolation{
public:
	LinearInterpolation();

	~LinearInterpolation();

	VectorXd loadTable(MatrixXd);

	Float64 searchIndex(VectorXd Vector,
						Float64 Value);

	Float64 biLinearInterpolation(VectorXd Vector1,
								  VectorXd Vector2,
								  MatrixXd Table,
								  Float64 Value1,
								  Float64 Value2);
	
private:
	Int32		index1;
	Int32		index2;
	Float64     dx;
	Float64		dy;
	Float64     dx_inv;
	Float64		dy_inv;
	Float64	    interpolationValue;

};