// AudioDeviceEnum.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
#pragma comment(lib, "Winmm.lib")

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

