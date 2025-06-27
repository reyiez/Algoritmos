#pragma once
#include "Figura.h"

public ref class Cuadrado : public Figura {
public:
    // Constructor del Cuadrado
    Cuadrado(int _x, int _y, int _valor, System::Drawing::Color _color)
        : Figura(_x, _y, _valor, _color, 50, 50)  
    {
    }

    virtual void Dibujar(System::Drawing::Graphics^ g) override {
        g->FillRectangle(gcnew System::Drawing::SolidBrush(color), x, y, ancho, alto);
        g->DrawString(valor.ToString(), gcnew System::Drawing::Font("Arial", 12), System::Drawing::Brushes::White, x + 15, y + 20);
    }
};
