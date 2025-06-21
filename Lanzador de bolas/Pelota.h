#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Pelota {
private:
    float x, y;        // Coordenadas de la pelota
    std::string color; // Color de la pelota
    float velocidadX, velocidadY; // Velocidades en X y Y
public:
    // Constructor
    Pelota(float x_inicial, float y_inicial, std::string color_inicial)
        : x(x_inicial), y(y_inicial), color(color_inicial) {
        // Inicializamos velocidades aleatorias
        velocidadX = (rand() % 2 == 0 ? 1 : -1) * (rand() % 3 + 1);
        velocidadY = (rand() % 2 == 0 ? 1 : -1) * (rand() % 3 + 1);
    }

    // Mover pelota
    void mover() {
        x += velocidadX;
        y += velocidadY;

        // Rebotar si toca los límites de la pantalla
        if (x < 0 || x > 800) {
            velocidadX = -velocidadX; // Rebote horizontal
        }
        if (y < 0 || y > 600) {
            velocidadY = -velocidadY; // Rebote vertical
        }
    }

    // Mostrar la pelota
    void mostrar() const {
        std::cout << "Pelota " << color << " en (" << x << ", " << y << ")\n";
    }

    // Getters y setters
    float getX() const { return x; }
    float getY() const { return y; }
    std::string getColor() const { return color; }
};
