#include "readInTables.h"
#include<iostream>

readInTables::readInTables()
{
	PathName2 = "../Input/";
}

readInTables::~readInTables()
{
	
}


MatrixXd readInTables::readInTable(string FileName)
{
	
	// initialisation of data
	lines, columns = -1;


	ifstream input(PathName2+FileName);
	

	// Exit if file opening failed
	if (!input.is_open()) {
		cerr << "Daten von  " << FileName << " konnten nicht gelesen werden" << endl;
		system("pause");
		exit(1);
	}

	while (getline(input, line))
	{
		 columncounter = 0;
		stringstream lineparser(line);
		
		while (lineparser >> element)
		{

			tempData.push_back(element);
			++columncounter;
		}
		if (columns == -1) columns = columncounter;
		/*if (columns != columncounter)
		{
		cerr << "Fehler: Unterschiedliche Spaltenzahl in mindestens zwei Zeilen" << endl;
		exit(1);
		}*/
	}
	lines = tempData.size() / columns;

	//write data to matrix
	tempMatrix.resize(lines, columns);
	tempMatrix.setZero(lines, columns);

	if (columns == 1) {

		tempVec.resize(lines);
		tempVec.setZero(lines);
		//for (int i = 0; i < lines; ++i)
		//{
			//std::cout << tempData[i] << std::endl;
		//}
	}
	else {
		for (int i = 0; i < lines; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				tempMatrix(i, j) = tempData[i*columns + j];
			}
		}

		tempData.clear();
		if (columns == 1) {
			return tempVec;
		}
		return tempMatrix;
		
	}
}

VectorXd readInTables::readInVector(string FileName)
{

	// initialisation of data
	lines, columns = -1;


	ifstream input(PathName2 + FileName);


	// Exit if file opening failed
	if (!input.is_open()) {
		cerr << "Daten von ... konnten nicht gelesen werden" << endl;
		exit(1);
	}

	while (getline(input, line))
	{
		columncounter = 0;
		stringstream lineparser(line);

		while (lineparser >> element)
		{

			tempData.push_back(element);
			++columncounter;
		}
		if (columns == -1) {
			columns = columncounter;
		}
			

	}
	lines = tempData.size() / columns;


		tempVec.resize(lines);
		tempVec.setZero(lines);
		for (int i = 0; i < lines; ++i)
		{
			tempVec(i) = tempData[i];
		}


		tempData.clear();
	
		return tempVec;



}