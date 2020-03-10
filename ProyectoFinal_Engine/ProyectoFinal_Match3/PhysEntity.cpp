// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#include "PhysEntity.h"

//constructor
PhysEntity::PhysEntity() {

}

//destructor
PhysEntity::~PhysEntity() {
	for (int i = 0; i < mColliders.size(); i++) {
		delete mColliders[i];
		mColliders[i] = nullptr;
	}
	mColliders.clear();
}

// Anadir collider al objeto deseado
void PhysEntity::AddCollider(Collider* collider, Vector2 localPos) {
	collider->Parent(this);
	collider->Pos(localPos);
	mColliders.push_back(collider);
}

// Render all colliders
void PhysEntity::Render() {
	for (int i = 0; i < mColliders.size(); i++) {
		mColliders[i]->Render();
	}
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33