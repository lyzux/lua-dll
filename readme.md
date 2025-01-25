# LuaDLL

**LuaDLL** is a dynamic link library (DLL) project that embeds the Lua scripting engine, making it accessible for use in C++ and other programming environments. This project allows developers to integrate Lua as a lightweight and flexible scripting language within their applications and provides the ability to extend Lua functionality through custom C++ functions.

---

## Purpose

The purpose of this project is to:
1. Embed the Lua scripting engine into applications via a reusable DLL.
2. Provide the full Lua API, enabling script execution, configuration, and runtime extensibility.
3. Allow the addition of custom C++ functions that can be exposed to Lua scripts for enhanced functionality.

---

## Features

- **Complete Lua Scripting Engine**:
  - Fully integrates Lua 5.4.7, unchanged from its original source, ensuring full compatibility with Lua scripts.

- **Custom Function Support**:
  - Developers can define custom C++ functions, register them with Lua, and use them directly in Lua scripts.

- **Cross-Language Usability**:
  - The DLL can be used in C++, C#, Python, and other languages that support loading and calling functions from DLLs.

- **Unmodified Lua Source**:
  - The Lua source files are taken from the official [Lua 5.4.7 distribution](https://www.lua.org/) and remain unchanged.

---

## Lua Version Details

The embedded Lua source files are based on:
- **Filename**: `lua-5.4.7.tar.gz`
- **Date**: June 13, 2024
- **Size**: 374,097 bytes
- **SHA-256 Checksum**: `9fbf5e28ef86c69858f6d3d34eccc32e911c1a28b4120ff3e84aaa70cfbf1e30`

The Lua source files are used without modification to ensure compatibility with Lua scripts and the official Lua API.

---

## How to Build the DLL

### Prerequisites
- Visual Studio 2022 or later.
- Lua 5.4.7 source files (included in the project).

### Steps to Build:
1. Clone or download this project.
2. Open the `LuaDLL` solution in Visual Studio.
3. Build the project in either **Debug** or **Release** mode.
4. The output DLL and `.lib` files will be available in the `x64/` directory:
   - `x64/Debug/LuaDLL.dll`
   - `x64/Release/LuaDLL.dll`

---

## Using LuaDLL

### For C++ Applications
1. Link the `LuaDLL.lib` file to your C++ project.
2. Include the Lua headers (`lua.hpp`, `lauxlib.h`, etc.) in your project.
3. Use the Lua API to execute scripts and interact with Lua.

Example:
```cpp
#include "lua.hpp"

int main() {
    lua_State* L = luaL_newstate(); // Initialize Lua
    luaL_openlibs(L);               // Load Lua libraries

    if (luaL_dofile(L, "script.lua") != LUA_OK) {
        std::cerr << lua_tostring(L, -1) << std::endl;
    }

    lua_close(L); // Clean up
    return 0;
}
