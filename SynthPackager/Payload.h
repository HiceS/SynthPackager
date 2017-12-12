#pragma once

#include "stdafx.h"

class Payload {

public:
	Payload(_In_ LPCWSTR outName, _Outptr_ IAppxPackageWriter**);
	~Payload();

	HRESULT GetPackageWriter();
	HRESULT AddPayloadFiles();

	void cleanup();

private:
	LPCWSTR encryption;
	_In_ LPCWSTR outName;
	_Outptr_ IAppxPackageWriter** writer;

	HRESULT hr;

	IStream* outStream;
	IUri* hashMethod;
	APPX_PACKAGE_SETTINGS packageSettings;
	IAppxFactory* appxFactory;
};
