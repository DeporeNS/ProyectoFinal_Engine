// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UGHmS70UdH4&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=17
#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H

#include "Arrive.h"
#include "Evade.h"
#include "Flee.h"
#include "Hide.h"
#include "Interpose.h"
#include "Obstacle.h"
#include "Offset.h"
#include "Path.h"
#include "Pursuit.h"
#include "Seek.h"
#include "Wall.h"
#include "Wander.h"
#include "StartScreen.h"

// clase para manejar las pantallas
class ScreenManager {
private:
	enum SCREENS {start, seek, evade, flee, pursuit, arrive, wander, obstacle, wall, interpose, hide, path, offset}; // cuales pantallas hay en el juego

	// singleton
	static ScreenManager* sInstance;

	//managers
	InputManager* mInput;
	Timer* mTimer;

	// para salir de game over
	int sec;

	//pantallas
	StartScreen* mStartScreen;
	Arrive* mArrive;
	Evade* mEvade;
	Flee* mFlee;
	Hide* mHide;
	Interpose* mInterpose;
	Obstacle* mObstacle;
	Offset* mOffset;
	Path* mPath;
	Pursuit* mPursuit;
	Seek* mSeek;
	Wall* mWall;
	Wander* mWander;


	SCREENS mCurrentScreen; // pantalla actual

public:
	static ScreenManager* Instance(); // Para crear la intancia de la clase
	static void Release(); // para sacar de la memoria la instancia de la clase

	void Update(); // Actualiza
	void Render(); // Render

private:
	ScreenManager(); // constructor
	~ScreenManager(); // destructor

};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UGHmS70UdH4&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=17