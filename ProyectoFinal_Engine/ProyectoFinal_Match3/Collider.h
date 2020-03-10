// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33
#ifndef _COLLIDER_H
#define _COLLIDER_H

#include "Texture.h"

using namespace ProyectoFinal;

// clase para hacer los box colliders
class Collider : public GameEntity {
public:
	//tipo de colider si de cuadro o circulo
	enum class ColliderType {
		Box,
		Circle
	};

protected:
	ColliderType mType; // tipo

	static const bool DEBUG_COLLIDERS = true; // verdadero si se va a ver la imagen para hacer debug
	Texture* mDebugTexture; // textura del collider

public:

	Collider(ColliderType type); // construtor
	virtual ~Collider(); // destructor

	virtual void Render(); // render

protected:
	void SetDebugTexture(Texture* texture); // poner la textura
};

#endif

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=232DKHiChKo&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=33