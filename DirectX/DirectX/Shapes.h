#pragma once

#include "Types.h"

class Shapes
{
public:
	Shapes(void);
	~Shapes(void);

	static void DrawCuboid(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer);
	static void DrawPiramid(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer);
	static void DrawRect(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer);
	static void DrawTree(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer);
};

