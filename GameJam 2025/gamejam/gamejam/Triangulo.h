#pragma once
#include "Figura.h"

public ref class Triangulo : public Figura {
public:
   
    Triangulo(int _x, int _y, int _valor, System::Drawing::Color _color)
        : Figura(_x, _y, _valor, _color, 50, 50)  
    {
    }

    virtual void Dibujar(System::Drawing::Graphics^ g) override {
        array<System::Drawing::Point>^ puntos = gcnew array<System::Drawing::Point>(3);

        puntos[0] = System::Drawing::Point(x, y);  
        puntos[1] = System::Drawing::Point(x + ancho, y);  
        puntos[2] = System::Drawing::Point(x + ancho / 2, y - alto);  

        System::Drawing::SolidBrush^ brocha = gcnew System::Drawing::SolidBrush(color);

        g->FillPolygon(brocha, puntos);  

        g->DrawString(valor.ToString(), gcnew System::Drawing::Font("Arial", 12), System::Drawing::Brushes::White, x + 15, y + 20);
    }
};
