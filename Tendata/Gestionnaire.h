#ifndef GESTIONNAIRE
#define GESTIONNAIRE

#include <iostream>
#include <windows.h>
#using <System.dll>
using namespace std;
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Specialized;
using namespace System::Diagnostics;

class Gestionnaire {
public:
	Gestionnaire();
	~Gestionnaire();
	void createCounter(PerformanceCounter^% CPUCounter);
	void getData(PerformanceCounter^ CPUCounter);
	double getPerVMemory();
	double getPerPMemory();

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