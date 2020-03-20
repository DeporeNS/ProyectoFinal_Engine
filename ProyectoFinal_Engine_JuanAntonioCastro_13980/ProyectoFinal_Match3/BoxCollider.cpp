// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#include "BoxCollider.h"

// Constructor
BoxCollider::BoxCollider(Vector2 size) : Collider(ColliderType::Box) {
	AddVert(0, Vector2(-0.5f * size.x, -0.5f * size.y));
	AddVert(2, Vector2( 0.5f * size.x, -0.5f * size.y));
	AddVert(3, Vector2(-0.5f * size.x,  0.5f * size.y));
	AddVert(4, Vector2( 0.5f * size.x,  0.5f * size.y));

	if (DEBUG_COLLIDERS) {
		SetDebugTexture(new Texture("BoxCollider.png"));
		mDebugTexture->Scale(size / 100.0f);
	}
}

// Destructor
BoxCollider::~BoxCollider() {
	for (int i = 0; i < MAX_VERTS; i++) {
		delete mVerts[i];
		mVerts[i] = nullptr;
	}
}

// Add vertex
void BoxCollider::AddVert(int index, Vector2 pos) {
	mVerts[index] = new GameEntity(pos.x, pos.y);
	mVerts[index]->Parent(this);
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33