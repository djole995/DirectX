#include "StdAfx.h"
#include "Shapes.h"


Shapes::Shapes(void)
{
}


Shapes::~Shapes(void)
{
}

void Shapes::DrawPiramid(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer)
{
	short indices[] =
	{
		0, 2, 1,    // base
		1, 2, 3,
		0, 1, 5,    // sides
		1, 3, 4,
		3, 2, 4,
		2, 0, 5,
	};

	void *pVoid;

	vBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, 6*sizeof(CUSTOMVERTEX));
	vBuffer->Unlock();

	iBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, indices, sizeof(indices));
	iBuffer->Unlock();

	dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 5, 0, 6);
}

void Shapes::DrawCuboid(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer)
{
	short indices[] =
    {
        0, 1, 2,    // side 1
        2, 1, 3,
        4, 5, 6,    // side 2
        6, 5, 7,
        8, 9, 10,    // side 3
        10, 9, 11,
        12, 13, 14,    // side 4
        14, 13, 15,
        16, 17, 18,    // side 5
        18, 17, 19,
        20, 21, 22,    // side 6
        22, 21, 23,
    };

	void *pVoid;

	vBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, 24*sizeof(CUSTOMVERTEX));
	vBuffer->Unlock();

	iBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, indices, sizeof(indices));
	iBuffer->Unlock();

	dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

}

void Shapes::DrawRect(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer)
{
	short indices[] =
	{
		0, 1, 2,
		2, 1, 3
	};

	void *pVoid;

	vBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, 4*sizeof(CUSTOMVERTEX));
	vBuffer->Unlock();

	iBuffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, indices, sizeof(indices));
	iBuffer->Unlock();

	dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

void Shapes::DrawTree(IDirect3DDevice9* dev, CUSTOMVERTEX vertices[], IDirect3DIndexBuffer9* iBuffer, IDirect3DVertexBuffer9* vBuffer)
{
}