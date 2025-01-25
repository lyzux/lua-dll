#ifndef CUSTOM_FUNCTIONS_H
#define CUSTOM_FUNCTIONS_H

#include "lua.hpp"

// Remember to set the properties of this file to be included into this build as a header

// Declare custom Lua functions
int myCustomFunction(lua_State* L);
int anotherCustomFunction(lua_State* L);

// Register all custom functions with Lua
void registerCustomFunctions(lua_State* L);

#endif // CUSTOM_FUNCTIONS_H
