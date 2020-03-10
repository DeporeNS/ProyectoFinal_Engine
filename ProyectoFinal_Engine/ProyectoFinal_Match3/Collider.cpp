// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#include "Collider.h"

// constructor
Collider::Collider(ColliderType type) : mType(type) {
	mDebugTexture = nullptr;
}

// destructor
Collider::~Collider() {
	if (mDebugTexture) {
		delete mDebugTexture;
		mDebugTexture = nullptr;
	}
}

// Pone la textura que quieres usar para el debug
void Collider::SetDebugTexture(Texture* texture) {
	delete mDebugTexture;
	mDebugTexture = texture;
	mDebugTexture->Parent(this);
}


void Collider::Render() {
	if (DEBUG_COLLIDERS) {
		mDebugTexture->Render();
	}
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33