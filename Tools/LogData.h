#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

typedef double Float64;

using namespace std;

class LogData
{
public:
	LogData();

	~LogData();
	
	void openFile(string FileName);

	void defineHeader(string Header);

	void updateLogData(Float64 &Variable);

	void closeFile(string FileName);


private:
	string FileName;
	ofstream output;
	char   *conversion;
	string pfad1;
	string pfad2;

};
