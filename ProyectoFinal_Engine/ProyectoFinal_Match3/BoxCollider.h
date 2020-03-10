// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Collider.h"

// clase de box collider
class BoxCollider : public Collider {
private:

	static const int MAX_VERTS = 4; // numero de vertices
	GameEntity* mVerts[MAX_VERTS]; // numero de vertices

public:
	BoxCollider(Vector2 size); // constructor
	~BoxCollider(); // destructor

private:
	void AddVert(int index, Vector2 pos); // anade vertices
};

#endif // !BOXCOLLIDER_H



// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33