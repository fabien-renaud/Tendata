#include "Tendata.h"

Tendata::Tendata() {
}


Tendata::~Tendata() {
}

void Tendata::getData(PerformanceCounter^ CPUCounter) {
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

double Tendata::getPerVMemory() {
	return ((double)usedVMemory / (double)totalVMemory) * 100;
}

double Tendata::getPerPMemory() {
	return ((double)usedPMemory / (double)totalPMemory) * 100;
}

void Tendata::sendData() {

}

int main() {
	Tendata *tendata = new Tendata();
	PerformanceCounter^ CPUCounter;
	PerformanceCounter^ AlimCounter;
	CPUCounter = gcnew PerformanceCounter("Processor", "% Processor Time", "_Total");
	AlimCounter = gcnew PerformanceCounter("Energy Counter", "Energy");
	while (1) {
		tendata->getData(CPUCounter);
		Sleep(1000);
	}
	return 0;
}