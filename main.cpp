#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BANK_interface.h"

using namespace std;

int main()
{
    cSystem system;
    system.initTheSystem();
    system.startTheSystem();    

    return 0;
}