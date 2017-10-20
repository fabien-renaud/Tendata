#ifndef TENDATA
#define TENDATA

#include <iostream>
#include <windows.h>
#using <System.dll>

using namespace std;
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Specialized;
using namespace System::Diagnostics;

class Tendata {
public:
	Tendata();
	~Tendata();
	void getData(PerformanceCounter^ CPUCounter);
	double getPerVMemory();
	double getPerPMemory();
	void sendData();

private:
	// RAM Usage
	DWORDLONG usedVMemory;
	DWORDLONG usedPMemory;
	DWORDLONG totalVMemory;
	DWORDLONG totalPMemory;
	double	  perVMemory;
	double	  perPMemory;
	double	  usedCPU;
};

#endif