#include "stdafx.h"
#include "AppSound.h"



AppSound::AppSound(void)
{
}


AppSound::~AppSound(void)
{
}

HRESULT AppSound::CreateBuffer(IDirectSound8 *sound, IDirectSoundBuffer8 **buffer, int length, DWORD descFlags)
{
	WAVEFORMATEX wfx;
	DSBUFFERDESC dsbdesc;
	LPDIRECTSOUNDBUFFER pDsb = NULL; 
	HRESULT hr;

	// Set up WAV format structure. 
	memset(&wfx, 0, sizeof(WAVEFORMATEX)); 
	wfx.wFormatTag = WAVE_FORMAT_PCM; 
	wfx.nChannels = 2; 
	wfx.nSamplesPerSec = 22050; 
	wfx.nBlockAlign = 4; 
	wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign; 
	wfx.wBitsPerSample = 16; 
 
	// Set up DSBUFFERDESC structure. 

	memset(&dsbdesc, 0, sizeof(DSBUFFERDESC)); 
	dsbdesc.dwSize = sizeof(DSBUFFERDESC); 
	
	// If flags not specified, setting default flags. 
	if(descFlags == 0)
		dsbdesc.dwFlags = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY
		| DSBCAPS_GLOBALFOCUS;
	else
		dsbdesc.dwFlags = descFlags;

	dsbdesc.dwBufferBytes = length * wfx.nAvgBytesPerSec; 
	dsbdesc.lpwfxFormat = &wfx; 
	
	// Create buffer. 
	hr = sound->CreateSoundBuffer(&dsbdesc, &pDsb, NULL); 
	if (SUCCEEDED(hr)) 
	{ 
		hr = pDsb->QueryInterface(IID_IDirectSoundBuffer8, (void**)buffer);
		pDsb->Release();
	}
	return hr;
}

HRESULT AppSound::LoadWav(IDirectSoundBuffer8 *buffer, const char* filePath)
{
	FILE *f = fopen(filePath, "r");
	short *data;
	unsigned int dataSize = 0;
    
	LPVOID lpvWrite;
	DWORD  dwLength;
	HRESULT hr;
	DWORD sampleRate;

	fseek(f, 24, SEEK_SET);
	fread(&sampleRate, sizeof(DWORD), 1, f);
	buffer->SetFrequency(sampleRate);

	fseek(f, 40, SEEK_SET);
	fread(&dataSize, sizeof(unsigned int), 1, f);

	hr = buffer->Lock(
      0,          // Offset at which to start lock.
      0,          // Size of lock; ignored because of flag.
      &lpvWrite,  // Gets address of first part of lock.
      &dwLength,  // Gets size of first part of lock.
      NULL,       // Address of wraparound not needed. 
      NULL,       // Size of wraparound not needed.
      DSBLOCK_ENTIREBUFFER);  // Flag.

	if (hr == DS_OK)
	{ 
		data = (short*) malloc(dataSize);
		fseek(f, 44, SEEK_SET);
		fread(data, sizeof(short), dataSize/2, f);

		if(dwLength <= dataSize)
			memcpy(lpvWrite, data, dwLength);
		else
			memcpy(lpvWrite, data, dataSize);

		hr = buffer->Unlock(
		lpvWrite,   // Address of lock start.
		dwLength,   // Size of lock.
		NULL,       // No wraparound portion.
		0);         // No wraparound size.
	}

	fclose(f);

	return hr;
}