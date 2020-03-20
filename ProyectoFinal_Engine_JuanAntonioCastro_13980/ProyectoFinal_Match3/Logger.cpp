#include "Logger.h"

namespace ProyectoFinal {

	Logger* Logger::Instance = nullptr;

	Logger* Logger::Instanciate()
	{
		if (!Instance)
			Instance = new Logger();
		return Instance;
	}

	void Logger::Save()
	{
		std::ofstream outfile("../Logger/Logger.txt");
		log += "This is the log:";
		outfile << log;
		outfile.close();
	}
}