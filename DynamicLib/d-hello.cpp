#include "d-hello.h"
#include <iostream>
#include <onesdk/onesdk.h>
#include <windows.h>

static void InitOneSdk()
{
    onesdk_stub_set_logging_level(ONESDK_LOGGING_LEVEL_FINEST);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // color your text in Windows console mode
    // colors are 0=black 1=blue 2=green and so on to 15=white  
    // colorattribute = foreground + background * 16
    // to get red text on yellow use 4 + 14*16 = 228
    // light red on yellow would be 12 + 14*16 = 236

    FlushConsoleInputBuffer(hConsole);

    onesdk_result_t const onesdk_init_result = onesdk_initialize();

    if (onesdk_init_result == ONESDK_SUCCESS)
    {
        SetConsoleTextAttribute(hConsole, 2);
        std::cout << "OneSDK initialised OK from DLL" << std::endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4);
        std::cout << "OneSDK initialised ERROR from DLL" << std::endl;
    }

    SetConsoleTextAttribute(hConsole, 15); //set back to black background and white text
}

extern "C"
{
    void dHelloFun()
    {
        InitOneSdk();

        std::cout << "DynamicLibHello helloFun() just called" << std::endl;
    }
}