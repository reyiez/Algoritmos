#pragma once
#include <iostream>
#include <cstdlib>
using namespace System;
using namespace std;

class Aliado {
public:
    void GenerarPosicionAleatoria(int maxX, int maxY);
    void Dibujar();
    void Borrar();
    int ObtenerX();
    int ObtenerY();

private:
    int x = 0; 
    int y = 0;
};

void Aliado::GenerarPosicionAleatoria(int maxX, int maxY) {
    x = rand() % maxX; 
    y = rand() % maxY; 

    Console::SetCursorPosition(0, 46);
    cout << "" << endl;
    cout << "Aliado generado en posicion (" << x << ", " << y << ")" << endl;
}


void Aliado::Dibujar() {
    Console::SetCursorPosition(x, y);
    Console::ForegroundColor = ConsoleColor::Green;
    cout << (char)219;
    Console::ResetColor();
}

void Aliado::Borrar() {
    Console::SetCursorPosition(x, y);
    cout << " ";
}

int Aliado::ObtenerX() {
    return x;
}

int Aliado::ObtenerY() {
    return y;
}
