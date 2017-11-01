#include "readInData.h"


readInData::readInData()
{
	PathName2 = "../Input/";
}

readInData::~readInData()
{
}

Float64 readInData::readInParameter(std::string CodeWord, std::string FileName)
{


	// Öffne File
	input.open(PathName2+FileName, std::ios::in);

	// Exit if file opening failed
	if (!input.is_open()) {
		std::cerr << "Daten von  " << FileName << " konnten nicht gelesen werden" << std::endl;
		system("pause");
		exit(1);
	}

	// Durchlaufe File, solange Daten vorhanden
	while (!input.eof())
	{
		// Einlesen Zeile für Zeile
		std::getline(input, currtenLine);

		// Suche nach Code Wort in der aktuellen Zeile
		std::size_t found = currtenLine.find(CodeWord, 0);

		// Wenn Zeile gefunden, dann Parameter extrahieren
		if (found != std::string::npos)
		{

			size_t pos = 0;
			std::string delimiter = "=";
			std::string token = currtenLine.substr(pos, currtenLine.find(delimiter));

			while ((currtenLine.find(delimiter)) != std::string::npos) {
				token = currtenLine.substr(0, pos);
				currtenLine.erase(0, pos + delimiter.length());
			}

			tempValue = std::stod(currtenLine.c_str());

		}
	}
	input.close();
	std::cout << CodeWord << " = " <<tempValue << std::endl;
	Float64 Value = tempValue;
	currtenLine.clear();

	return Value;
}

MatrixXd readInData::readInTable(std::string FileName)
{
	// initialisation of data
	lines, columns = -1;


	std::ifstream input(PathName2 + FileName);


	// Exit if file opening failed
	if (!input.is_open()) {
		std::cerr << "Daten von  " << FileName << " konnten nicht gelesen werden" << std::endl;
		system("pause");
		exit(1);
	}

	while (getline(input, line))
	{
		columncounter = 0;
		std::stringstream lineparser(line);

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

VectorXd readInData::readInVector(std::string FileName)
{
	// initialisation of data
	lines, columns = -1;


	std::ifstream input(PathName2 + FileName);


	// Exit if file opening failed
	if (!input.is_open()) {
		std::cerr << "Daten von ... konnten nicht gelesen werden" << std::endl;
		exit(1);
	}

	while (getline(input, line))
	{
		columncounter = 0;
		std::stringstream lineparser(line);

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
