#include "pch.h"
#include "Lanzador.h"
#include <conio.h>  // Necesario para _kbhit() y _getch()
#include <iostream>
#include <thread>
#include <chrono>

using namespace System;

const int WIDTH = 20;  // Ancho de la pantalla (consola)
const int HEIGHT = 10; // Alto de la pantalla (consola)

void limpiarPantalla() {
    system("cls");
}

// Función para dibujar el estado en consola
void dibujarEstado(Lanzador& lanzadorSuperior, Lanzador& lanzadorInferior) {
    limpiarPantalla();

    // Crear la matriz de la pantalla
    char pantalla[HEIGHT][WIDTH];

    // Inicializar la matriz con espacios vacíos
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pantalla[i][j] = ' '; // Espacios vacíos
        }
    }

    // Representar el lanzador superior (azul)
    cambiarColor(9);  // Azul en la consola
    for (int i = static_cast<int>(lanzadorSuperior.getY()); i < static_cast<int>(lanzadorSuperior.getY()) + 1; i++) {
        if (i < HEIGHT) {
            pantalla[i][static_cast<int>(lanzadorSuperior.getX())] = 219; // Lanzador superior
        }
    }

    // Representar el lanzador inferior (rojo)
    cambiarColor(12);  // Rojo en la consola
    for (int i = static_cast<int>(lanzadorInferior.getY()); i < static_cast<int>(lanzadorInferior.getY()) + 1; i++) {
        if (i < HEIGHT) {
            pantalla[i][static_cast<int>(lanzadorInferior.getX())] = 219; // Lanzador inferior
        }
    }

    // Representar las pelotas
    cambiarColor(15);  // Color blanco (o color normal) para las pelotas
    for (const auto& pelota : lanzadorSuperior.getPelotas()) {
        if (pelota->getX() < WIDTH && pelota->getY() < HEIGHT) {
            pantalla[static_cast<int>(pelota->getY())][static_cast<int>(pelota->getX())] = 'o'; // Pelota azul
        }
    }
    for (const auto& pelota : lanzadorInferior.getPelotas()) {
        if (pelota->getX() < WIDTH && pelota->getY() < HEIGHT) {
            pantalla[static_cast<int>(pelota->getY())][static_cast<int>(pelota->getX())] = 'o'; // Pelota roja
        }
    }

    // Dibujar la matriz de pantalla en la consola
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            std::cout << pantalla[i][j];  // Imprimir cada celda de la matriz
        }
        std::cout << std::endl;
    }

    // Restaurar color predeterminado de la consola
    cambiarColor(15);  // Color blanco para el texto predeterminado
}

int main() {
    srand(time(0)); // Semilla para números aleatorios

    // Crear los lanzadores en posiciones izquierda y derecha
    Lanzador lanzadorSuperior(2, 2);  // Lanzador superior en la izquierda
    Lanzador lanzadorInferior(18, HEIGHT - 2);  // Lanzador inferior en la derecha

    // Bucle principal
    char tecla;
    while (true) {
        if (_kbhit()) { // Verifica si se presionó una tecla
            tecla = _getch();

            if (tecla == 'A' || tecla == 'a') {
                lanzadorSuperior.lanzarPelota("Azul"); // Lanzar pelota azul
            }
            else if (tecla == 'R' || tecla == 'r') {
                lanzadorInferior.lanzarPelota("Roja"); // Lanzar pelota roja
            }
            else if (tecla == 'X' || tecla == 'x') {
                lanzadorSuperior.eliminarPelota("Azul"); // Eliminar pelota azul
            }
            else if (tecla == 'E' || tecla == 'e') {
                lanzadorInferior.eliminarPelota("Roja"); // Eliminar pelota roja
            }
            else if (tecla == 'Q' || tecla == 'q') {
                break; // Salir del programa
            }
        }

        // Mover y mostrar pelotas
        lanzadorSuperior.moverPelotas();
        lanzadorInferior.moverPelotas();

        // Dibujar el estado actual de los lanzadores y pelotas
        dibujarEstado(lanzadorSuperior, lanzadorInferior);

        // Esperar un poco antes de volver a mostrar
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
