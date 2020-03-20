#include "Enemy.h"

// constructor
Enemy::Enemy() {
	mInput = InputManager::Instance();
	mTexture = new Texture("Tile5.png");
	mTexture->Parent(this);
	InitialPos.x = 920;
	InitialPos.y = 510;
	ScaleObstacle.x = 1.5;
	ScaleObstacle.y = 1.5;
	mTexture->Pos(InitialPos);
	mInput = InputManager::Instance();
}

// destructor
Enemy::~Enemy() {
	mInput = NULL;

	delete mTexture;
	mTexture = NULL;
}

// funcion para manejar el estado de Seek
void Enemy::HandleSeekState() {
}

// funcion para manejar el estado de Evade que es lo mismo que el flee
// pero con una posicion futura
void Enemy::HandleEvadeState(Vector2 PlayerPos) {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	//TargetPos = mInput->MousePos();

	distance = Pos - PlayerPos;
	ahead = 10/*distance.Magnitude() / maxSpeed*/;
	futurePos = PlayerPos + 30 /* ahead*/;

	normal = Pos.normalizeVector(Pos, futurePos);
	dVel = normal * maxSpeed;
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	else if (steering > maxSpeed) {
		clampedV = maxSpeed;
	}

	Pos += clampedV;

	if (Pos.x < 0 || Pos.x > 1720 || Pos.y < 0 || Pos.y >1024) {
		mTexture->Pos(InitialPos);
	}
	else {
		mTexture->Pos(Pos);
	}
}

// funcion para manejar estado flee
void Enemy::HandleFleeState() {
}

void Enemy::HandlePursuitState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	//TargetPos = mInput->MousePos();

	distance = Pos - PlayerPos;
	ahead = 10/*distance.Magnitude() / maxSpeed*/;
	futurePos = PlayerPos + 30 /* ahead*/;

	normal = Pos.normalizeVector(futurePos, Pos);
	dVel = normal * maxSpeed;
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	else if (steering > maxSpeed) {
		clampedV = maxSpeed;
	}

	Pos += clampedV;

	if (Pos.x < 0 || Pos.x > 1720 || Pos.y < 0 || Pos.y >1024) {
		mTexture->Pos(InitialPos);
	}
	else {
		mTexture->Pos(Pos);
	}
}

void Enemy::HandleArriveState() {

}

void Enemy::HandleWanderState() {

}

void Enemy::HandleObstacleState() {
	mTexture->Scale(ScaleObstacle);
}

void Enemy::HandleWallState() {

}

void Enemy::HandleInterposeState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	MousePos = mInput->MousePos();

	PlayerDirection = MousePos - PlayerPos;
	PlayerDirection = PlayerDirection / 2;

	TargetPos = MousePos - PlayerDirection;

	distance = TargetPos - Pos;
	magnitud = distance.Magnitude();

	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	if (magnitud > 5) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * maxSpeed;

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		else if (steering >= maxSpeed) {
			clampedV = maxSpeed;
		}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
}

void Enemy::HandleHideState() {

}

void Enemy::HandlePathState() {

}

void Enemy::HandleOffsetState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = PlayerPos;
	MousePos = mInput->MousePos();

	PlayerDirection = MousePos - PlayerPos;
	PlayerDirection = PlayerDirection.Normalized();
	behind = PlayerDirection * 200;
	TargetPos = PlayerPos - behind;

	maxSpeed = 4;

	distance = TargetPos - Pos;
	magnitud = distance.Magnitude();

	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	if (magnitud > 400) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * maxSpeed;

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		else if (steering >= maxSpeed) {
			clampedV = maxSpeed;
		}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else if (magnitud > 250) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * (maxSpeed - 1);

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		else if (steering >= (maxSpeed - 1)) {
			clampedV = (maxSpeed - 1);
		}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else if (magnitud > 10) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * (maxSpeed - 2);

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		else if (steering >= (maxSpeed - 2)) {
			clampedV = (maxSpeed - 1);
		}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else {

	}
}

// funcion para manejar el estado de Seek
void Enemy::RenderSeekState() {
	mTexture->Render();
}

// funcion para manejar el estado de Evade
void Enemy::RenderEvadeState() {
	mTexture->Render();
}

void Enemy::RenderFleeState() {
	mTexture->Render();
}

void Enemy::RenderPursuitState() {
	mTexture->Render();
}

void Enemy::RenderArriveState() {
	mTexture->Render();
}

void Enemy::RenderWanderState() {
	mTexture->Render();
}

void Enemy::RenderObstacleState() {
	mTexture->Render();
}

void Enemy::RenderWallState() {
	mTexture->Render();
}

void Enemy::RenderInterposeState() {
	mTexture->Render();
}

void Enemy::RenderHideState() {
	mTexture->Render();
}

void Enemy::RenderPathState() {
	mTexture->Render();
}

void Enemy::RenderOffsetState() {
	mTexture->Render();
}

// Funcion para manejar los estados de las tiles
void Enemy::HandleStates() {
	switch (mCurrentState) {
	case seek:
		HandleSeekState();
		break;

	case evade:
		HandleEvadeState(PlayerPos);
		break;

	case flee:
		HandleFleeState();
		break;

	case pursuit:
		HandlePursuitState();
		break;

	case arrive:
		HandleArriveState();
		break;

	case wander:
		HandleWanderState();
		break;

	case obstacle:
		HandleObstacleState();
		break;

	case wall:
		HandleWallState();
		break;

	case interpose:
		HandleInterposeState();
		break;

	case hide:
		HandleHideState();
		break;

	case path:
		HandlePathState();
		break;

	case offset:
		HandleOffsetState();
		break;
	}
}

// funcion para hacer render segun el estado
void Enemy::RenderStates() {
	switch (mCurrentState) {
	case seek:
		RenderSeekState();
		break;

	case evade:
		RenderEvadeState();
		break;

	case flee:
		RenderFleeState();
		break;

	case pursuit:
		RenderPursuitState();
		break;

	case arrive:
		RenderArriveState();
		break;

	case wander:
		RenderWanderState();
		break;

	case obstacle:
		RenderObstacleState();
		break;

	case wall:
		RenderWallState();
		break;

	case interpose:
		RenderInterposeState();
		break;

	case hide:
		RenderHideState();
		break;

	case path:
		RenderPathState();
		break;

	case offset:
		RenderOffsetState();
		break;
	}
}

// regresa el estado de la tile
Enemy::States Enemy::CurrentState() {

	return mCurrentState;
}


// Update
void Enemy::Update(Vector2 player) {
	GetPlayerPos(player);

	if (Active())
		HandleStates();

}

// Render
void Enemy::Render() {

	if (Active())
		RenderStates();
}

// funcion para cambiar el estado
void Enemy::changeState(int state) {
	if (state == 1) {
		mCurrentState = seek;
	}
	else if (state == 2) {
		mCurrentState = evade;
	}
	else if (state == 3) {
		mCurrentState = flee;
	}
	else if (state == 4) {
		mCurrentState = pursuit;
	}
	else if (state == 5) {
		mCurrentState = arrive;
	}
	else if (state == 6) {
		mCurrentState = wander;
	}
	else if (state == 7) {
		mCurrentState = obstacle;
	}
	else if (state == 8) {
		mCurrentState = wall;
	}
	else if (state == 9) {
		mCurrentState = interpose;
	}
	else if (state == 10) {
		mCurrentState = hide;
	}
	else if (state == 11) {
		mCurrentState = path;
	}
	else if (state == 12) {
		mCurrentState = offset;
	}
}

// funcion para cambiar el estado
Enemy::States Enemy::getState(int state) {
	if (state == 1) {
		return seek;
	}
	else if (state == 2) {
		return evade;
	}
	else if (state == 3) {
		mCurrentState = flee;
	}
	else if (state == 4) {
		mCurrentState = pursuit;
	}
	else if (state == 5) {
		mCurrentState = arrive;
	}
	else if (state == 6) {
		mCurrentState = wander;
	}
	else if (state == 7) {
		mCurrentState = obstacle;
	}
	else if (state == 8) {
		mCurrentState = wall;
	}
	else if (state == 9) {
		mCurrentState = interpose;
	}
	else if (state == 10) {
		mCurrentState = hide;
	}
	else if (state == 11) {
		mCurrentState = path;
	}
	else if (state == 12) {
		mCurrentState = offset;
	}
}