// SynthPackager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

const LPCWSTR OutPath = L"SynthesisInstaller.appx";

int main()
{

	char * inpath = new char[100]; 
	//Covered by manifest file, almost forgot
	/*char * exe = new char[100];
	char * AppName = new char[100];
	char * Certificate = new char[100];*/

	cout << "Please specify the file directory!" << endl;
	cin.getline(inpath, strlen(inpath + 1));
	cout << "Path is : " << inpath << endl;

	cout << "\nDid you remember to appropriately modify the AppManifest.xml file?" << endl;

	HRESULT hr = S_OK;

	// Specify the appropriate COM threading model
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (SUCCEEDED(hr))
	{
		// Create a package writer
		IAppxPackageWriter* packageWriter = NULL;


		Payload* p = new Payload(OutPath, & packageWriter);
		hr = p->GetPackageWriter();

		//Next write recursive loop for all files in the root directory.

	}

    return 0;
}

