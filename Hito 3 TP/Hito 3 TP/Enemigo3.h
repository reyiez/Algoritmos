#pragma once
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

class Enemigo_3 {
public:
    void DibujarFigura3(int x3, int y3);
    void BorrarFigura3(int x3, int y3);
    void CambiarColor3(ConsoleColor nuevoColor3);
    void CambiarVelocidad3(double nuevaVelocidad3);
    void RestablecerVelocidad3();
    double ObtenerVelocidad3();

private:
    string figura[5] = {
        "   O  ",
        "  OOO  ",
        "   O   ",
        "   O   ",
        " O   O "
    };
    ConsoleColor color = ConsoleColor::White; 
    double velocidad3 = 0.5;  
};

void Enemigo_3::DibujarFigura3(int x3, int y3) {
    Console::ForegroundColor = color; 
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x3, y3 + i);
        cout << figura[i];
    }
    Console::ResetColor(); 
}

void Enemigo_3::BorrarFigura3(int x3, int y3) {
    for (int i = 0; i < 5; i++) {
        Console::SetCursorPosition(x3, y3 + i);
        cout << "           "; 
    }
}

void Enemigo_3::CambiarColor3(ConsoleColor nuevoColor3) {
    color = nuevoColor3; 
}

void Enemigo_3::CambiarVelocidad3(double nuevaVelocidad3) {
    velocidad3 = nuevaVelocidad3;  
}

void Enemigo_3::RestablecerVelocidad3() {
    velocidad3 = 0.5;  
}

double Enemigo_3::ObtenerVelocidad3() {
    return velocidad3;  
}
