// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
#include "GameManager.h"

namespace ProyectoFinal {
	// La instancia se inicializa como NULL
	GameManager* GameManager::sInstance = NULL;

	// Regresa un apuntador a la instancia del juego
	GameManager* GameManager::Instance() {
		if (sInstance == NULL) {
			sInstance = new GameManager();
		}

		return sInstance;
	}

	// Sirve para liberar de la memoria 
	void GameManager::Release() {
		delete sInstance;
		sInstance = NULL;
	}

	// constructor
	GameManager::GameManager() {
		mQuit = false;
		//Inicializa SDL
		mGraphics = Graphics::Instance();

		// Sale de SDL si el juego falla al inicializarse
		if (!Graphics::Initialized())
			mQuit = true;

		//Inicializa AssetManager
		mAssetMgr = AssetManager::Instance();

		//Inicializa InputManager
		mInputMgr = InputManager::Instance();

		//Inicializa Audio Manager
		mAudioMgr = AudioManager::Instance();

		//Inicializa Timer Manager	
		mTimer = Timer::Instance();

		// Inicializa el manager de pantallas
		mScreenMgr = ScreenManager::Instance();
	}
	 
	// destructor
	GameManager::~GameManager() {
		ScreenManager::Release();
		mScreenMgr = NULL;

		AudioManager::Release();
		mAudioMgr = NULL;

		AssetManager::Release();
		mAssetMgr = NULL;

		Graphics::Release();
		mGraphics = NULL;

		InputManager::Release();
		mInputMgr = NULL;

		Timer::Release();
		mTimer = NULL;
	}

	//  Se usa para cosas que se updatean primero (Input)
	void GameManager::EarlyUpdate() {
		// Primero se actualizan los Inputs para  saber que lo demas esta bien
		mInputMgr->Update();
	}

	// se usa para update (transforms)
	void GameManager::Update() {
		// GameEntity Updates van aqui

		// Update de la pantalla inicial
		mScreenMgr->Update();
	}

	// Se usa para hacer el ultimo update a cosas que van al final (resetear el timer)
	void GameManager::LateUpdate() {
		// deteccion de colisiones deben de ir aqui
		mInputMgr->UpdatePrevInput();
		mTimer->Reset();
	}

	// hace update a los renders	
	void GameManager::Render() {
		// Limpia el Ultimo Render del BackBuffer 
		mGraphics->ClearBackBuffer();
		//Todos los demas Renders pasan aqui

		// Render de la pantalla de inicio
		mScreenMgr->Render();

		// Se hace el render de la frame
		mGraphics->Render();
	}

	// Run GameManager
	void GameManager::Run() {

		clock_t t = clock();

		// lectura ini para tamano de la pantalla
		INIReader file("prueba.ini");

		byte = file.GetInteger("memory", "byte", -1);
		kbyte = file.GetInteger("memory", "kbyte", -1);
		mbyte = file.GetInteger("memory", "mbyte", -1);
		std::cout << file.GetInteger("memory", "byte", -1) << std::endl;
		std::cout << file.GetInteger("memory", "kbyte", -1) << std::endl;
		std::cout << file.GetInteger("memory", "mbyte", -1) << std::endl;

		//asignar 32 MB de memoria dinamica
		StackAllocator* stackAllocator = new StackAllocator(1024*1024* mbyte);
		clock_t dt = clock() - t;
		printf("Tomo %f segundos inicializar StackAllocator.\n", ((float)dt) / CLOCKS_PER_SEC);

		int n = 100000;
		//crear n strings con asignacion heap y medir tiempo
		t = clock();
		for (int i = 0; i < n; i++)
		{
			std::string* str = new std::string("hola mundo");
		}
		t = clock() - t;
		printf("Tomo %f segundos asignar con memoria dinamica.\n", ((float)t) / CLOCKS_PER_SEC);

		////crear n strings con asignacion stack y medir el tiempo
		//t = clock();
		//for (int i = 0; i < n; i++)
		//{
		//	void* buf = stackAllocator->alloc(sizeof(std::string));
		//	std::string* str = new(buf) std::string("hola mundo");    // placement new
		//}
		//t = clock() - t;
		//printf("Tomo %f segundos asignar con StackAllocator.\n", ((float)t) / CLOCKS_PER_SEC);

		//getchar();

		while (!mQuit) {
			mTimer->Update();

			while (SDL_PollEvent(&mEvents) != 0) {
				// Checa si el jugador quito el juego
				if (mEvents.type == SDL_QUIT) {
					mQuit = true;
				}
			}

			// Limita el Frame rate a FRAME_RATE
			if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				//printf("DeltaTime: %f\n", mTimer->DeltaTime());

				EarlyUpdate();
				Update();
				LateUpdate();
				Render();
				//mTex->Rotate(10 * mTimer->DeltaTime());

				//mTexAnim->Update();

			}
		}
	}
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7