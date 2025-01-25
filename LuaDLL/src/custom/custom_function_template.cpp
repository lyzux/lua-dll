#include "custom_function_template.h"
#include <iostream>

// Remember to set the properties of this file to be included into this build as a CPP file

// Define custom Lua functions
int myCustomFunction(lua_State* L) {
    // Example: Add two integers passed as arguments from Lua
    int arg1 = luaL_checkinteger(L, 1); // First argument
    int arg2 = luaL_checkinteger(L, 2); // Second argument

    int result = arg1 + arg2;

    lua_pushinteger(L, result); // Push the result onto the Lua stack
    return 1;                   // Return the number of results
}

int anotherCustomFunction(lua_State* L) {
    // Example: Print a string passed from Lua
    const char* message = luaL_checkstring(L, 1); // First argument

    std::cout << "Message from Lua: " << message << std::endl;

    return 0; // No return values
}

// Register all custom functions with Lua
void registerCustomFunctions(lua_State* L) {
    // Register each function with Lua
    lua_register(L, "add", myCustomFunction);
    lua_register(L, "printMessage", anotherCustomFunction);
}
