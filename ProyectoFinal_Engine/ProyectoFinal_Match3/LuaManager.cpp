#include "LuaManager.h"
//#include "Singletons/Debug.h"

namespace ProyectoFinal {
	LuaManager::LuaManager() {
		L = luaL_newstate();
		luaL_openlibs(L);
		initialized = false;
	}

	LuaManager::LuaManager(UTFManager s) {
		L = luaL_newstate();
		luaL_openlibs(L);
		initialized = false;
		initializeLua(s);
	}

	void LuaManager::initializeLua(UTFManager s) {
		if (!initialized) {
			UTFManager root("../../Assets/Files/LuaFiles/");
			root += s;
			if (!CheckLua(L, luaL_dofile(L, root.toString().c_str())))
				throw 401;
			else
				initialized = true;
		}
	}

	bool LuaManager::CheckLua(lua_State* l, int r) {
		if (r != LUA_OK) {
			UTFManager e = lua_tostring(L, -1);
			//Debug::GetPtr()->LogError(e);
			return false;
		}
		return true;
	}

	bool LuaManager::getGlobal(UTFManager s) {
		try {
			lua_getglobal(L, s.toString().c_str());
		}
		catch (std::exception e) {
			int x;
		}
		return lua_isfunction(L, -1);
	}

	bool LuaManager::callFunction(int args, int result) {
		return CheckLua(L, lua_pcall(L, args, result, 0));
	}

	void LuaManager::pushNumber(float f) {
		lua_pushnumber(L, f);
	}

	void LuaManager::pushPointer(unsigned long long int i) {
		lua_pushnumber(L, i);
	}

	void LuaManager::pushString(UTFManager s) {
		lua_pushstring(L, s.toString().c_str());
	}

	lua_State* LuaManager::GetState() {
		return L;
	}

	void LuaManager::pop(int n) {
		lua_pop(L, n);
	}

	void LuaManager::addFunction(UTFManager name, int (*f)(lua_State*)) {
		lua_register(L, name.toString().c_str(), f);
	}

	float LuaManager::getNumber(int n) {
		return lua_tonumber(L, n);
	}

	unsigned long long int LuaManager::getPointer(int n) {
		return lua_tonumber(L, n);
	}

	std::string LuaManager::getString(int n) {
		return lua_tostring(L, n);
	}

	bool LuaManager::getBoolean(int n) {
		return lua_toboolean(L, n);
	}

	float LuaManager::getNumber(lua_State* l, int n) {
		return lua_tonumber(l, n);
	}

	unsigned long long int LuaManager::getPointer(lua_State* l, int n) {
		return lua_tonumber(l, n);
	}

	std::string LuaManager::getString(lua_State* l, int n) {
		return lua_tostring(l, n);
	}

	void LuaManager::pushNumber(lua_State* l, float f) {
		lua_pushnumber(l, f);
	}
}