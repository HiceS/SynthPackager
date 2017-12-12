// SynthPackager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

const LPCWSTR OutPath = L"SynthesisInstaller.appx";

int main()
{

	char * inpath = new char[100]; 
	cout << "Please specify the file directory!" << endl;
	cin.getline(inpath, strlen(inpath + 1));
	cout << "Path is : " << inpath << endl;

	HRESULT hr = S_OK;

	// Specify the appropriate COM threading model
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (SUCCEEDED(hr))
	{
		// Create a package writer
		IAppxPackageWriter* packageWriter = NULL;


		Payload* p = new Payload(OutPath, & packageWriter);
		hr = p->GetPackageWriter();

	}

    return 0;
}

