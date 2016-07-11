#include <stdio.h>
#include <stdlib.h>
#include "SystemLibrary.h"


int main()
{
    SystemLibrary library;
    int(*f)();

    library=open_system_library("KernelBase");
    if(!library)
    {
        printf("\nlibrary not found");
        return 0;
    }

    f=get_system_function(library, "wprintf");
    if(!f)
    {
        printf("\nfunction not found");
        return 0;
    }

    char *string=L"abcdef\0";
    int args[]={string};


    run_system_function(f, args, 1);

    close_system_library(library);

    return 0;
}
