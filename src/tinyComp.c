#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "tinyComp.h"

static int print(lua_State *L)
{
    const int argc = lua_gettop(L);

    for (int i = 1; i <= argc; i++)
    {
        printf("%s ", lua_tostring(L, i));
    }

    printf("\n");

    return 0;
}

static const luaL_Reg tinyCompLib[] =
    {
        // {"print", print},
        {NULL, NULL}};

int luaopen_tinyComp(lua_State *L)
{
    luaL_newlib(L, tinyCompLib);
    lua_register(L, "print", print);
    return 1;
}