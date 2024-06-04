#include "main.h"

// a sample exported function
int DLL_EXPORT sumValue(int value1, int value2)
{
    return value1 + value2;
}

int DLL_EXPORT maxValue(int value1, int value2)
{
    if(value1 > value2){return value1;}
    else return value2;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
