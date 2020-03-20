#ifndef _ROBOT_H
#define _ROBOT_H

#include "Tiles.h"

// Robot Tile
class Robot : public Tiles {
public:
	Robot(int index); // constructor
	~Robot(); // destructor
};

#endif // _ROBOT_H
