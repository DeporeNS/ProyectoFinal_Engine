#include "StartScreen.h"

// Constructor
StartScreen::StartScreen() {
	// Barra de arriba Entities
	mTopBar = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 120.0f);
	nubes = new Texture("Nubes.png");	
	nubes->Parent(mTopBar);
	nubes->Pos(Vector2(nubesPosX, 0));
	mTopBar->Parent(this);

	//Fondo
	mFondo = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.5f);
	fondo = new Texture("MenuFondo.png");
	fondo->Parent(mFondo);
	fondo->Pos(VEC2_ZERO);
	mFondo->Parent(this);

	//Logo
	mLogo = new Texture("S. Behaviors", "Lazer84.TTF", 200, { 170, 0, 0 });
	mLogo2 = new Texture("S. Behaviors", "Lazer84.TTF", 200, { 170, 81, 0 });
	mLogo3 = new Texture("S. Behaviors", "Lazer84.TTF", 200, { 170, 157, 0 });
	mLogo->Parent(this);
	mLogo2->Parent(this);
	mLogo3->Parent(this);
	mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.20f));
	mLogo2->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.20f));
	mLogo3->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.20f));

	//Menu
	mMenu = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.6f);
	Arrive = new Texture("Arrive", "ARCADE.TTF", 72, { 0, 0, 0, });
	Arrive2 = new Texture("Arrive", "ARCADE.TTF", 72, { 170, 0, 0, });
	Evade = new Texture("Evade", "ARCADE.TTF", 72, { 0, 0, 0, });
	Evade2 = new Texture("Evade", "ARCADE.TTF", 72, { 170, 0, 0, });
	Flee = new Texture("Flee", "ARCADE.TTF", 72, { 0, 0, 0, });
	Flee2 = new Texture("Flee", "ARCADE.TTF", 72, { 170, 0, 0, });
	Hide = new Texture("Hide", "ARCADE.TTF", 72, { 0, 0, 0, });
	Hide2 = new Texture("Hide", "ARCADE.TTF", 72, { 170, 0, 0, });
	Interpose = new Texture("Interpose", "ARCADE.TTF", 72, { 0, 0, 0, });
	Interpose2 = new Texture("Interpose", "ARCADE.TTF", 72, { 170, 0, 0, });
	Obstacle = new Texture("Obstacle", "ARCADE.TTF", 72, { 0, 0, 0, });
	Obstacle2 = new Texture("Obstacle", "ARCADE.TTF", 72, { 170, 0, 0, });
	Offset = new Texture("Offset", "ARCADE.TTF", 72, { 0, 0, 0, });
	Offset2 = new Texture("Offset", "ARCADE.TTF", 72, { 170, 0, 0, });
	Path = new Texture("Path", "ARCADE.TTF", 72, { 0, 0, 0, });
	Path2 = new Texture("Path", "ARCADE.TTF", 72, { 170, 0, 0, });
	Pursuit = new Texture("Pursuit", "ARCADE.TTF", 72, { 0, 0, 0, });
	Pursuit2 = new Texture("Pursuit", "ARCADE.TTF", 72, { 170, 0, 0, });
	Seek = new Texture("Seek", "ARCADE.TTF", 72, { 0, 0, 0, });
	Seek2 = new Texture("Seek", "ARCADE.TTF", 72, { 170, 0, 0, });
	Wall = new Texture("Wall", "ARCADE.TTF", 72, { 0, 0, 0, });
	Wall2 = new Texture("Wall", "ARCADE.TTF", 72, { 170, 0, 0, });
	Wander = new Texture("Wander", "ARCADE.TTF", 72, { 0, 0, 0, });
	Wander2 = new Texture("Wander", "ARCADE.TTF", 72, { 170, 0, 0, });
	MuteMusic = new Texture("Mute Music", "ARCADE.TTF", 72, { 0, 0, 0, });
	MuteMusic2 = new Texture("Mute Music", "ARCADE.TTF", 72, { 170, 0, 0, });
	ExitGame = new Texture("Exit Game", "ARCADE.TTF", 72, { 0, 0, 0, });
	ExitGame2 = new Texture("Exit Game", "ARCADE.TTF", 72, { 170, 0, 0, });
	ButtonArrive = new Texture("Button.png");
	ButtonEvade = new Texture("Button.png");
	ButtonFlee = new Texture("Button.png");
	ButtonHide = new Texture("Button.png");
	ButtonInterpose = new Texture("Button.png");
	ButtonObstacle = new Texture("Button.png");
	ButtonOffset = new Texture("Button.png");
	ButtonPath = new Texture("Button.png");
	ButtonPursuit = new Texture("Button.png");
	ButtonSeek = new Texture("Button.png");
	ButtonWall = new Texture("Button.png");
	ButtonWander = new Texture("Button.png");
	ButtonMuteMusic = new Texture("Button.png");
	ButtonExitGame = new Texture("Button.png");
	ButtonArrive->Parent(mMenu);
	ButtonEvade->Parent(mMenu);
	ButtonFlee->Parent(mMenu);
	ButtonHide->Parent(mMenu);
	ButtonInterpose->Parent(mMenu);
	ButtonObstacle->Parent(mMenu);
	ButtonOffset->Parent(mMenu);
	ButtonPath->Parent(mMenu);
	ButtonPursuit->Parent(mMenu);
	ButtonSeek->Parent(mMenu);
	ButtonWall->Parent(mMenu);
	ButtonWander->Parent(mMenu);
	ButtonMuteMusic->Parent(mMenu);
	ButtonExitGame->Parent(mMenu);
	Arrive->Parent(ButtonArrive);
	Arrive2->Parent(ButtonArrive);
	Evade->Parent(ButtonEvade);
	Evade2->Parent(ButtonEvade);
	Flee->Parent(ButtonFlee);
	Flee2->Parent(ButtonFlee);
	Hide->Parent(ButtonHide);
	Hide2->Parent(ButtonHide);
	Interpose->Parent(ButtonInterpose);
	Interpose2->Parent(ButtonInterpose);
	Obstacle->Parent(ButtonObstacle);
	Obstacle2->Parent(ButtonObstacle);
	Offset->Parent(ButtonOffset);
	Offset2->Parent(ButtonOffset);
	Path->Parent(ButtonPath);
	Path2->Parent(ButtonPath);
	Pursuit->Parent(ButtonPursuit);
	Pursuit2->Parent(ButtonPursuit);
	Seek->Parent(ButtonSeek);
	Seek2->Parent(ButtonSeek);
	Wall->Parent(ButtonWall);
	Wall2->Parent(ButtonWall);
	Wander->Parent(ButtonWander);
	Wander2->Parent(ButtonWander);
	MuteMusic->Parent(ButtonMuteMusic);
	MuteMusic2->Parent(ButtonMuteMusic);
	ExitGame->Parent(ButtonExitGame);
	ExitGame2->Parent(ButtonExitGame);
	ButtonArrive->Pos(Vector2(-500, -190));
	ButtonArrive->Scale(Vector2(1.5, 1));
	ButtonEvade->Pos(Vector2(-500, -60));
	ButtonEvade->Scale(Vector2(1.5, 1));
	ButtonFlee->Pos(Vector2(-500, 70));
	ButtonFlee->Scale(Vector2(1.5, 1));
	ButtonHide->Pos(Vector2(-500, 200));
	ButtonHide->Scale(Vector2(1.5, 1));
	ButtonInterpose->Pos(Vector2(-500, 330));
	ButtonInterpose->Scale(Vector2(1.5, 1));
	ButtonObstacle->Pos(Vector2(0, -190));
	ButtonObstacle->Scale(Vector2(1.5, 1));
	ButtonOffset->Pos(Vector2(0, -60));
	ButtonOffset->Scale(Vector2(1.5, 1));
	ButtonPath->Pos(Vector2(0, 70));
	ButtonPath->Scale(Vector2(1.5, 1));
	ButtonPursuit->Pos(Vector2(0, 200));
	ButtonPursuit->Scale(Vector2(1.5, 1));
	ButtonSeek->Pos(Vector2(0, 330));
	ButtonSeek->Scale(Vector2(1.5, 1));
	ButtonWall->Pos(Vector2(500, -190));
	ButtonWall->Scale(Vector2(1.5, 1));
	ButtonWander->Pos(Vector2(500, -60));
	ButtonWander->Scale(Vector2(1.5, 1));
	ButtonMuteMusic->Pos(Vector2(500, 200));
	ButtonMuteMusic->Scale(Vector2(1.5, 1));
	ButtonExitGame->Pos(Vector2(500, 330));
	ButtonExitGame->Scale(Vector2(1.5, 1));
	Arrive->Scale(Vector2(0.5, 1));
	Arrive2->Scale(Vector2(0.5, 1));
	Evade->Scale(Vector2(0.5, 1));
	Evade2->Scale(Vector2(0.5, 1));
	Flee->Scale(Vector2(0.5, 1));
	Flee2->Scale(Vector2(0.5, 1));
	Hide->Scale(Vector2(0.5, 1));
	Hide2->Scale(Vector2(0.5, 1));
	Interpose->Scale(Vector2(0.5, 1));
	Interpose2->Scale(Vector2(0.5, 1));
	Obstacle->Scale(Vector2(0.5, 1));
	Obstacle2->Scale(Vector2(0.5, 1));
	Offset->Scale(Vector2(0.5, 1));
	Offset2->Scale(Vector2(0.5, 1));
	Path->Scale(Vector2(0.5, 1));
	Path2->Scale(Vector2(0.5, 1));
	Pursuit->Scale(Vector2(0.5, 1));
	Pursuit2->Scale(Vector2(0.5, 1));
	Seek->Scale(Vector2(0.5, 1));
	Seek2->Scale(Vector2(0.5, 1));
	Wall->Scale(Vector2(0.5, 1));
	Wall2->Scale(Vector2(0.5, 1));
	Wander->Scale(Vector2(0.5, 1));
	Wander2->Scale(Vector2(0.5, 1));
	MuteMusic->Scale(Vector2(0.5, 1));
	MuteMusic2->Scale(Vector2(0.5, 1));
	ExitGame->Scale(Vector2(0.5, 1));
	ExitGame2->Scale(Vector2(0.5, 1));

	//Managers
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudioMgr = AudioManager::Instance();

	//Music
	mAudioMgr->PlayMusic("Music.wav");
}

// Destructor
StartScreen::~StartScreen() {
	// libera las entidades de la barra de arriba
	delete mTopBar;
	mTopBar = NULL;
	delete nubes;
	nubes = NULL;

	// libera el espacio del fondo
	delete mFondo;
	mFondo = NULL;
	delete fondo;
	fondo = NULL;

	// libera espacio del logo
	delete mLogo;
	mLogo = NULL;
	delete mLogo2;
	mLogo2 = NULL;
	delete mLogo3;
	mLogo3 = NULL;

	// libera el espacio del menu
	delete mMenu;
	mMenu = NULL;
	delete ButtonArrive;
	ButtonArrive = NULL;
	delete ButtonEvade;
	ButtonEvade = NULL;
	delete ButtonFlee;
	ButtonFlee = NULL;
	delete ButtonHide;
	ButtonHide = NULL;
	delete ButtonInterpose;
	ButtonInterpose = NULL;
	delete ButtonObstacle;
	ButtonObstacle = NULL;
	delete ButtonOffset;
	ButtonOffset = NULL;
	delete ButtonPath;
	ButtonPath = NULL;
	delete ButtonPursuit;
	ButtonPursuit = NULL;
	delete ButtonSeek;
	ButtonSeek = NULL;
	delete ButtonWall;
	ButtonWall = NULL;
	delete ButtonWander;
	ButtonWander = NULL;
	delete ButtonMuteMusic;
	ButtonMuteMusic = NULL;
	delete ButtonExitGame;
	ButtonExitGame = NULL;
	delete Arrive;
	Arrive = NULL;
	delete Evade;
	Evade = NULL;
	delete Flee;
	Flee = NULL;
	delete Hide;
	Hide = NULL;
	delete Interpose;
	Interpose = NULL;
	delete Obstacle;
	Obstacle = NULL;
	delete Offset;
	Offset = NULL;
	delete Path;
	Path = NULL;
	delete Pursuit;
	Pursuit = NULL;
	delete Seek;
	Seek = NULL;
	delete Wall;
	Wall = NULL;
	delete Wander;
	Wander = NULL;
	delete MuteMusic;
	MuteMusic = NULL;
	delete ExitGame;
	ExitGame = NULL;
	delete Arrive2;
	Arrive2 = NULL;
	delete Evade2;
	Evade2 = NULL;
	delete Flee2;
	Flee2 = NULL;
	delete Hide2;
	Hide2 = NULL;
	delete Interpose2;
	Interpose2 = NULL;
	delete Obstacle2;
	Obstacle2 = NULL;
	delete Offset2;
	Offset2 = NULL;
	delete Path2;
	Path2 = NULL;
	delete Pursuit2;
	Pursuit2 = NULL;
	delete Seek2;
	Seek2 = NULL;
	delete Wall2;
	Wall2 = NULL;
	delete Wander2;
	Wander2 = NULL;
	delete MuteMusic2;
	MuteMusic2 = NULL;
	delete ExitGame2;
	ExitGame2 = NULL;
}

// Update de la pantalla de inicio
void StartScreen::Update() {
	LogoColorSecs++;

	if (LogoColorSecs < 60) {
		LogoColor = 1;
	}
	else if (LogoColorSecs < 120) {
		LogoColor = 2;
	}
	else if (LogoColorSecs < 180) {
		LogoColor = 3;
	}
	else {
		LogoColor = 1;
		LogoColorSecs = 0;
	}

	if (nubesPosX > 150) {
		forward = false;
	}
	if (nubesPosX < -150) {
		forward = true;
	}
	if (forward == true) {
		nubesPosX = nubesPosX + 0.2;
	}
	else {
		nubesPosX = nubesPosX - 0.2;
	}

	if (mInput->MousePos().x >= ButtonArrive->Pos().x -180.0f && mInput->MousePos().y >= ButtonArrive->Pos().y - 50.0f && mInput->MousePos().x <= ButtonArrive->Pos().x + 180.0f && mInput->MousePos().y <= ButtonArrive->Pos().y + 50.0f) {
		ArriveColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 1;
		}
	}
	else {
		ArriveColor = true;
	}

	if (mInput->MousePos().x >= ButtonEvade->Pos().x - 180.0f && mInput->MousePos().y >= ButtonEvade->Pos().y - 50.0f && mInput->MousePos().x <= ButtonEvade->Pos().x + 180.0f && mInput->MousePos().y <= ButtonEvade->Pos().y + 50.0f) {
		EvadeColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 2;
		}
	}
	else {
		EvadeColor = true;
	}

	if (mInput->MousePos().x >= ButtonFlee->Pos().x - 180.0f && mInput->MousePos().y >= ButtonFlee->Pos().y - 50.0f && mInput->MousePos().x <= ButtonFlee->Pos().x + 180.0f && mInput->MousePos().y <= ButtonFlee->Pos().y + 50.0f) {
		FleeColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 3;
		}
	}
	else {
		FleeColor = true;
	}

	if (mInput->MousePos().x >= ButtonHide->Pos().x - 180.0f && mInput->MousePos().y >= ButtonHide->Pos().y - 50.0f && mInput->MousePos().x <= ButtonHide->Pos().x + 180.0f && mInput->MousePos().y <= ButtonHide->Pos().y + 50.0f) {
		HideColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 4;
		}
	}
	else {
		HideColor = true;
	}

	if (mInput->MousePos().x >= ButtonInterpose->Pos().x - 180.0f && mInput->MousePos().y >= ButtonInterpose->Pos().y - 50.0f && mInput->MousePos().x <= ButtonInterpose->Pos().x + 180.0f && mInput->MousePos().y <= ButtonInterpose->Pos().y + 50.0f) {
		InterposeColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 5;
		}
	}
	else {
		InterposeColor = true;
	}

	if (mInput->MousePos().x >= ButtonObstacle->Pos().x - 180.0f && mInput->MousePos().y >= ButtonObstacle->Pos().y - 50.0f && mInput->MousePos().x <= ButtonObstacle->Pos().x + 180.0f && mInput->MousePos().y <= ButtonObstacle->Pos().y + 50.0f) {
		ObstacleColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 6;
		}
	}
	else {
		ObstacleColor = true;
	}

	if (mInput->MousePos().x >= ButtonOffset->Pos().x - 180.0f && mInput->MousePos().y >= ButtonOffset->Pos().y - 50.0f && mInput->MousePos().x <= ButtonOffset->Pos().x + 180.0f && mInput->MousePos().y <= ButtonOffset->Pos().y + 50.0f) {
		OffsetColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 7;
		}
	}
	else {
		OffsetColor = true;
	}

	if (mInput->MousePos().x >= ButtonPath->Pos().x - 180.0f && mInput->MousePos().y >= ButtonPath->Pos().y - 50.0f && mInput->MousePos().x <= ButtonPath->Pos().x + 180.0f && mInput->MousePos().y <= ButtonPath->Pos().y + 50.0f) {
		PathColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 8;
		}
	}
	else {
		PathColor = true;
	}

	if (mInput->MousePos().x >= ButtonPursuit->Pos().x - 180.0f && mInput->MousePos().y >= ButtonPursuit->Pos().y - 50.0f && mInput->MousePos().x <= ButtonPursuit->Pos().x + 180.0f && mInput->MousePos().y <= ButtonPursuit->Pos().y + 50.0f) {
		PursuitColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 9;
		}
	}
	else {
		PursuitColor = true;
	}

	if (mInput->MousePos().x >= ButtonSeek->Pos().x - 180.0f && mInput->MousePos().y >= ButtonSeek->Pos().y - 50.0f && mInput->MousePos().x <= ButtonSeek->Pos().x + 180.0f && mInput->MousePos().y <= ButtonSeek->Pos().y + 50.0f) {
		SeekColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 10;
		}
	}
	else {
		SeekColor = true;
	}

	if (mInput->MousePos().x >= ButtonWall->Pos().x - 180.0f && mInput->MousePos().y >= ButtonWall->Pos().y - 50.0f && mInput->MousePos().x <= ButtonWall->Pos().x + 180.0f && mInput->MousePos().y <= ButtonWall->Pos().y + 50.0f) {
		WallColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 11;
		}
	}
	else {
		WallColor = true;
	}

	if (mInput->MousePos().x >= ButtonWander->Pos().x - 180.0f && mInput->MousePos().y >= ButtonWander->Pos().y - 50.0f && mInput->MousePos().x <= ButtonWander->Pos().x + 180.0f && mInput->MousePos().y <= ButtonWander->Pos().y + 50.0f) {
		WanderColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 12;
		}
	}
	else {
		WanderColor = true;
	}

	if (mInput->MousePos().x >= ButtonMuteMusic->Pos().x - 180.0f && mInput->MousePos().y >= ButtonMuteMusic->Pos().y - 50.0f && mInput->MousePos().x <= ButtonMuteMusic->Pos().x + 180.0f && mInput->MousePos().y <= ButtonMuteMusic->Pos().y + 50.0f) {
		MuteMusicColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			if (play == true) {
				mAudioMgr->PauseMusic();
				play = false;				
			}
			else{
				mAudioMgr->ResumeMusic();
				play = true;
			}
		}
	}
	else {
		MuteMusicColor = true;
	}

	if (mInput->MousePos().x >= ButtonExitGame->Pos().x - 180.0f && mInput->MousePos().y >= ButtonExitGame->Pos().y - 50.0f && mInput->MousePos().x <= ButtonExitGame->Pos().x + 180.0f && mInput->MousePos().y <= ButtonExitGame->Pos().y + 50.0f) {
		ExitGameColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			exitGame();
		}
	}
	else {
		ExitGameColor = true;
	}

	nubes->Pos(Vector2(nubesPosX, 0));
}

//Render de la pantalla de inicio
void StartScreen::Render() {
	fondo->Render();
	ButtonArrive->Render();
	ButtonEvade->Render();
	ButtonFlee->Render();
	ButtonHide->Render();
	ButtonInterpose->Render();
	ButtonObstacle->Render();
	ButtonOffset->Render();
	ButtonPath->Render();
	ButtonPursuit->Render();
	ButtonSeek->Render();
	ButtonWall->Render();
	ButtonWander->Render();
	ButtonMuteMusic->Render();
	ButtonExitGame->Render();
	nubes->Render();

	if (LogoColor == 1) {
		mLogo->Render();
	}
	else if (LogoColor == 2) {
		mLogo2->Render();
	}
	else {
		mLogo3->Render();
	}

	if (ArriveColor == false) {
		Arrive2->Render();
	}
	else {
		Arrive->Render();
	}

	if (EvadeColor == false) {
		Evade2->Render();
	}
	else {
		Evade->Render();
	}

	if (FleeColor == false) {
		Flee2->Render();
	}
	else {
		Flee->Render();
	}

	if (HideColor == false) {
		Hide2->Render();
	}
	else {
		Hide->Render();
	}

	if (InterposeColor == false) {
		Interpose2->Render();
	}
	else {
		Interpose->Render();
	}

	if (ObstacleColor == false) {
		Obstacle2->Render();
	}
	else {
		Obstacle->Render();
	}

	if (OffsetColor == false) {
		Offset2->Render();
	}
	else {
		Offset->Render();
	}

	if (PathColor == false) {
		Path2->Render();
	}
	else {
		Path->Render();
	}

	if (PursuitColor == false) {
		Pursuit2->Render();
	}
	else {
		Pursuit->Render();
	}

	if (SeekColor == false) {
		Seek2->Render();
	}
	else {
		Seek->Render();
	}

	if (WallColor == false) {
		Wall2->Render();
	}
	else {
		Wall->Render();
	}

	if (WanderColor == false) {
		Wander2->Render();
	}
	else {
		Wander->Render();
	}

	if (MuteMusicColor == false) {
		MuteMusic2->Render();
	}
	else {
		MuteMusic->Render();
	}

	if (ExitGameColor == false) {
		ExitGame2->Render();
	}
	else {
		ExitGame->Render();
	}
}

// para salir del juego 
void StartScreen::exitGame() {
	exit(0);
}