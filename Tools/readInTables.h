//////////////////////////////////////////////////////////////////////////////////////////
//
// class name:			readInTables
//
// short description:	class which reads in tables from text files
//
// Date:				22.10.2017
//
// Author:				Jan Olucak
//
// external sources:	-eigen library for Matrix operations
//						-C++ -Das umfassendes Handbuch,Rheinwerk Computing,
//						 Juergen Wolf
//
// revision:			1.0
//
//////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include <../EIGENDIR/EIGEN/Dense>
using Eigen::MatrixXd;
using Eigen::Vector3f;
using Eigen::MatrixX2f;
using Eigen::VectorXd;
using Eigen::Map;



using namespace std;

class readInTables
{
public:
	//////////////////////////////////////////////////////////////////
	// Base constructor
	/////////////////////////////////////////////////////////////////
	readInTables();

	//////////////////////////////////////////////////////////////////
	// destructor
	/////////////////////////////////////////////////////////////////
	~readInTables();

	//////////////////////////////////////////////////////////////////
	//  function which reads in data and returns matrix
	/////////////////////////////////////////////////////////////////
	virtual MatrixXd readInTable(string FileName);

	virtual VectorXd readInVector(string FileName);

private:
	vector<double> tempData;
	int columncounter;
	double element;
	int lines;
	string line;
	int	columns;
	MatrixXd tempMatrix;
	VectorXd tempVec;
	string PathName1;
	string PathName2;

};