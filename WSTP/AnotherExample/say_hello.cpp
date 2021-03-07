#include <stdlib.h>
#include <string.h>

char *say_hello()
{
    char *hello = (char*)malloc(15);
    strcpy(hello, "hello WSTP");
    return hello;
}