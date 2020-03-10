#include "GameManager.h"

int main(int argc, char* argv[]) {

	ProyectoFinal::GameManager* game = ProyectoFinal::GameManager::Instance();
	game->Run();

	ProyectoFinal::GameManager::Release();
	game = NULL;

	return 0;
}