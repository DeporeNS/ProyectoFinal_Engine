#ifndef _ENEMY_H
#define _ENEMY_H

#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace ProyectoFinal;

// Clase para el player
class Enemy : public GameEntity {
public:
	// estados de las tiles
	enum States {
		seek,
		evade,
		flee,
		pursuit,
		arrive,
		wander,
		obstacle,
		wall,
		interpose,
		hide,
		path,
		offset
	};

protected:
	bool inside;
	int time = 0;

	// Managers
	InputManager* mInput;
	States mCurrentState;

	float maxSpeed = 2;
	float ahead;
	float magnitud;

	Vector2 PlayerDirection;
	Vector2 ScaleObstacle;
	Vector2 MousePos;
	Vector2 behind;
	Vector2 TargetPos;
	Vector2 Target;
	Vector2 normal;
	Vector2 dVel;
	Vector2 steering;
	Vector2 clampedV;
	Vector2 distance;
	Vector2 InitialPos;
	Vector2 futurePos;
	Texture* mTexture; // textura de la tile

	Vector2 PlayerPos;
	int mIndex;

protected:
	void HandleStates(); // para constrolar los estadps
	virtual void HandleSeekState();
	virtual void HandleEvadeState(Vector2 PlayerPos);
	virtual void HandleFleeState();
	virtual void HandlePursuitState();
	virtual void HandleArriveState();
	virtual void HandleWanderState();
	virtual void HandleObstacleState();
	virtual void HandleWallState();
	virtual void HandleInterposeState();
	virtual void HandleHideState();
	virtual void HandlePathState();
	virtual void HandleOffsetState();

	void RenderStates(); // para constrolar el render segun los estados
	virtual void RenderSeekState();
	virtual void RenderEvadeState();
	virtual void RenderFleeState();
	virtual void RenderPursuitState();
	virtual void RenderArriveState();
	virtual void RenderWanderState();
	virtual void RenderObstacleState();
	virtual void RenderWallState();
	virtual void RenderInterposeState();
	virtual void RenderHideState();
	virtual void RenderPathState();
	virtual void RenderOffsetState();

public:
	Vector2 Pos;

	Enemy(); // constructor
	virtual ~Enemy(); // destructor

	void changeState(int state); // funcion para cambiar el estado

	States CurrentState(); // regresa el estado
	States getState(int state); // para sacar un estado

	void GetPlayerPos(Vector2 player) { PlayerPos = player; };

	void Update(Vector2 player); // update

	virtual void Render(); // render
};

#endif