#ifndef _GUNROBOT_H
#define _GUNROBOT_H

#include "Tiles.h"

// Robot Tile
class Rectangle : public Tiles {
public:
	Rectangle(int index); // constructor
	~Rectangle(); // destructor
};

#endif // _GUNROBOT_H