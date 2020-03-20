#ifndef _MINIARMY_H
#define _MINIARMY_H

#include "Tiles.h"

// Robot Tile
class Triangle : public Tiles {
public:
	Triangle(int index); // constructor
	~Triangle(); // destructor
};

#endif // _MINIARMY_H