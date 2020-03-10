#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace ProyectoFinal;

class StartScreen : public GameEntity {	
private:
	// Entidad de la parte de arriba
	GameEntity* mTopBar;
	Texture* nubes;
	float nubesPosX = 0;
	bool forward = true; 

	// Entidades del fondo y fullscreen
	GameEntity* mFondo;
	Texture* fondo;

	// Entidades de logo
	Texture* mLogo;
	Texture* mLogo2;
	Texture* mLogo3;
	int LogoColor;
	int LogoColorSecs = 0;

	//Entidades del menu
	GameEntity* mMenu;
	Texture* ButtonArrive;
	Texture* ButtonEvade;
	Texture* ButtonFlee;
	Texture* ButtonHide;
	Texture* ButtonInterpose;
	Texture* ButtonObstacle;
	Texture* ButtonOffset;
	Texture* ButtonPath;
	Texture* ButtonPursuit;
	Texture* ButtonSeek;
	Texture* ButtonWall;
	Texture* ButtonWander;
	Texture* ButtonMuteMusic;
	Texture* ButtonExitGame;
	Texture* Arrive;
	Texture* Arrive2;
	Texture* Evade;
	Texture* Evade2;
	Texture* Flee;
	Texture* Flee2;
	Texture* Hide;
	Texture* Hide2;
	Texture* Interpose;
	Texture* Interpose2;
	Texture* Obstacle;
	Texture* Obstacle2;
	Texture* Offset;
	Texture* Offset2;
	Texture* Path;
	Texture* Path2;
	Texture* Pursuit;
	Texture* Pursuit2;
	Texture* Seek;
	Texture* Seek2;
	Texture* Wall;
	Texture* Wall2;
	Texture* Wander;
	Texture* Wander2;
	Texture* MuteMusic;
	Texture* MuteMusic2;
	Texture* ExitGame;
	Texture* ExitGame2;
	bool ArriveColor = true;
	bool EvadeColor = true;
	bool FleeColor = true;
	bool HideColor = true;
	bool InterposeColor = true;
	bool ObstacleColor = true;
	bool OffsetColor = true;
	bool PathColor = true;
	bool PursuitColor = true;
	bool SeekColor = true;
	bool WallColor = true;
	bool WanderColor = true;
	bool MuteMusicColor = true;
	bool ExitGameColor = true;

	//Managers
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudioMgr;

	bool play = true; // To know if music is playing or not

public:

	StartScreen(); // constructor
	~StartScreen(); // destructor

	int mSelectedMode = 0; // cambie de pantalla
	int SelectedMode(); // cambie de pantalla

	void Update(); // Update de la pantalla de inicio

	void Render(); // Render de la pantalla de inicio

	void exitGame(); // para salir del juego
};

#endif