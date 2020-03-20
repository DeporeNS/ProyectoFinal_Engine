// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UGHmS70UdH4&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=17
#include "ScreenManager.h"

// singleton
ScreenManager* ScreenManager::sInstance = NULL;

// Se instancia al manager en el juego 
ScreenManager* ScreenManager::Instance() {
	if (sInstance == NULL)
		sInstance = new ScreenManager();

	return sInstance;
}

// libera de la memoria la instancia del manager
void ScreenManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

// constructor
ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();
	mTimer = Timer::Instance();

	mStartScreen = new StartScreen();
	mArrive = new Arrive();
	mEvade = new Evade();
	mFlee = new Flee();
	mHide = new Hide();
	mInterpose = new Interpose();
	mObstacle = new Obstacle();
	mOffset = new Offset();
	mPath = new Path();
	mPursuit = new Pursuit();
	mSeek = new Seek();
	mWall = new Wall();
	mWander = new Wander();

	mCurrentScreen = start;
}

// destructor
ScreenManager::~ScreenManager() {
	mInput = NULL;

	delete mStartScreen;
	mStartScreen = NULL;
	delete mArrive;
	mArrive = NULL;
	delete mEvade;
	mEvade = NULL;
	delete mFlee;
	mFlee = NULL;
	delete mHide;
	mHide = NULL;
	delete mInterpose;
	mInterpose = NULL;
	delete mObstacle;
	mObstacle = NULL;
	delete mOffset;
	mOffset = NULL;
	delete mPath;
	mPath = NULL;
	delete mPursuit;
	mPursuit = NULL;
	delete mSeek;
	mSeek = NULL;
	delete mWall;
	mWall = NULL;
	delete mWander;
	mWander = NULL;
}

// Update
void ScreenManager::Update() {

	switch (mCurrentScreen) {
	case start:
		mStartScreen->Update();
		if (mStartScreen->mSelectedMode == 1) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = arrive;
		}
		else if (mStartScreen->mSelectedMode == 2) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = evade;
		}
		else if (mStartScreen->mSelectedMode == 3) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = flee;
		}
		else if (mStartScreen->mSelectedMode == 4) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = hide;
		}
		else if (mStartScreen->mSelectedMode == 5) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = interpose;
		}
		else if (mStartScreen->mSelectedMode == 6) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = obstacle;
		}
		else if (mStartScreen->mSelectedMode == 7) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = offset;
		}
		else if (mStartScreen->mSelectedMode == 8) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = path;
		}
		else if (mStartScreen->mSelectedMode == 9) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = pursuit;
		}
		else if (mStartScreen->mSelectedMode == 10) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = seek;
		}
		else if (mStartScreen->mSelectedMode == 11) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = wall;
		}
		else if (mStartScreen->mSelectedMode == 12) {
			mStartScreen->mSelectedMode = 0;
			mCurrentScreen = wander;
		}
		break;

	case arrive:
		mArrive->Update();
		if (mArrive->mSelectedMode == 1) {
			mArrive->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case evade:
		mEvade->Update();
		if (mEvade->mSelectedMode == 1) {
			mEvade->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case flee:
		mFlee->Update();
		if (mFlee->mSelectedMode == 1) {
			mFlee->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case hide:
		mHide->Update();
		if (mHide->mSelectedMode == 1) {
			mHide->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case interpose:
		mInterpose->Update();
		if (mInterpose->mSelectedMode == 1) {
			mInterpose->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case obstacle:
		mObstacle->Update();
		if (mObstacle->mSelectedMode == 1) {
			mObstacle->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case offset:
		mOffset->Update();
		if (mOffset->mSelectedMode == 1) {
			mOffset->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case path:
		mPath->Update();
		if (mPath->mSelectedMode == 1) {
			mPath->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case pursuit:
		mPursuit->Update();
		if (mPursuit->mSelectedMode == 1) {
			mPursuit->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case seek:
		mSeek->Update();
		if (mSeek->mSelectedMode == 1) {
			mSeek->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case wall:
		mWall->Update();
		if (mWall->mSelectedMode == 1) {
			mWall->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;

	case wander:
		mWander->Update();
		if (mWander->mSelectedMode == 1) {
			mWander->mSelectedMode = 0;
			mCurrentScreen = start;
		}
		break;
	}
}

//Render
void ScreenManager::Render() {
	switch (mCurrentScreen) {
	case start:
		mStartScreen->Render();
		break;

	case arrive:
		mArrive->Render();
		break;

	case evade:
		mEvade->Render();
		break;

	case flee:
		mFlee->Render();
		break;

	case hide:
		mHide->Render();
		break;

	case interpose:
		mInterpose->Render();
		break;

	case obstacle:
		mObstacle->Render();
		break;

	case offset:
		mOffset->Render();
		break;

	case path:
		mPath->Render();
		break;

	case pursuit:
		mPursuit->Render();
		break;

	case seek:
		mSeek->Render();
		break;

	case wall:
		mWall->Render();
		break;

	case wander:
		mWander->Render();
		break;
	}

}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UGHmS70UdH4&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=17