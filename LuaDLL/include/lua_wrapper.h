#ifndef LUA_WRAPPER_H
#define LUA_WRAPPER_H

#ifdef _WIN32
#define LUA_API __declspec(dllexport)
#else
#define LUA_API
#endif

// Include the Lua headers
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#endif // LUA_WRAPPER_H
