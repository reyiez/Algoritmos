#pragma once
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

class Enemigo_2 {
public:
    void DibujarFigura2(int x2, int y2);
    void BorrarFigura2(int x2, int y2);
    void CambiarColor2(ConsoleColor nuevoColor2);
    void CambiarVelocidad2(double nuevaVelocidad2);
    void RestablecerVelocidad2();
    double ObtenerVelocidad2();

private:
    string figura[5] = {
        "   O  ",
        "  OOO  ",
        "   O   ",
        "   O   ",
        " O   O "
    };
    ConsoleColor color = ConsoleColor::White;
    double velocidad2 = 0.5;  
};

void Enemigo_2::DibujarFigura2(int x2, int y2) {
    Console::ForegroundColor = color;
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x2, y2 + i);
        cout << figura[i];
    }
    Console::ResetColor();
}

void Enemigo_2::BorrarFigura2(int x2, int y2) {
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x2, y2 + i);
        cout << "           ";
    }
}

void Enemigo_2::CambiarColor2(ConsoleColor nuevoColor2) {
    color = nuevoColor2;
}

void Enemigo_2::CambiarVelocidad2(double nuevaVelocidad2) {
    velocidad2 = nuevaVelocidad2;
}

void Enemigo_2::RestablecerVelocidad2() {
    velocidad2 = 0.5;
}

double Enemigo_2::ObtenerVelocidad2() {
    return velocidad2;
}
