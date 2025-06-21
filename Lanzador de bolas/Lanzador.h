#pragma once

#include "Pelota.h"
#include <vector>
#include <cstdlib>

class Lanzador {
private:
    float x, y; // Posición del lanzador
    std::vector<Pelota*> pelotas; // Contenedor de pelotas activas

public:
    // Constructor
    Lanzador(float x_inicial, float y_inicial)
        : x(x_inicial), y(y_inicial) {}

    // Métodos de acceso (getters) para obtener las posiciones de los lanzadores
    float getX() const { return x; }
    float getY() const { return y; }

    // Método para lanzar una pelota
    void lanzarPelota(std::string color) {
        // Pelotas azules salen desde la parte superior y rojas desde la parte inferior
        Pelota* nueva_pelota = new Pelota(x, y, color);
        pelotas.push_back(nueva_pelota);
    }

    // Eliminar pelota
    void eliminarPelota(std::string color) {
        for (auto it = pelotas.begin(); it != pelotas.end(); ++it) {
            if ((*it)->getColor() == color) {
                delete* it; // Liberar la memoria de la pelota
                pelotas.erase(it);
                break;
            }
        }
    }

    // Mover todas las pelotas
    void moverPelotas() {
        for (auto& pelota : pelotas) {
            pelota->mover();
        }
    }

    // Mostrar todas las pelotas
    void mostrarPelotas() const {
        for (const auto& pelota : pelotas) {
            pelota->mostrar();
        }
    }

    // Destructor para liberar memoria
    ~Lanzador() {
        for (auto& pelota : pelotas) {
            delete pelota;
        }
    }

    // Método para obtener las pelotas (necesario para dibujar las pelotas en la consola)
    const std::vector<Pelota*>& getPelotas() const {
        return pelotas;
    }
};
