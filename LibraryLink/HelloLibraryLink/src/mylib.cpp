#include "mylib.h"
#include "extern.h"
#include "WolframLibrary.h"

// LibraryFunctionLoad["mylib.dll","add_one",{Real},Real]
EXTERN_C int add_one(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
    double x = MArgument_getReal(Args[0]);
    MArgument_setReal(Res, x + 1.0);
    return LIBRARY_NO_ERROR;
}