#pragma once
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;

class VigilanteDelEquilibrio {
public:
    void DibujarFigura(int x, int y);
    void BorrarFigura(int x, int y);
    void QuitarVida();
    void MostrarVidas();
    int ObtenerVidas();
    void RestaurarVidas();

private:
    int vidas = 3;

    string figura[3] = {
        "    O     ",  
        "   /|\\   ",  
        "    /\\   "   
    };
};
//Fin de la clase

// Implementación de los métodos
void VigilanteDelEquilibrio::DibujarFigura(int x, int y) {
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << figura[i]; 
    }
}

void VigilanteDelEquilibrio::BorrarFigura(int x, int y) {
    for (int i = 0; i < 3; i++) {
        Console::SetCursorPosition(x, y + i);
        cout << "          ";  
    }
}

void VigilanteDelEquilibrio::QuitarVida() {
    if (vidas > 0) vidas--;  
    MostrarVidas();  
}

void VigilanteDelEquilibrio::RestaurarVidas() {
    vidas = 3;  
}

void VigilanteDelEquilibrio::MostrarVidas() {
    Console::SetCursorPosition(0, 0);  
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "Vidas: ";
    for (int i = 0; i < vidas; i++) {
        cout << (char)219 << " ";  
    }
    for (int i = vidas; i < 3; i++) {
        cout << "  ";  
    }
    Console::ResetColor();
}

int VigilanteDelEquilibrio::ObtenerVidas() {
    return vidas;  
}
