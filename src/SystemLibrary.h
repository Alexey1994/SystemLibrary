#ifndef SYSTEM_LIBRARY_H_INCLUDED
#define SYSTEM_LIBRARY_H_INCLUDED

/*
typedef struct
{
    char *name;
    char *library;
}SystemLibrary;*/

typedef char* SystemLibrary;


SystemLibrary open_system_library(char *name);
void close_system_library(SystemLibrary library);
char* get_system_function(SystemLibrary library, char *name);
int run_system_function(int(*f)(), int *args, int length);

#endif // SYSTEM_LIBRARY_H_INCLUDED
