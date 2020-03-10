// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#ifndef _PHYSENTITY_H
#define _PHYSENTITY_H
#include <vector>
#include "Collider.h"

// Game Entity donde generas los colliders
class PhysEntity : public GameEntity {
public:
	std::vector<Collider*> mColliders; // colliders

	PhysEntity(); // constructor
	virtual ~PhysEntity(); // destructor

	virtual void Render(); // render

protected:
	void AddCollider(Collider* collider, Vector2 localPos = VEC2_ZERO); // anadir el collider
};


#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33