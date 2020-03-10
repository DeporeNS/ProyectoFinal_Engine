#ifndef _PLAYER_H
#define _PLAYER_H

#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "AudioManager.h"
#include <list>

using namespace ProyectoFinal;

// Clase para el player
class Player : public GameEntity {
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

	float maxSpeed = 3;
	float ahead;
	float magnitud;
	float TargetX;
	float TargetY;
	int i = 0;

	Vector2 Points[5];
	Vector2 Avoid;
	Vector2 Pos2;
	Vector2 EnemyLocation;
	Vector2 Point1;
	Vector2 Point2;
	Vector2 Point3;
	Vector2 Point4;
	Vector2 Point5;
	Vector2 TargetPos;
	Vector2 normal;
	Vector2 dVel;
	Vector2 steering;
	Vector2 clampedV;
	Vector2 distance;
	Vector2 InitialPos;
	Vector2 futurePos;
	Texture* mTexture; // textura de la tile
	int mIndex;

protected:
	void HandleStates(); // para constrolar los estadps
	virtual void HandleSeekState();
	virtual void HandleEvadeState();
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

	Player(); // constructor
	virtual ~Player(); // destructor

	void changeState(int state); // funcion para cambiar el estado

	States CurrentState(); // regresa el estado
	States getState(int state); // para sacar un estado

	void Update(); // update

	virtual void Render(); // render
};

#endif
