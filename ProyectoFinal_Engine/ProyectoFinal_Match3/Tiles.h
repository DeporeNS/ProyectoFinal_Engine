#ifndef _TILES_H
#define _TILES_H

#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace ProyectoFinal;

// Clase padre de las tiles
class Primitives : public GameEntity {
public:
	// tipo de tile
	enum class TilesType {
		Army,
		GunRobot,
		Head,
		Robot,
		MiniArmy
	};

	// estados de las tiles
	enum States {
		normal,
		selected,
		destroy,
		over
	};

protected:
	bool inside;
	int time = 0;

	// Managers
	InputManager* mInput;
	TilesType mType;
	States mCurrentState;
	Texture* mTexture[6]; // textura de la tile
	AnimatedTexture* mAnimatedTexture;
	int mIndex;

protected:
	void HandleStates(); // para constrolar los estadps
	virtual void HandleNormalState();
	virtual void HandleSelectedState();
	virtual void HandleDestroyState();
	virtual void HandleOverState();

	void RenderStates(); // para constrolar el render segun los estados
	virtual void RenderNormalState();
	virtual void RenderSelectedState();
	virtual void RenderDestroyState();
	virtual void RenderOverState();

public:
	Primitives(int index); // constructor
	Primitives();
	virtual ~Primitives(); // destructor

	void changeState(int state); // funcion para cambiar el estado

	States CurrentState(); // regresa el estado
	TilesType Type(); // regresa el tipo
	States getState(int state); // para sacar un estado
	int GetIndex(); // regresa un indice del 1 al 5 segun el tipo de tile

	void Update(); // update

	virtual void Render(); // render
};

#endif
