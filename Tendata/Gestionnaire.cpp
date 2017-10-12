#include "Gestionnaire.h"

Gestionnaire::Gestionnaire() {
}


Gestionnaire::~Gestionnaire() {
}

void Gestionnaire::createCounter(PerformanceCounter^% CPUCounter) {
	CPUCounter = gcnew PerformanceCounter("Processor", "% Processor Time", "_Total");
} 

void Gestionnaire::getData(PerformanceCounter^ CPUCounter) {
	// get all memory info
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);

	// get informations about virtual memory
	totalVMemory = memInfo.ullTotalPageFile;
	usedVMemory = totalVMemory - memInfo.ullAvailPageFile;
	cout << "Virtual Memory : " << usedVMemory << "/" << totalVMemory << endl;
	cout << "Virtual Memory : " << getPerVMemory() << "%" << endl;

	// get informations about physical memory
	totalPMemory = memInfo.ullTotalPhys;
	usedPMemory = totalPMemory - memInfo.ullAvailPhys;
	cout << "Physical Memory : " << usedPMemory << "/" << totalPMemory << endl;
	cout << "Physical Memory : " << getPerPMemory() << "%" << endl;

	// get informations about CPU
	usedCPU = CPUCounter->NextValue();
	cout << "CPU : " << usedCPU << "%" << endl;

	cout << endl;
}

double Gestionnaire::getPerVMemory() {
	return ((double)usedVMemory / (double)totalVMemory) * 100;
}

double Gestionnaire::getPerPMemory() {
	return ((double)usedPMemory / (double)totalPMemory) * 100;
}

int main() {
	Gestionnaire *gestionnaire = new Gestionnaire();
	PerformanceCounter^ CPUCounter;
	gestionnaire->createCounter(CPUCounter);
	while (1) {
		gestionnaire->getData(CPUCounter);
		Sleep(1000);
	}

	return 0;
}