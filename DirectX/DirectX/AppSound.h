#pragma once

#include "stdafx.h"

class AppSound
{
public:
	AppSound(void);
	~AppSound(void);

	static HRESULT CreateBuffer(IDirectSound8 *sound, IDirectSoundBuffer8 **buffer, int length, DWORD descFlags);  
	static HRESULT LoadWav(IDirectSoundBuffer8 *buffer, const char *filePath); 
};

