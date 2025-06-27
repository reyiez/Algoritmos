#pragma once
#include <iostream>
using namespace System;
using namespace std;

const int filas = 45;
const int columnas = 120;

// Estructura para un carácter con colores RGB de texto y fondo
struct CharWithColors {
    char character;
    int r_fg, g_fg, b_fg; // color texto
    int r_bg, g_bg, b_bg; // color fondo

    CharWithColors(char c = ' ', int r1 = 255, int g1 = 255, int b1 = 255,
        int r2 = 0, int g2 = 0, int b2 = 0)
        : character(c), r_fg(r1), g_fg(g1), b_fg(b1),
        r_bg(r2), g_bg(g2), b_bg(b2) {
    }
};

class MapaRGB {
public:
    CharWithColors mapa[filas][columnas];

    MapaRGB() {
        // Inicializa mapa con fondo negro y espacio blanco (ajusta si quieres)
        for (int y = 0; y < filas; y++) {
            for (int x = 0; x < columnas; x++) {
                mapa[y][x] = CharWithColors(' ', 255, 255, 255, 0, 0, 0);
            }
        }
    }

    // Dibuja todo el mapa
    void DibujarMapaCompleto() {
        Console::CursorVisible = false;
        for (int y = 0; y < filas; y++) {
            for (int x = 0; x < columnas; x++) {
                DibujarCelda(x, y);
            }
        }
    }

    // Dibuja una sola celda del mapa usando colores RGB con secuencias ANSI
    void DibujarCelda(int x, int y) {
        if (x < 0 || x >= columnas || y < 0 || y >= filas) return;

        CharWithColors& c = mapa[y][x];
        Console::SetCursorPosition(x, y);

        // Secuencia ANSI: texto y fondo RGB
        printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm%c\033[0m",
            c.r_fg, c.g_fg, c.b_fg,
            c.r_bg, c.g_bg, c.b_bg,
            c.character);
    }

    // Opcional: función para cambiar celda (texto y colores)
    void SetCelda(int x, int y, CharWithColors c) {
        if (x < 0 || x >= columnas || y < 0 || y >= filas) return;
        mapa[y][x] = c;
    }
};
