#pragma once
using namespace System::Drawing;

public ref class Figura abstract {
protected:
    int x, y;         
    int valor;        
    Color color;      
    int ancho, alto;   

public:
    Figura(int _x, int _y, int _valor, Color _color, int _ancho, int _alto)
        : x(_x), y(_y), valor(_valor), color(_color), ancho(_ancho), alto(_alto) {
    }

    virtual void Dibujar(Graphics^ g) = 0;

    void mover(int dx, int dy) {
        x += dx;
        y += dy;
    }

    
    int getX() { return x; }
    int getY() { return y; }
    int getAncho() { return ancho; }
    int getAlto() { return alto; }
    int getValor() { return valor; }
    Color getColor() { return color; }

    void setValor(int nuevoValor) { valor = nuevoValor; }
    void setColor(Color nuevoColor) { color = nuevoColor; }

    bool colisionaCon(Figura^ otra) {
        Rectangle rect1 = Rectangle(x, y, ancho, alto);
        Rectangle rect2 = Rectangle(otra->getX(), otra->getY(), otra->getAncho(), otra->getAlto());
        return rect1.IntersectsWith(rect2);
    }
    void setTamano(int nuevoAncho, int nuevoAlto) {
        ancho = nuevoAncho;
        alto = nuevoAlto;
    }
};
