#include "LogData.h"

LogData::LogData()
{
	pfad1 = "C:\\Users/janol/source";
	pfad2 = "/repos/GenericFlightSimulation/Output/";
}

LogData::~LogData()
{
}

void LogData::openFile(string FileName)
{
	output.open(pfad1+pfad2+FileName, ios::app);
}

void LogData::defineHeader(string Header)
{

}

void LogData::closeFile(string FileName)
{
	output.close();
}

void LogData::updateLogData(Float64 &Variable)
{
	conversion = (char *)&Variable;
}
