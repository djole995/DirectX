
#include "stdafx.h"

enum Direction { LEFT, RIGHT, UP, DOWN };

struct CUSTOMVERTEX {
	FLOAT x, y, z;
	//D3DVECTOR normal;
	float tu, tv;
	//D3DCOLOR color;
	//float rhw;
};

struct CUSTOMVERTEX2 {
	FLOAT x, y, z;
	//D3DVECTOR normal;
	float tu, tv;
	D3DCOLOR color;
	//float rhw;
};

typedef struct Position
{
	float x, y, z;
	Direction direction;

	Position(float _x, float _y, float _z, Direction _direction)
	{
		x = _x;
		y = _y;
		z = _z;
		direction = _direction;
	}
} Position;

