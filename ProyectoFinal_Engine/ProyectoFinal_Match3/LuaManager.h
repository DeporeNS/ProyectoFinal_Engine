#ifndef _LUAMANAGER_H
#define _LUAMANAGER_H

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#ifdef _WIN64
#pragma comment(lib, "liblua53.a")
#endif

#include "UTFManager.h"

namespace ProyectoFinal {
	class LuaManager
	{
	public:

		LuaManager();
		LuaManager(UTFManager s);

		lua_State* GetState();

		void initializeLua(UTFManager s);

		bool getGlobal(UTFManager s);
		bool callFunction(int args, int result);

		void pushNumber(float f);
		void pushString(UTFManager s);
		void pushPointer(unsigned long long int i);

		void pop(int n);

		void addFunction(UTFManager name, int (*f)(lua_State*));

		unsigned long long int getPointer(int n);
		float getNumber(int n);
		std::string getString(int n);
		bool getBoolean(int n);

		static unsigned long long int getPointer(lua_State* l, int n);
		static float getNumber(lua_State* l, int n);
		static std::string getString(lua_State* l, int n);

		static void pushNumber(lua_State* l, float f);


	private:
		bool CheckLua(lua_State* l, int r);

		lua_State* L;
		bool initialized;

	};
}

#endif;