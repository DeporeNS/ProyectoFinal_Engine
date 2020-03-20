#ifndef _LOGGER_H
#define _LOGGER_H
#include <iostream>
#include <fstream>

using namespace std;

namespace ProyectoFinal {
	class Logger
	{

	public:
		static Logger* Instanciate();
		void Save();
	private:
		string log;
		static Logger* Instance;
	};
}

#endif