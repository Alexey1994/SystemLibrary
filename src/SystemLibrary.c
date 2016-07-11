#include "SystemLibrary.h"
#include "extends.h"


static char *LIBRARY_PATH="libs/";
static int   SIZE_OF_LIBRARY_PATH=5;

#ifdef WIN32
#include <windows.h>

SystemLibrary open_system_library(char *name)
{
    char path[SIZE_OF_LIBRARY_PATH + strlen(name)+1];

    strcpy(path, LIBRARY_PATH);
    strcpy(path+SIZE_OF_LIBRARY_PATH, name);

    //return LoadLibrary(path);
    return LoadLibrary(name);
}


void close_system_library(SystemLibrary library)
{
    FreeLibrary(library);
}


char* get_system_function(SystemLibrary library, char *name)
{
    return GetProcAddress(library, name);
}

#endif // WIN32

int run_system_function(int(*f)(), int *args, int length)
{
    for(length--; length>=0; length--)
    {
        __asm__("sub   $4, %%esp\n"
                "movl  %0, (%%esp)"
                :
                :"r"(args[length])
               );
    }

    return f();
}
