#pragma once
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

class Enemigo {
public:
    void DibujarFigura(int x, int y);
    void BorrarFigura(int x, int y);
    void CambiarColor(ConsoleColor nuevoColor);
    void CambiarVelocidad(double nuevaVelocidad);
    void RestablecerVelocidad();
    double ObtenerVelocidad();

private:
    string figura[5] = {
        "   O  ",
        "  OOO  ",
        "   O   ",
        "   O   ",
        " O   O "
    };
    ConsoleColor color = ConsoleColor::White;
    double velocidad = 0.5;  
};

void Enemigo::DibujarFigura(int x, int y) {
    Console::ForegroundColor = color;
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << figura[i];
    }
    Console::ResetColor();
}

void Enemigo::BorrarFigura(int x, int y) {
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << "           ";
    }
}

void Enemigo::CambiarColor(ConsoleColor nuevoColor) {
    color = nuevoColor;
}

void Enemigo::CambiarVelocidad(double nuevaVelocidad) {
    velocidad = nuevaVelocidad;
}

void Enemigo::RestablecerVelocidad() {
    velocidad = 0.5;
}

double Enemigo::ObtenerVelocidad() {
    return velocidad;
}


