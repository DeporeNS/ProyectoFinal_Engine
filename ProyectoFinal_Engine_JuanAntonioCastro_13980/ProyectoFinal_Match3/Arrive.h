#ifndef _ARRIVE_H
#define _ARRIVE_H

#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Player.h"
#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <sstream> 

using namespace ProyectoFinal;

class Arrive : public GameEntity {
private:
	// Entidad de la parte de arriba
	GameEntity* mTopBar;
	Texture* nubes;
	float nubesPosX = 0;
	bool forward = true;

	// Entidades del fondo y fullscreen
	GameEntity* mFondo;
	Texture* fondo;
	Player* mPlayer;

	// Entidades de logo
	Texture* mLogo;
	Texture* mLogo2;
	Texture* mLogo3;
	int LogoColor;
	int LogoColorSecs = 0;

	//Entidades del menu
	GameEntity* mMenu;
	Texture* ButtonMainMenu;
	Texture* ButtonMuteMusic;
	Texture* ButtonExitGame;
	Texture* MainMenu;
	Texture* MainMenu2;
	Texture* MuteMusic;
	Texture* MuteMusic2;
	Texture* ExitGame;
	Texture* ExitGame2;
	bool NewGameColor = true;
	bool HighScoresColor = true;
	bool MuteMusicColor = true;
	bool ExitGameColor = true;

	//Managers
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudioMgr;

	bool play = true; // To know if music is playing or not

public:

	Arrive(); // constructor
	~Arrive(); // destructor

	int mSelectedMode = 0; // cambie de pantalla

	void Update(); // Update de la pantalla de inicio

	void Render(); // Render de la pantalla de inicio

	void exitGame(); // para salir del juego
};

#endif
