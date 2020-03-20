#include "Tiles.h"

// constructor
Tiles::Tiles(int index) {
	mInput = InputManager::Instance();

	mTexture[0] = nullptr;
	mTexture[1] = nullptr;
	mTexture[2] = nullptr;
	mTexture[3] = nullptr;
	mTexture[4] = nullptr;
	mTexture[5] = nullptr;
	mAnimatedTexture = nullptr;
	mIndex = index;
}

Tiles::Tiles() {
}

// destructor
Tiles::~Tiles() {
	mInput = NULL;

	for (int i = 0; i < 2; i++) {
		delete mTexture[i];
		mTexture[i] = NULL;
	}
}

// funcion para manejar el estado de una Tile normal
void Tiles::HandleNormalState() {
	if (mInput->MousePos().x >= this->Pos().x - 57.2f && mInput->MousePos().y >= this->Pos().y - 57.2f && mInput->MousePos().x <= this->Pos().x + 57.2f && mInput->MousePos().y <= this->Pos().y + 57.2f) {
		//if (mInput->MouseButtonPressed(InputManager::left)) {
		//	//mAudioMgr->PlaySFX("Button_Click.wav");
		//	mCurrentState = selected;
		//}
		mCurrentState = over;
	}
}

// funcion para manejar el estado de una tile seleccionada
void Tiles::HandleSelectedState() {
	if (mInput->MouseButtonPressed(InputManager::left)) {
		//mAudioMgr->PlaySFX("Button_Click.wav");
		mCurrentState = normal;
	}
}

// funcion para manejar el estado de una tile destruida
void Tiles::HandleDestroyState() {

}

// funcion para manejar el estado de una tile cuando el mouse esta sobre ella
void Tiles::HandleOverState() {
	inside = false;
	if (mInput->MousePos().x >= this->Pos().x - 57.2f && mInput->MousePos().y >= this->Pos().y - 57.2f && mInput->MousePos().x <= this->Pos().x + 57.2f && mInput->MousePos().y <= this->Pos().y + 57.2f) {
		inside = true;
	}
	if (inside == false) {
		mCurrentState = normal;
	}
	if (mInput->MouseButtonPressed(InputManager::left)) {
		//mAudioMgr->PlaySFX("Button_Click.wav");
		mCurrentState = selected;
	}
}

// funcion para manejar el estado de una Tile normal
void Tiles::RenderNormalState() {
	mTexture[0]->Render();
}

// funcion para manejar el estado de una tile seleccionada
void Tiles::RenderSelectedState() {
	mTexture[1]->Render();
}

// funcion para manejar el estado de una tile destruida
void Tiles::RenderDestroyState() {
	time++;
	if (time < 60) {
		mTexture[3]->Render();
	}
	else if (time < 120) {
		mTexture[4]->Render();
	}
	else if (time < 180) {
		mTexture[5]->Render();
	}
	else {
		time = 0;
	}
}

// funcion para manejar el estado de una tile cuando el mouse esta sobre ella
void Tiles::RenderOverState() {
	mTexture[2]->Render();
}

// Funcion para manejar los estados de las tiles
void Tiles::HandleStates() {
	switch (mCurrentState) {
	case normal:
		HandleNormalState();
		break;

	case selected:
		HandleSelectedState();
		break;

	case destroy:
		HandleDestroyState();
		break;

	case over:
		HandleOverState();
		break;
	}
}

// funcion para hacer render segun el estado
void Tiles::RenderStates() {
	switch (mCurrentState) {
	case normal:
		RenderNormalState();
		break;

	case selected:
		RenderSelectedState();
		break;

	case destroy:
		RenderDestroyState();
		break;

	case over:
		RenderOverState();
		break;
	}
}

// regresa el estado de la tile
Tiles::States Tiles::CurrentState() {

	return mCurrentState;
}

// Regresa el tipo de tile
Tiles::TilesType Tiles::Type() {

	return mType;
}

// Regresa un indice de 1 a 5 segun el tipo de tile
int Tiles::GetIndex() {

	return mIndex;
}

// Update
void Tiles::Update() {

	if (Active())
		HandleStates();

}

// Render
void Tiles::Render() {

	if (Active())
		RenderStates();
}

// funcion para cambiar el estado
void Tiles::changeState(int state) {
	if (state == 1) {
		mCurrentState = normal;
	}
	else if (state == 2) {
		mCurrentState = selected;
	}
	else if (state == 3) {
		mCurrentState = destroy;
	}
	else if (state == 4) {
		mCurrentState = over;
	}
}

// funcion para cambiar el estado
Tiles::States Tiles::getState(int state) {
	if (state == 1) {
		return normal;
	}
	else if (state == 2) {
		return selected;
	}
	else if (state == 3) {
		return destroy;
	}
	else if (state == 4) {
		return over;
	}
}



