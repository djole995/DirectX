// DirectX.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "DirectX.h"
/*#include <d3d9.h>
#include <d3dx9.h*/
//#include <InitGuid.h>
#include "Shapes.h"
#include "GenSinus.h"
#include "AppSound.h"
#include "math.h"
#include <vector>
/*#include <stdlib.h>
#include <stdio.h>*/
/*#include <XAudio2.h>
#include <dsound.h>*/

#define MAX_LOADSTRING 100
#define CAR_WIDTH 2
#define CAR_HEIGHT 1
#define CAR_DEPTH 2
#define OBSTACLE_WIDTH 0.2
#define OBSTACLE_HEIGHT 1
#define OBSTACLE_DEPTH 0.1


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

/*CUSTOMVERTEX verticesLight[] =
{
        { -3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f, },    // side 1
        { 3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f, },
        { -3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f, },
        { 3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f, },

        { -3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f, },    // side 2
        { -3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f, },
        { 3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f, },
        { 3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f, },

        { -3.0f, 3.0f, -3.0f, 0.0f, 1.0f, 0.0f, },    // side 3
        { -3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f, },
        { 3.0f, 3.0f, -3.0f, 0.0f, 1.0f, 0.0f, },
        { 3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f, },

        { -3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f, },    // side 4
        { 3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f, },
        { -3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f, },
        { 3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f, },

        { 3.0f, -3.0f, -3.0f, 1.0f, 0.0f, 0.0f, },    // side 5
        { 3.0f, 3.0f, -3.0f, 1.0f, 0.0f, 0.0f, },
        { 3.0f, -3.0f, 3.0f, 1.0f, 0.0f, 0.0f, },
        { 3.0f, 3.0f, 3.0f, 1.0f, 0.0f, 0.0f, },

        { -3.0f, -3.0f, -3.0f, -1.0f, 0.0f, 0.0f, },    // side 6
        { -3.0f, -3.0f, 3.0f, -1.0f, 0.0f, 0.0f, },
        { -3.0f, 3.0f, -3.0f, -1.0f, 0.0f, 0.0f, },
        { -3.0f, 3.0f, 3.0f, -1.0f, 0.0f, 0.0f, },
};*/
CUSTOMVERTEX rectVertices[] =
{
	{ -1.0f, -1.0f, 16.0f, 1.0f, 1.0f },    
    { 1.0f, -1.0f, 16.0f, 0.0f, 1.0f }, 
    { -1.0f, -1.0f, 14.0f, 1.0f, 0.0f },
    { 1.0f, -1.0f, 14.0f, 0.0f, 0.0f },
};

CUSTOMVERTEX trapRect[] = 
{
	{ -1.0f, -2.0f, 0.0f, 1.0f, 1.0f },    
    { 1.0f, -2.0f, 0.0f, 0.0f, 1.0f },
    { -1.0f, 0.0f, 0.0f, 1.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f }
};

CUSTOMVERTEX rectVertices2[] =
{
	{ -1.0f, -2.0f, 16.0f, 1.0f, 1.0f },    
    { 1.0f, -2.0f, 16.0f, 0.0f, 1.0f },
    { -1.0f, -1.0f, 16.0f, 1.0f, 0.0f },
    { 1.0f, -1.0f, 16.0f, 0.0f, 0.0f },
};

CUSTOMVERTEX rectFenceR[] =
{
	{ -1000.0f, -3.0f, 20.0f, 0.0f, 0.0f },    
    { -10.0f, -3.0f, 20.0f, 100.0f, 0.0f },
    { -1000.0f, -3.0f, -5380.0f, 100.0f, 500.0f },
    { -10.0f, -3.0f, -5380.0f, 0.0f, 500.0f },
};

CUSTOMVERTEX rectFenceL[] =
{
	{ 10.0f, -3.0f, 20.0f, 100.0f, 500.0f },    
    { 1000.0f, -3.0f, 20.0f, 0.0f, 500.0f },
    { 10.0f, -3.0f, -5380.0f, 100.0f, 0.0f },
    { 1000.0f, -3.0f, -5380.0f, 0.0f, 0.0f },
};

CUSTOMVERTEX skyRect[] =
{
	{ -1000.0f, -3.0f, 20.0f, 0.0f, 0.0f },    
    { 1000.0f, -3.0f, 20.0f, 2.0f, 0.0f },
    { -1000.0f, -3.0f, -5380.0f, 2.0f, 5.0f },
    { 1000.0f, -3.0f, -5380.0f, 0.0f, 5.0f },
};


CUSTOMVERTEX rectVerticesGrass[] =
{
	{ -10.0f, -3.0f, 20.0f, 1.0f, 50.0f },    
    { 10.0f, -3.0f, 20.0f, 0.0f, 50.0f },
    { -10.0f, -3.0f, -5380.0f, 1.0f, 0.0f },
    { 10.0f, -3.0f, -5380.0f, 0.0f, 0.0f },
};

CUSTOMVERTEX verticesCubeTexture[] =
{
        { -3.0f, -3.0f, 3.0f, 0.0f, 0.0f },    // side 1
        { 3.0f, -3.0f, 3.0f, 0.0f, 2.0f },
        { -3.0f, 3.0f, 3.0f, 2.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 2.0f, 2.0f },

        { -3.0f, -3.0f, -3.0f, 0.0f, 0.0f },    // side 2
        { -3.0f, 3.0f, -3.0f, 0.0f, 2.0f},
        { 3.0f, -3.0f, -3.0f, 2.0f, 0.0f },
        { 3.0f, 3.0f, -3.0f, 2.0f, 2.0f },

        { -3.0f, 3.0f, -3.0f, 0.0f, 0.0f },    // side 3
        { -3.0f, 3.0f, 3.0f, 0.0f, 2.0f },
        { 3.0f, 3.0f, -3.0f, 2.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 2.0f, 2.0f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 4
        { 3.0f, -3.0f, -3.0f, 0.0f, 2.0f },
        { -3.0f, -3.0f, 3.0f, 2.0f, 0.0f },
        { 3.0f, -3.0f, 3.0f,  2.0f, 2.0f },

        { 3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 5
        { 3.0f, 3.0f, -3.0f,  0.0f, 2.0f },
        { 3.0f, -3.0f, 3.0f,  2.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f,  2.0f, 2.0f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 6
        { -3.0f, -3.0f, 3.0f,  0.0f, 2.0f },
        { -3.0f, 3.0f, -3.0f, 2.0f, 0.0f },
        { -3.0f, 3.0f, 3.0f,  2.0f, 2.0f },
};

CUSTOMVERTEX vertices[] = 
{
	{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255) },
    { 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0) },
    { -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0) },
    { 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255) },
    { -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255) },
    { 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0) },
    { -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0) },
    { 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255) }
};

CUSTOMVERTEX piramidVertices[] =
{
    // base
    { -3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
    { 3.0f, 0.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },
    { -3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },
    { 3.0f, 0.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },

    // top
    { 0.0f, 7.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0), },
};

CUSTOMVERTEX piramidVerticesTextures[] =
{
    // base
    { -3.0f, -3.0f, 3.0f, 0.0f, 0.0f },
    { 3.0f, -3.0f, 3.0f, 0.0f, 1.0f },
    { -3.0f, -3.0f, -3.0f, 1.0f, 0.0f },
    { 3.0f, -3.0f, -3.0f, 1.0f, 1.0f },

    // top
    { 0.0f, 7.0f, 0.0f, 0.0f, 0.0f },
	{ 0.0f, 7.0f, 0.0f, 1.0f, 1.0f }
};

CUSTOMVERTEX treeRect[] = 
{
	{ -0.5f, -3.0f, 0.0f, 1.0f, 1.0f },    
    { 0.5f, -3.0f, 0.0f, 0.0f, 1.0f },
    { -0.5f, 3.0f, 0.0f, 1.0f, 0.0f },
    { 0.5f, 3.0f, 0.0f, 0.0f, 0.0f }
};

CUSTOMVERTEX gateSide[] = 
{
        { -3.0f, -3.0f, 3.0f, 0.0f, 0.0f },    // side 1
        { 3.0f, -3.0f, 3.0f, 0.0f, 0.2f },
        { -3.0f, 3.0f, 3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 1.0f, 0.2f },

        { -3.0f, -3.0f, -3.0f, 0.0f, 0.0f },    // side 2
        { -3.0f, 3.0f, -3.0f, 0.0f, 0.2f},
        { 3.0f, -3.0f, -3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, -3.0f, 1.0f, 0.2f },

        { -3.0f, 3.0f, -3.0f, 0.0f, 0.0f },    // side 3
        { -3.0f, 3.0f, 3.0f, 0.0f, 0.2f },
        { 3.0f, 3.0f, -3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 1.0f, 0.2f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 4
        { 3.0f, -3.0f, -3.0f, 0.0f, 0.2f },
        { -3.0f, -3.0f, 3.0f, 1.0f, 0.0f },
        { 3.0f, -3.0f, 3.0f,  1.0f, 0.2f },

        { 3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 5
        { 3.0f, 3.0f, -3.0f,  0.0f, 0.2f },
        { 3.0f, -3.0f, 3.0f,  1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f,  1.0f, 0.2f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 6
        { -3.0f, -3.0f, 3.0f,  0.0f, 0.2f },
        { -3.0f, 3.0f, -3.0f, 1.0f, 0.0f },
        { -3.0f, 3.0f, 3.0f,  1.0f, 0.2f },
};

CUSTOMVERTEX gateTop[] = 
{
        { -3.0f, -3.0f, 3.0f, 0.0f, 0.0f },    // side 1
        { 3.0f, -3.0f, 3.0f, 0.0f, 1.0f },
        { -3.0f, 3.0f, 3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 1.0f, 1.0f },

        { -3.0f, -3.0f, -3.0f, 0.0f, 0.0f },    // side 2
        { -3.0f, 3.0f, -3.0f, 0.0f, 1.0f},
        { 3.0f, -3.0f, -3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, -3.0f, 1.0f, 1.0f },

        { -3.0f, 3.0f, -3.0f, 0.0f, 0.0f },    // side 3
        { -3.0f, 3.0f, 3.0f, 0.0f, 1.0f },
        { 3.0f, 3.0f, -3.0f, 1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f, 1.0f, 1.0f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 4
        { 3.0f, -3.0f, -3.0f, 0.0f, 1.0f },
        { -3.0f, -3.0f, 3.0f, 1.0f, 0.0f },
        { 3.0f, -3.0f, 3.0f,  1.0f, 1.0f },

        { 3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 5
        { 3.0f, 3.0f, -3.0f,  0.0f, 1.0f },
        { 3.0f, -3.0f, 3.0f,  1.0f, 0.0f },
        { 3.0f, 3.0f, 3.0f,  1.0f, 1.0f },

        { -3.0f, -3.0f, -3.0f,  0.0f, 0.0f },    // side 6
        { -3.0f, -3.0f, 3.0f,  0.0f, 1.0f },
        { -3.0f, 3.0f, -3.0f, 1.0f, 0.0f },
        { -3.0f, 3.0f, 3.0f,  1.0f, 1.0f },
};   

CUSTOMVERTEX gunFireRect[] = 
{
	{ -0.1f, -3.0f, 12.0f, 1.0f, 1.0f },    
    { 0.1f, -3.0f, 12.0f, 0.0f, 1.0f },
    { -0.1f, -3.0f, -10.0f, 1.0f, 0.0f },
    { 0.1f, -3.0f, -10.0f, 0.0f, 0.0f }
};

short indices[] =
{
    0, 1, 2,    // side 1
    2, 1, 3,
    4, 0, 6,    // side 2
    6, 0, 2,
    7, 5, 6,    // side 3
    6, 5, 4,
    3, 1, 7,    // side 4
    7, 1, 5,
    4, 5, 0,    // side 5
    0, 5, 1,
    3, 7, 2,    // side 6
    2, 7, 6,
};

#define CUSTOMFVF (D3DFVF_XYZ /*| D3DFVF_NORMAL*/ | D3DFVF_TEX1 )
#define CUSTOMFVF2 (D3DFVF_XYZ /*| D3DFVF_NORMAL*/ | D3DFVF_TEX1 | D3DFVF_DIFFUSE)
#define OBSTACLES_NUMBER 170

IDirect3D9* d = Direct3DCreate9(D3D_SDK_VERSION);
IDirect3DDevice9* dev;
LPDIRECT3DVERTEXBUFFER9 vertex = NULL;
LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;
IDirect3DCubeTexture9* cubeTexture;
LPDIRECT3DSURFACE9 pZBuffer;
IDirect3DSurface9 *cubeSurface;
float cnt = 0;
int direction = 1;
bool start = true;
bool fire = false;
float value = 2;
float numSegs[] = {4, 3, 3};
float zZoom = 20;
float move = 0;

D3DVIEWPORT9 view;
D3DMATRIX *matrix;
IDirect3DSurface9* surface;
IDirect3DSurface9* backBuffer;
IDirect3DTexture9* fileTexture;
IDirect3DTexture9* fileTextureGrass;
IDirect3DTexture9* fileTextureFence;
IDirect3DTexture9* carTexture;
IDirect3DTexture9* skyTexture;
IDirect3DTexture9* fileTextureBrick;
IDirect3DTexture9* piramidTexture;
IDirect3DTexture9* fireTexture;
IDirect3DTexture9* woodTexture;
IDirect3DTexture9* gateTexture;
IDirect3DTexture9* obstacleTexture;
IDirectSound8 *sound;
IDirectSound3DBuffer *sound3DBuffer;
IDirectSound3DListener *sound3DListener;
IDirectSoundBuffer8 *soundBuffer;
IDirectSoundBuffer8 *soundBuffer2;
IDirectSoundBuffer8 *soundBuffer3;

std::vector<Position*> obstaclesPosition;
D3DRECT rect;
// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void render();
bool crash();

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DIRECTX, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	VOID* pVoid;
	D3DXMATRIX matrix;
	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DIRECTX));

	//dev->SetViewport(&view);

	// Main message loop:
	GetMessage(&msg, NULL, 0, 0);
	while (msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			render();
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DIRECTX));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DIRECTX);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   
   ShowWindow(hWnd, SW_MAXIMIZE);
   UpdateWindow(hWnd);


   D3DPRESENT_PARAMETERS dp;

   ZeroMemory(&dp, sizeof(dp));

   dp.Windowed = true;
   dp.SwapEffect = D3DSWAPEFFECT_DISCARD;
   dp.BackBufferFormat = D3DFMT_A8R8G8B8;
   dp.BackBufferWidth = 1366;
   dp.BackBufferHeight = 768;
   dp.BackBufferCount   = 1;
   dp.EnableAutoDepthStencil = true;
   dp.AutoDepthStencilFormat = D3DFMT_D16;

   d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &dp, &dev);

   dev->CreateVertexBuffer(24*sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &vertex, NULL);

    VOID* pVoid;

	dev->CreateIndexBuffer(36*sizeof(short),
                          0,
                          D3DFMT_INDEX16,
                          D3DPOOL_MANAGED,
                          &i_buffer,
                          NULL);

/*	D3DLIGHT9 light;    // create the light struct
	D3DMATERIAL9 material;    // create the material struct

    ZeroMemory(&light, sizeof(light));    // clear out the light struct for use
    light.Type = D3DLIGHT_DIRECTIONAL;    // make the light type 'directional light'
    light.Diffuse = D3DXCOLOR(0.7f, 0.5f, 0.0f, 1.0f);    // set the light's color
    light.Direction = D3DXVECTOR3(-1.0f, -0.3f, -1.0f);

    dev->SetLight(0, &light);    // send the light struct properties to light #0
    dev->LightEnable(0, TRUE);    // turn on light #0

	ZeroMemory(&material, sizeof(D3DMATERIAL9));    // clear out the struct for use
    material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);    // set diffuse color to white
    material.Ambient = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);    // set ambient color to white

    dev->SetMaterial(&material);    // set the globably-used material to &material

	dev->SetRenderState(D3DRS_LIGHTING, true);
	dev->SetRenderState(D3DRS_ZENABLE, true);
	dev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(10, 10, 10));*/



	LPCWSTR wsPath = L"D://Textures//Penguins.jpg"; // path to the image
    D3DXIMAGE_INFO Info;

	if(FAILED(D3DXGetImageInfoFromFile(wsPath, &Info)))
		MessageBox(hWnd, L"Ne valja", NULL, MB_OK);
	if(FAILED(dev -> CreateOffscreenPlainSurface(Info.Width, Info.Height, D3DFMT_A8R8G8B8, D3DPOOL_SYSTEMMEM, &surface, NULL)))
		MessageBox(hWnd, L"Ne valja surface", NULL, MB_OK);
	HRESULT h = D3DXLoadSurfaceFromFile(surface, NULL, NULL, wsPath, NULL, D3DX_FILTER_NONE, 0, NULL);
	 if(h == D3DERR_INVALIDCALL || h == D3DXERR_INVALIDDATA)
		 MessageBox(hWnd, L"Ne valja", NULL, MB_OK);
	 dev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	//dev->SetRenderState(D3DRS_FOGENABLE, true);
  /* HRESULT hr = dev->CreateCubeTexture(256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8,  D3DPOOL_DEFAULT, &cubeTexture, NULL);

   if(FAILED(hr))
   {
	   exit(0);
   }

    D3DXMATRIX matProjSave, matViewSave;
    dev->GetTransform(D3DTS_VIEW,       &matViewSave );
    dev->GetTransform(D3DTS_PROJECTION, &matProjSave);

	D3DXMATRIX matProj;
    D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI/2, 1.0f, 0.5f, 1000.0f);
    dev->SetTransform(D3DTS_PROJECTION, &matProj);

	D3DXVECTOR3 vEnvEyePt;
	vEnvEyePt.x = 0;
	vEnvEyePt.y = 0;
	vEnvEyePt.z = 10;
    D3DXVECTOR3 vLookatPt, vUpVec;
	vLookatPt.x = 0;
	vLookatPt.y = 0;
	vLookatPt.z = 0;

	vUpVec.x = 0;
	vUpVec.y = 1;
	vUpVec.z = 0;

	D3DXMATRIX matView;
    D3DXMatrixLookAtLH(&matView, &vEnvEyePt, &vLookatPt, &vUpVec);
	dev->SetTransform(D3DTS_VIEW, &matView);

	cubeTexture->GetCubeMapSurface(D3DCUBEMAP_FACE_NEGATIVE_Y, 0, &cubeSurface);
	//cubeTexture->UnlockRect(D3DCUBEMAP_FACE_POSITIVE_X, 0);
	dev->GetDepthStencilSurface(&pZBuffer);*/

	//dev->SetRenderTarget(1, cubeSurface);
	/*if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//car_back1.jpg", &fileTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);*/

	/*if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//car_back2.jpg", &carTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);*/

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//road_texture.jpg", &fileTextureGrass)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//grasstext.jpg", &fileTextureFence)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//desert.jpg", &fileTextureBrick)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//sky.jpg", &skyTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//tree.jpg", &piramidTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//fire.jpg", &fireTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//tree_wood.jpg", &woodTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//obstacle.jpg", &obstacleTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	if(FAILED(D3DXCreateTextureFromFile(dev, L"D://Textures//wall.jpg", &gateTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	D3DXCreateTextureFromFileEx(dev, 
	(L"D://Textures//car_back8.jpg"),
	D3DX_DEFAULT,
	 D3DX_DEFAULT,
	D3DX_DEFAULT,
	NULL,
	D3DFMT_A8R8G8B8, 
	D3DPOOL_MANAGED,
	D3DX_DEFAULT,
	D3DX_DEFAULT,
	D3DCOLOR_ARGB(255,  127, 127, 127),
	NULL,
	NULL,
	&carTexture);

	D3DXCreateTextureFromFileEx(dev, 
	(L"D://Textures//car_back7.jpg"),
	 D3DX_DEFAULT,
	 D3DX_DEFAULT,
	D3DX_DEFAULT,
	NULL,
	D3DFMT_A8R8G8B8, 
	D3DPOOL_MANAGED,
	D3DX_DEFAULT,
	D3DX_DEFAULT,
	D3DCOLOR_ARGB(255, 127, 127, 127),
	NULL,
	NULL,
	&fileTexture);

	dev->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

	dev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	dev->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	
	if(FAILED(dev->SetTexture(0, fileTexture)))
		MessageBox(hWnd, L"Ne valja tekstura", NULL, MB_OK);

	// Create sound device interface.
	HRESULT hr = DirectSoundCreate8(NULL, &sound, NULL);
	if(FAILED(hr))
		MessageBox(hWnd, L"Creating sound interface failed!", NULL, MB_OK);

	hr = sound->SetCooperativeLevel(hWnd, DSSCL_PRIORITY);
	if(FAILED(hr))
		MessageBox(hWnd, L"Setting sound cooperative level failed!", NULL, MB_OK);

	// Create buffer.
	hr = AppSound::CreateBuffer(sound, &soundBuffer, 10, 0);
	if(FAILED(hr))
		MessageBox(hWnd, L"Creating sound buffer failed!", NULL, MB_OK);

	hr = AppSound::CreateBuffer(sound, &soundBuffer2, 2, 0);
	if(FAILED(hr))
		MessageBox(hWnd, L"Creating sound buffer failed!", NULL, MB_OK);

	hr = AppSound::CreateBuffer(sound, &soundBuffer3, 1, 0);
	if(FAILED(hr))
		MessageBox(hWnd, L"Creating sound buffer failed!", NULL, MB_OK);

	hr = AppSound::LoadWav(soundBuffer, "D://Textures//car_sound.wav");
	if(FAILED(hr))
		MessageBox(hWnd, L"Loading sound failed!", NULL, MB_OK);

	hr = AppSound::LoadWav(soundBuffer2, "D://Textures//AK47.wav");
	if(FAILED(hr))
		MessageBox(hWnd, L"Loading sound failed!", NULL, MB_OK);

	hr = AppSound::LoadWav(soundBuffer3, "D://Textures//car_crash.wav");
	if(FAILED(hr))
		MessageBox(hWnd, L"Loading sound failed!", NULL, MB_OK);

	soundBuffer->SetCurrentPosition(0);
	soundBuffer2->SetCurrentPosition(0);
	soundBuffer3->SetCurrentPosition(0);

	for(int i = 0; i < OBSTACLES_NUMBER; i++)
	{
		obstaclesPosition.push_back(new Position(rand()%10-10, rand()%10-10, rand()%10-10, (Direction)(i%2)));
	}

	hr = soundBuffer->SetVolume(-2000);
	if(FAILED(hr))
		MessageBox(hWnd, L"Setting sound volume failed!", NULL, MB_OK);
	
	hr = soundBuffer->Play(0, 0, DSBPLAY_LOOPING);
	if(FAILED(hr))
		MessageBox(hWnd, L"Playing sound failed!", NULL, MB_OK);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	HRESULT hr;
	switch (message)
	{
	case WM_KEYUP:
		switch(wParam)
		{
		case VK_UP:
			start = false;
			hr = soundBuffer->Stop();
			if(FAILED(hr))
			{
				MessageBox(hWnd, L"Stoping sound failed!", NULL, MB_OK);
			}

			hr = soundBuffer->SetCurrentPosition(0);
			if(FAILED(hr))
			{
				MessageBox(hWnd, L"Rewinding sound failed!", NULL, MB_OK);
			}
			break;
		case VK_CONTROL:
			fire = false;
			hr = soundBuffer2->Stop();
			if(FAILED(hr))
			{
				MessageBox(hWnd, L"Stoping sound failed!", NULL, MB_OK);
			}

			hr = soundBuffer2->SetCurrentPosition(0);
			if(FAILED(hr))
			{
				MessageBox(hWnd, L"Rewinding sound failed!", NULL, MB_OK);
			}
			break;
		}
		break;
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_UP:
			if(!start)
			{
				soundBuffer->SetVolume(-2000);
				hr = soundBuffer->Play(0,  0,  DSBPLAY_LOOPING);
				if (FAILED(hr))
				{
					MessageBox(hWnd, L"Playing sound failed!", NULL, MB_OK);
				}
				start = true;
			}
			break;
		case VK_DOWN:
			zZoom += value;
			break;
		case VK_LEFT:
			if(move < 8)
				move += 1.0f;
			break;
		case VK_RIGHT:
			if(move > -8)
				move -= 1.0f;
			break;
		case VK_SPACE:
			value = 8;
			break;
		case VK_CONTROL:
			fire = true;
			hr = soundBuffer2->Play(0,  0,  DSBPLAY_LOOPING); 
			if (FAILED(hr))
			{
				MessageBox(hWnd, L"Playing sound failed!", NULL, MB_OK);
			}
			break;
		}
		break;	
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void render()
{
			zZoom -= value*start;

			dev->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(70, 120, 255), 1.0f, 0);
			dev->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

			dev->BeginScene();
			dev->SetFVF(CUSTOMFVF);
			D3DXMATRIX matRotateY;    // a matrix to store the rotation information
			D3DXMATRIX matRotateZ;
			D3DXMATRIX matRotateX;
			D3DXMATRIX matIdentity;
			D3DXMATRIX matTranslateX;
			D3DXMATRIX scale;

			D3DXMatrixIdentity(&matIdentity);
			
			static float index = 0.0f; 
			static float value = 0.01;
			static float translateValueX = 0.0f;

			if(index > 3.142)
			{
				index = -3.142;
			}
			//Increase Rotating float value
			index += value;

			dev->SetTransform(D3DTS_WORLD, &matIdentity);

			D3DXMATRIX matView;    // the view transform matrix

			D3DXMatrixLookAtLH(&matView,
							   &D3DXVECTOR3 (move, 0.0f, zZoom),    // the camera position
							   &D3DXVECTOR3 (move, 0.0f, zZoom-20),    // the look-at position
							   &D3DXVECTOR3 (0.0f, 1.0f, 0.0f));    // the up direction


			dev->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

			D3DXMATRIX matProjection;     // the projection transform matrix

			D3DXMatrixPerspectiveFovLH(&matProjection,
									   D3DXToRadian(60),    // the horizontal field of view
									   1300.0f / 700.0f, // aspect ratio
									   1.0f,    // the near view-plane
									   4000.0f);    // the far view-planes

			dev->SetTransform(D3DTS_PROJECTION, &matProjection);    // set the projection

			dev->SetStreamSource(0, vertex, 0, sizeof(CUSTOMVERTEX));
			dev->SetIndices(i_buffer);
			dev->SetTexture(0, fileTextureGrass);
			dev->SetTransform(D3DTS_WORLD, &(matIdentity));
			Shapes::DrawRect(dev, rectVerticesGrass, i_buffer, vertex);

			// obstacles
			dev->SetTexture(0, obstacleTexture);

			if(crash())
			{
				soundBuffer3->SetCurrentPosition(0);
				soundBuffer3->Play(0, 0, 0);
				soundBuffer->Stop();
				MessageBox(NULL, L"Game over!", NULL, MB_OK);
				for(int i = 0; i < obstaclesPosition.size(); i++)
				{
					delete obstaclesPosition[i];
				}
				exit(0);
			}
			
			if(zZoom < -5000)
			{
				soundBuffer->Stop();
				MessageBox(NULL, L"You win!", NULL, MB_OK);
				exit(0);
			}

			for(int i = 0; i < OBSTACLES_NUMBER; i++)
			{
				if(obstaclesPosition[i]->x > 10 || obstaclesPosition[i]->x < -10)
					obstaclesPosition[i]->direction = (obstaclesPosition[i]->direction == LEFT) ? RIGHT : LEFT;
				obstaclesPosition[i]->x += (obstaclesPosition[i]->direction == LEFT) ? 0.2 : -0.2;
				
				D3DXMatrixTranslation(&matTranslateX, obstaclesPosition[i]->x, -3, -40*i);
                D3DXMatrixScaling(&scale, 0.1, 1, 0.1);
				dev->SetTransform(D3DTS_WORLD, &(scale*matTranslateX));
				Shapes::DrawCuboid(dev, verticesCubeTexture, i_buffer, vertex);
			}
			cnt += 0.01;
			if((cnt > 2.5))
			{
				cnt = 0;
				direction = -direction;
			}

			if(zZoom < -2500)
				dev->SetTexture(0, fileTextureBrick);
			else
				dev->SetTexture(0, fileTextureFence);

			dev->SetTransform(D3DTS_WORLD, &(matIdentity));
			Shapes::DrawRect(dev, rectFenceL, i_buffer, vertex);

			dev->SetTransform(D3DTS_WORLD, &(matIdentity));
			Shapes::DrawRect(dev, rectFenceR, i_buffer, vertex);


			//Drawing trees
			dev->SetTexture(0, woodTexture);

			for(int i = 0; i < 50; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, 16, 0, -50*i);
				dev->SetTransform(D3DTS_WORLD, &matTranslateX);
				Shapes::DrawRect(dev, treeRect, i_buffer, vertex);
			}

			for(int i = 0; i < 50; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, -16, 0, -50*i);
				dev->SetTransform(D3DTS_WORLD, &matTranslateX);
				Shapes::DrawRect(dev, treeRect, i_buffer, vertex);
			}

			dev->SetTexture(0, piramidTexture);

			for(int i = 0; i < 50; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, 16, 2, -50*i);
				dev->SetTransform(D3DTS_WORLD, &matTranslateX);
				Shapes::DrawPiramid(dev, piramidVerticesTextures, i_buffer, vertex);
			}

			for(int i = 0; i < 50; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, -16, 2, -50*i);
				dev->SetTransform(D3DTS_WORLD, &matTranslateX);
				Shapes::DrawPiramid(dev, piramidVerticesTextures, i_buffer, vertex);
			}


			dev->SetTexture(0, gateTexture);
			D3DXMatrixScaling(&scale, 1, 4, 0.2);
			for(int i = 50; i < 100; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, 15, 0, -50*i);
				dev->SetTransform(D3DTS_WORLD, &(scale*matTranslateX));
				Shapes::DrawCuboid(dev, gateSide, i_buffer, vertex);
			}

			for(int i = 50; i < 100; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, -15, 0, -50*i);
				dev->SetTransform(D3DTS_WORLD, &(scale*matTranslateX));
				Shapes::DrawCuboid(dev, gateSide, i_buffer, vertex);
			}

			D3DXMatrixScaling(&scale, 6, 2, 0.2);
			for(int i = 50; i < 100; i++)
			{
				D3DXMatrixTranslation(&matTranslateX, 0, 18, -50*i);
				dev->SetTransform(D3DTS_WORLD, &(scale*matTranslateX));
				Shapes::DrawCuboid(dev, gateTop, i_buffer, vertex);
			}
			        
			// Drawing sky
			dev->SetTexture(0, skyTexture);
			D3DXMatrixRotationZ(&matRotateZ, D3DX_PI);
			D3DXMatrixTranslation(&matTranslateX, 0, 80, 0);
			dev->SetTransform(D3DTS_WORLD, &(matRotateZ * matTranslateX));
			Shapes::DrawRect(dev, skyRect, i_buffer, vertex);

			//Drawing car
			dev->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
			dev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			dev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

			dev->SetTexture(0, fileTexture);
			D3DXMatrixTranslation(&matTranslateX, move, 0, zZoom-20);
			dev->SetTransform(D3DTS_WORLD, &(matTranslateX));
			Shapes::DrawRect(dev, rectVertices2, i_buffer, vertex);
			dev->SetTexture(0, carTexture);
			Shapes::DrawRect(dev, rectVertices, i_buffer, vertex);

			dev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
			dev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
			dev->SetRenderState(D3DRS_ALPHABLENDENABLE, false);

			if(fire)
			{
				dev->SetTexture(0, fireTexture);
				D3DXMatrixTranslation(&matTranslateX, move, 1.5f, zZoom-20);
				dev->SetTransform(D3DTS_WORLD, &(matTranslateX));
				Shapes::DrawRect(dev, gunFireRect, i_buffer, vertex);
			}

			dev->EndScene();
			dev->Present(0, 0, 0, 0);
}

bool crash()
{
	for(int i = 0; i < OBSTACLES_NUMBER; i++)
	{
		if(abs(obstaclesPosition[i]->x - move) <= (CAR_WIDTH/2+OBSTACLE_WIDTH) && abs(zZoom-6+40*i) <= 1)
			return true;
	}
	return false;
}
