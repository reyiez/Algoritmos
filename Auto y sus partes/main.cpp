#include "pch.h"
#include "Carrera.h"
using namespace System;

int main()
{
    Console::SetWindowSize(80, 40);
    srand(time(nullptr));
    Carrera *ObjCarrera;
    ObjCarrera = new Carrera();
    ObjCarrera->IniciaCarrera();

    system("pause>0");
    return 0;
}
