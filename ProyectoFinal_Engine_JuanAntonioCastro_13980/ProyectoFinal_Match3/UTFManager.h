// Codigo fuente: https://github.com/Knothe/GameEngine/tree/master/GameEngine/GameEngine

#pragma once
#include <iostream>

namespace ProyectoFinal {
	class UTFManager
	{
	public:
		UTFManager();
		UTFManager(const char* s);
		UTFManager(const wchar_t* s);
		UTFManager(std::string s);
		UTFManager(std::wstring& s);
		void Set(std::string s);
		std::wstring Get();
		const char* GetChar();
		void Print();

		bool operator==(std::string& s);
		bool operator==(UTFManager s);
		void operator=(UTFManager s);
		void operator=(std::string& s);
		UTFManager operator+(UTFManager& s);
		UTFManager operator+(const char* s);
		UTFManager operator+(const char s);
		UTFManager operator+(std::string& s);
		void operator+=(std::string& s);
		void operator+=(UTFManager& s);
		void operator+=(const char* s);
		void operator+=(const char s);
		void operator+=(wchar_t* s);
		bool operator>(UTFManager s);
		bool operator<(UTFManager s);
		bool operator!=(UTFManager& s);
		std::string toString();

	private:
		std::wstring string;

		std::wstring convert(const std::string& input);


	};
}

// Codigo fuente: https://github.com/Knothe/GameEngine/tree/master/GameEngine/GameEngine