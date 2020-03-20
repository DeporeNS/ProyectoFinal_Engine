#include "Wall.h"

// Constructor
Wall::Wall() {
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

	//Player
	mPlayer = new Player();
	mPlayer->changeState(8);

	//Logo
	mLogo = new Texture("Wall", "Lazer84.TTF", 120, { 140, 0, 0 });
	mLogo2 = new Texture("Wall", "Lazer84.TTF", 120, { 140, 81, 0 });
	mLogo3 = new Texture("Wall", "Lazer84.TTF", 120, { 140, 157, 0 });
	mLogo->Parent(this);
	mLogo2->Parent(this);
	mLogo3->Parent(this);
	mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.165f, Graphics::Instance()->SCREEN_HEIGHT * 0.35f));
	mLogo2->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.165f, Graphics::Instance()->SCREEN_HEIGHT * 0.35f));
	mLogo3->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.165f, Graphics::Instance()->SCREEN_HEIGHT * 0.35f));

	//Menu
	mMenu = new GameEntity(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.6f);
	MainMenu = new Texture("Main Menu", "ARCADE.TTF", 72, { 0, 0, 0, });
	MainMenu2 = new Texture("Main Menu", "ARCADE.TTF", 72, { 170, 0, 0, });
	MuteMusic = new Texture("Mute Music", "ARCADE.TTF", 72, { 0, 0, 0, });
	MuteMusic2 = new Texture("Mute Music", "ARCADE.TTF", 72, { 170, 0, 0, });
	ExitGame = new Texture("Exit Game", "ARCADE.TTF", 72, { 0, 0, 0, });
	ExitGame2 = new Texture("Exit Game", "ARCADE.TTF", 72, { 170, 0, 0, });
	ButtonMainMenu = new Texture("Button.png");
	ButtonMuteMusic = new Texture("Button.png");
	ButtonExitGame = new Texture("Button.png");
	ButtonMainMenu->Parent(mMenu);
	ButtonMuteMusic->Parent(mMenu);
	ButtonExitGame->Parent(mMenu);
	MainMenu->Parent(ButtonMainMenu);
	MainMenu2->Parent(ButtonMainMenu);
	MuteMusic->Parent(ButtonMuteMusic);
	MuteMusic2->Parent(ButtonMuteMusic);
	ExitGame->Parent(ButtonExitGame);
	ExitGame2->Parent(ButtonExitGame);
	ButtonMainMenu->Pos(Vector2(-580, -90));
	ButtonMainMenu->Scale(Vector2(1.5, 1));
	ButtonMuteMusic->Pos(Vector2(-580, 40));
	ButtonMuteMusic->Scale(Vector2(1.5, 1));
	ButtonExitGame->Pos(Vector2(-580, 170));
	ButtonExitGame->Scale(Vector2(1.5, 1));
	MainMenu->Scale(Vector2(0.5, 1));
	MainMenu2->Scale(Vector2(0.5, 1));
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
Wall::~Wall() {
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
	delete ButtonMainMenu;
	ButtonMainMenu = NULL;
	delete ButtonMuteMusic;
	ButtonMuteMusic = NULL;
	delete ButtonExitGame;
	ButtonExitGame = NULL;
	delete MainMenu;
	MainMenu = NULL;
	delete MuteMusic;
	MuteMusic = NULL;
	delete ExitGame;
	ExitGame = NULL;
	delete MainMenu2;
	MainMenu2 = NULL;
	delete MuteMusic2;
	MuteMusic2 = NULL;
	delete ExitGame2;
	ExitGame2 = NULL;
}


// Update
void Wall::Update() {
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

	// movimiento nuves
	if (nubesPosX > 150) {
		forward = false;
	}
	if (nubesPosX < -150) {
		forward = true;
	}
	if (forward == true) {
		nubesPosX = nubesPosX + 0.2f;
	}
	else {
		nubesPosX = nubesPosX - 0.2f;
	}

	// sonido click y cambio de color en botones
	if (mInput->MousePos().x >= ButtonMainMenu->Pos().x - 180.0f && mInput->MousePos().y >= ButtonMainMenu->Pos().y - 50.0f && mInput->MousePos().x <= ButtonMainMenu->Pos().x + 180.0f && mInput->MousePos().y <= ButtonMainMenu->Pos().y + 50.0f) {
		HighScoresColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			mSelectedMode = 1;
		}
	}
	else {
		HighScoresColor = true;
	}

	// sonido click y cambio de color en botones
	if (mInput->MousePos().x >= ButtonMuteMusic->Pos().x - 180.0f && mInput->MousePos().y >= ButtonMuteMusic->Pos().y - 50.0f && mInput->MousePos().x <= ButtonMuteMusic->Pos().x + 180.0f && mInput->MousePos().y <= ButtonMuteMusic->Pos().y + 50.0f) {
		MuteMusicColor = false;
		if (mInput->MouseButtonPressed(InputManager::left)) {
			mAudioMgr->PlaySFX("Button_Click.wav");
			if (play == true) {
				mAudioMgr->PauseMusic();
				play = false;
			}
			else {
				mAudioMgr->ResumeMusic();
				play = true;
			}
		}
	}
	else {
		MuteMusicColor = true;
	}

	// sonido click y cambio de color en botones
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

	// posicion de las nuves
	nubes->Pos(Vector2(nubesPosX, 0));

	mPlayer->Update();
}

// Render
void Wall::Render() {
	fondo->Render();
	ButtonMainMenu->Render();
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

	if (HighScoresColor == false) {
		MainMenu2->Render();
	}
	else {
		MainMenu->Render();
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

	mPlayer->Render();
}


// para salir del juego 
void Wall::exitGame() {
	exit(0);
}