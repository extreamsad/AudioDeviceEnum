// AudioDeviceEnum.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "PolicyConfig.h"

using namespace std;
#pragma comment(lib, "Winmm.lib")

HRESULT SetDefaultAudioPlaybackDevice(LPCWSTR devID)
{
	IPolicyConfigVista *pPolicyConfig;
	ERole reserved = eConsole;

	HRESULT hr = CoCreateInstance(__uuidof(CPolicyConfigVistaClient),
		NULL, CLSCTX_ALL, __uuidof(IPolicyConfigVista), (LPVOID *)&pPolicyConfig);
	if (SUCCEEDED(hr))
	{
		hr = pPolicyConfig->SetDefaultEndpoint(devID, reserved);
		pPolicyConfig->Release();
	}
	return hr;
}

int main()
{
	int nSoundCardCount = waveOutGetNumDevs();

	for (int i = 0; i < nSoundCardCount; i++)
	{
		WAVEOUTCAPS woc;
		waveOutGetDevCaps(i, &woc, sizeof(woc));

		wcout << woc.szPname << endl;
	}

	system("pause");

    return 0;
}

