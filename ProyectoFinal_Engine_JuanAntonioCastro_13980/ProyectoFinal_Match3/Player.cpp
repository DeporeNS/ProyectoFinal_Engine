#include "Player.h"

// constructor
Player::Player() {
	mInput = InputManager::Instance();
	mTexture = new Texture("Tile1.png");
	mTexture->Parent(this);
	InitialPos.x = 860;
	InitialPos.y = 510;
	mTexture->Pos(InitialPos);
	EnemyLocation.x = 920;
	EnemyLocation.y = 510;
	TargetX = rand() % 1650 + 70;
	TargetY = rand() % 950 + 80;
	mInput = InputManager::Instance();
	Point1.y = 500;
	Point1.x = 1600;
	Points[0] = Point1;
	Point2.y = 300;
	Point2.x = 1350;
	Points[1] = Point2;
	Point3.y = 700;
	Point3.x = 1100;
	Points[2] = Point3;
	Point4.y = 300;
	Point4.x = 850;
	Points[3] = Point4;
	Point5.y = 500;
	Point5.x = 600;
	Points[4] = Point5;
}

// destructor
Player::~Player() {
	mInput = NULL;

	delete mTexture;
	mTexture = NULL;
}

// funcion para manejar el estado de Seek
void Player::HandleSeekState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

	normal = Pos.normalizeVector(TargetPos, Pos);
	dVel = normal * maxSpeed;
	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering >= maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	Pos += clampedV;
	mTexture->Pos(Pos);
}

// funcion para manejar el estado de Evade que es lo mismo que el flee
// pero con una posicion futura
void Player::HandleEvadeState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

	normal = Pos.normalizeVector(TargetPos, Pos);
	dVel = normal * (maxSpeed + 3);
	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering >= maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	Pos += clampedV;
	mTexture->Pos(Pos);
}

// funcion para manejar estado flee, es casi lo mismo que seek pero
// a la hora de sacar la normal de los vectores de posicion del mouse y target
// los inviertes para que el lugar de seguir huya
void Player::HandleFleeState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();
	normal = Pos.normalizeVector(Pos, TargetPos);
	dVel = normal * maxSpeed;
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering > maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	Pos += clampedV;

	mTexture->Pos(Pos);
}

void Player::HandlePursuitState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

	normal = Pos.normalizeVector(TargetPos, Pos);
	dVel = normal * maxSpeed;
	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering >= maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	Pos += clampedV;
	mTexture->Pos(Pos);
}

void Player::HandleArriveState() {
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

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
		//else if (steering >= maxSpeed) {
		//	clampedV = maxSpeed;
		//}

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
		//else if (steering >= (maxSpeed - 1)) {
		//	clampedV = (maxSpeed - 1);
		//}

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
		//else if (steering >= (maxSpeed - 2)) {
		//	clampedV = (maxSpeed - 1);
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
}

void Player::HandleWanderState() {
	if (Pos.x >= TargetPos.x - 180.0f && Pos.y >= TargetPos.y - 50.0f && Pos.x <= TargetPos.x + 180.0f && Pos.y <= TargetPos.y + 50.0f) {
		TargetX = rand() % 1650 + 70;
		TargetY = rand() % 950 + 80;
	}

	TargetPos.x = TargetX;
	TargetPos.y = TargetY;

	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();

	normal = Pos.normalizeVector(TargetPos, Pos);
	dVel = normal * maxSpeed;
	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering >= maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	Pos += clampedV;
	mTexture->Pos(Pos);
}

void Player::HandleObstacleState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

	distance = EnemyLocation - Pos;
	magnitud = EnemyLocation.Magnitude();
	normal = Pos.normalizeVector(TargetPos, Pos);
	dVel = normal * maxSpeed;

	Avoid = EnemyLocation - Pos;
	Avoid = Avoid.Normalized() * 4;

	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	steering = dVel - Pos;
	if (steering.x != Pos.x || steering.y != Pos.y) {
		clampedV = steering + Pos;
	}
	//else if (steering >= maxSpeed) {
	//	clampedV = maxSpeed;
	//}

	if (distance <= 100) {
		Pos += clampedV - Avoid;
	}
	else {
		Pos += clampedV;
	}
	mTexture->Pos(Pos);
}

void Player::HandleWallState() {

}

void Player::HandleInterposeState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

	distance = TargetPos - Pos;
	magnitud = distance.Magnitude();

	//vector para dar vuelta dependiendo de la velocidad maxima y el vector
	//posicion que simula la velocidad actual
	if (magnitud > 500) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * maxSpeed;

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		//else if (steering >= maxSpeed) {
		//	clampedV = maxSpeed;
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
}

void Player::HandleHideState() {

}

void Player::HandlePathState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();

	TargetPos = Points[i];

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
		//else if (steering >= maxSpeed) {
		//	clampedV = maxSpeed;
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else if (i == 4) {
		i = 0;
	}
	else {
		i++;
	}
}

void Player::HandleOffsetState() {
	// variables que guardan la posicion del robot y del mouse
	Pos = mTexture->Pos();
	TargetPos = mInput->MousePos();

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
		//else if (steering >= maxSpeed) {
		//	clampedV = maxSpeed;
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else if (magnitud > 150) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * (maxSpeed - 1);

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		//else if (steering >= (maxSpeed - 1)) {
		//	clampedV = (maxSpeed - 1);
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else if (magnitud > 100) {
		normal = Pos.normalizeVector(TargetPos, Pos);
		dVel = normal * (maxSpeed - 2);

		steering = dVel - Pos;
		if (steering.x != Pos.x || steering.y != Pos.y) {
			clampedV = steering + Pos;
		}
		//else if (steering >= (maxSpeed - 2)) {
		//	clampedV = (maxSpeed - 1);
		//}

		Pos += clampedV;
		mTexture->Pos(Pos);
	}
	else {

	}
}

// funcion para manejar el estado de Seek
void Player::RenderSeekState() {
	mTexture->Render();
}

// funcion para manejar el estado de Evade
void Player::RenderEvadeState() {
	mTexture->Render();
}

void Player::RenderFleeState() {
	mTexture->Render();
}

void Player::RenderPursuitState() {
	mTexture->Render();
}

void Player::RenderArriveState() {
	mTexture->Render();
}

void Player::RenderWanderState() {
	mTexture->Render();
}

void Player::RenderObstacleState() {
	mTexture->Render();
}

void Player::RenderWallState() {
	mTexture->Render();
}

void Player::RenderInterposeState() {
	mTexture->Render();
}

void Player::RenderHideState() {
	mTexture->Render();
}

void Player::RenderPathState() {
	mTexture->Render();
}

void Player::RenderOffsetState() {
	mTexture->Render();
}

// Funcion para manejar los estados de las tiles
void Player::HandleStates() {
	switch (mCurrentState) {
	case seek:
		HandleSeekState();
		break;

	case evade:
		HandleEvadeState();
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
void Player::RenderStates() {
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
Player::States Player::CurrentState() {

	return mCurrentState;
}


// Update
void Player::Update() {

	if (Active())
		HandleStates();

}

// Render
void Player::Render() {

	if (Active())
		RenderStates();
}

// funcion para cambiar el estado
void Player::changeState(int state) {
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
Player::States Player::getState(int state) {
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