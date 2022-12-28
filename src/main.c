#include <stdio.h>
#include <stdlib.h>

// Raylib
#include <raylib.h>

// Lua
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "tinyComp.h"

static const luaL_Reg lualibs[] = {
    //   {LUA_GNAME, luaopen_base},
    //   {LUA_LOADLIBNAME, luaopen_package},
    {LUA_COLIBNAME, luaopen_coroutine},
    {LUA_TABLIBNAME, luaopen_table},
    //   {LUA_IOLIBNAME, luaopen_io},
    //   {LUA_OSLIBNAME, luaopen_os},
    {LUA_STRLIBNAME, luaopen_string},
    {LUA_MATHLIBNAME, luaopen_math},
    {LUA_UTF8LIBNAME, luaopen_utf8},
    //   {LUA_DBLIBNAME, luaopen_debug},
    {"tinyComp", luaopen_tinyComp},
    {NULL, NULL}};

static void loadLibs(lua_State *L, const luaL_Reg *libs)
{
    const luaL_Reg *lib;
    /* "require" functions from 'loadedlibs' and set results to global table */
    for (lib = libs; lib->func; lib++)
    {
        luaL_requiref(L, lib->name, lib->func, 1);
        lua_pop(L, 1); /* remove lib */
    }
}

int main()
{
    lua_State *L = luaL_newstate();
    loadLibs(L, lualibs);

    luaL_dostring(L, "print(247689)");

    return 0;
}