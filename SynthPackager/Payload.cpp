#include "stdafx.h"

Payload::Payload(_In_ LPCWSTR out, _Outptr_ IAppxPackageWriter** write) {
	encryption = L"http://www.w3.org/2001/04/xmlenc#sha256";
	writer = write;
	outName = out;

	HRESULT hr = S_OK;

	IStream* outStream = NULL;
	IUri* hashMethod = NULL;
	APPX_PACKAGE_SETTINGS packageSettings = { 0 };
	IAppxFactory* appxFactory = NULL;
}

Payload::~Payload() {
	cleanup();
}

HRESULT Payload::GetPackageWriter() {
	hr = SHCreateStreamOnFileEx(outName, STGM_CREATE | STGM_WRITE | STGM_SHARE_EXCLUSIVE, 0, TRUE, NULL, &outStream);

	hr == S_OK ? hr = CreateUri(encryption, Uri_CREATE_CANONICALIZE, 0, &hashMethod) : hr = E_FAIL;
	
	if (hr == S_OK){
		packageSettings.forceZip32 = TRUE;
		packageSettings.hashMethod = hashMethod;
	}

	hr == S_OK ? hr = CoCreateInstance(__uuidof(appxFactory), NULL, CLSCTX_INPROC_SERVER, __uuidof(IAppxFactory), (LPVOID*)(&appxFactory)) : hr = E_FAIL;
	
	cleanup();

	return hr;
}



void Payload::cleanup() {
	//Only de-allocate and cleanup if exist
	if (appxFactory)
	{
		appxFactory->Release();
		appxFactory = NULL;
	}
	if (hashMethod)
	{
		hashMethod->Release();
		hashMethod = NULL;
	}
	if (outStream)
	{
		outStream->Release();
		outStream = NULL;
	}
	if (writer)
	{
		//not correct de-allocation - fix later 
		writer = NULL;
		delete writer;
	}
}