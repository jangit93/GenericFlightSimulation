#pragma once
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
#include <C:\Users\janol\Desktop\Studium\Master_Luft und Raumfahrttechnik\2.Fachsemester\Effizient Programmieren\Programierprojekt\GenericFlightSimulation\EIGENDIR\Eigen\dense>
using Eigen::MatrixXd;
using Eigen::Vector3f;
using Eigen::MatrixX2f;
using Eigen::VectorXd;
using Eigen::Map;


typedef double Float64;

class readInData
{
public:
	//////////////////////////////////////////////////////////////////
	// Base constructor
	/////////////////////////////////////////////////////////////////
	readInData();

	//////////////////////////////////////////////////////////////////
	// destructor
	/////////////////////////////////////////////////////////////////
	~readInData();

	//////////////////////////////////////////////////////////////////
	//  function which reads in data and returns matrix
	/////////////////////////////////////////////////////////////////
	Float64 readInParameter(std::string CodeWord, std::string Filename);
	 MatrixXd readInTable(std::string FileName);

	VectorXd readInVector(std::string FileName);

	void setPath(std::string Pathname);

private:
	std::vector<double> tempData;
	int columncounter;
	double element;
	int lines;
	std::string line;
	int	columns;
	MatrixXd tempMatrix;
	VectorXd tempVec;
	std::string PathName1;
	std::string PathName2;
	Float64 tempValue;
	std::fstream input;
	std::string currtenLine;

};