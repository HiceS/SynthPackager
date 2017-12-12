// SynthPackager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const LPCWSTR OutPath = L"SynthesisInstaller.appx";

int wmain()
{
	HRESULT hr = S_OK;

	// Specify the appropriate COM threading model
	hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (SUCCEEDED(hr))
	{
		// Create a package writer
		IAppxPackageWriter* packageWriter = NULL;

		hr = IAppxFactory::GetPackageWriter(OutputPackagePath, &packageWriter);
	}

    return 0;
}

