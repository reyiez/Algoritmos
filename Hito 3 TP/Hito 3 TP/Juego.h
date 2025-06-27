#pragma once
#include "VigilanteDelEquilibrio.h"
#include "Enemigo.h"
#include"Enemigo2.h"
#include"Enemigo3.h"
#include "Aliado.h"
#include "Mapa.h"
#include "Mapa2.h"
#include "Mapa3.h"
#include <iostream>
#include <conio.h>


using namespace System;
using namespace std;

class Juego {
public:
    void Iniciar();
    void GestionarRecursos();
    void Dibujar();
    void Borrar();
    void MoverVigilante();
    void MoverEnemigo();
    void MoverEnemigo_2();
    void MoverEnemigo_3();
    bool detectarColision();
    void CrearPortal();
    void MostrarPortal();
    void CrearRecursos();
    void ConfigurarNivel2();
    void ConfigurarNivel3();
    void GestionarCaja();
    void ConfigurarNivelFinal();

private:

    VigilanteDelEquilibrio vigilante;

    Enemigo enemigo;
    Enemigo_2 enemigo2;
    Enemigo_3 enemigo3;

    Aliado aliado;
    Mapa* mapa;
    Mapa2* mapa2;
    Mapa3* mapa3;


    bool aliadoActivo = true;
    int xV = 40, yV = 20; // Posicion del vigilante

    int xE = 5, yE = 5;  // Posicion del enemigo1
    int dxE = 1, dyE = 1; // Direccion de movimiento enemigo1

    int xE2 = 25, yE2 = 30;  // Posicion del enemigo2
    int dxE2 = 1, dyE2 = 1; // Direccion de movimiento enemigo2

    int xE3 = 60, yE3 = 15;  // Posicion del enemigo3
    int dxE3 = 1, dyE3 = 1; // Direccion de movimiento enemigo3

    int fase = 1;
    int fase2 = 1;
    int fase3 = 1;
    int contador = 0;
    int invulnerable = 0;
    int recursosRecogidos = 0;
    int recursosObjetivo = 6;  // 6 recursos en el mapa
    int portalX = 0, portalY = 0;
    int nivel = 1;
    int tiempoReducirVelocidad = 0;
    int recursos[6][2];  // Ahora hay 6 recursos
    bool recursosRecogidosFlag[6] = { false, false, false, false, false, false };
};
//Fin de la clase

//Implementacion
void Juego::Iniciar() {
    srand(time(0));
    mapa = new Mapa(mapa1);
    mapa->genera_mapa();

    xE = rand() % 90 + 5;  
    yE = rand() % 30 + 5; 

    xE2 = rand() % 90 + 5; 
    yE2 = rand() % 30 + 5; 

    xE3 = rand() % 90 + 5;
    yE3 = rand() % 30 + 5;

    vigilante.MostrarVidas();
    vigilante.DibujarFigura(xV, yV);

    enemigo.DibujarFigura(xE, yE);
    enemigo2.DibujarFigura2(xE2, yE2);
    enemigo3.DibujarFigura3(xE3, yE3);

    aliado.GenerarPosicionAleatoria(90, 35);
    aliadoActivo = true; // Activar el aliado

    CrearRecursos();
    CrearPortal();
    MostrarPortal();

    Console::SetCursorPosition(0, 45);
    cout << "Recursos Obtenidos: " << recursosRecogidos << "/" << recursosObjetivo;

    while (true) {
        MoverVigilante();
        Borrar();

        if (nivel != 4) {

            MoverEnemigo();
            MoverEnemigo_2();
            MoverEnemigo_3();
            GestionarRecursos();
            MostrarPortal();
        }

        Dibujar();

        if (nivel == 3) {
            GestionarCaja();
        }

        if (detectarColision() && invulnerable == 0) {
            vigilante.QuitarVida();
            invulnerable = 40;

            if (vigilante.ObtenerVidas() <= 0) {
                Console::SetCursorPosition(30, 40);
                Console::ForegroundColor = ConsoleColor::Red;
                cout << "¡ Perdiste ! Te quedaste sin vidas...";
                break;
            }
        }

        if (invulnerable > 0) {
            invulnerable--;
        }

        _sleep(50);
    }
    Console::SetCursorPosition(0, 39);
}



void Juego::Dibujar() {
    vigilante.DibujarFigura(xV, yV);

    if (nivel != 4) {
        enemigo.DibujarFigura(xE, yE);
        enemigo2.DibujarFigura2(xE2, yE2);
        enemigo3.DibujarFigura3(xE3, yE3);

        for (int i = 0; i < 6; i++) {
            if (!recursosRecogidosFlag[i]) {
                int recursoX = recursos[i][0];
                int recursoY = recursos[i][1];
                Console::SetCursorPosition(recursoX, recursoY);
                if (nivel == 1) {
                    cout << "@";
                }
                else {
                    cout << "%";
                }
            }
        }

        if (aliadoActivo) {
            aliado.Dibujar();
        }
    }
}

void Juego::Borrar() {
    enemigo.BorrarFigura(xE, yE);
    enemigo2.BorrarFigura2(xE2, yE2);
    enemigo3.BorrarFigura3(xE3, yE3);
    if (aliadoActivo) {
        aliado.Borrar();
    }
}

void Juego::MoverVigilante() {
    if (_kbhit()) {
        vigilante.BorrarFigura(xV, yV);
        char tecla = _getch();

        if (tecla == 72 && yV > 0) yV--;         // Arriba
        if (tecla == 80 && yV < 35) yV++;        // Abajo
        if (tecla == 77 && xV < 100) xV++;       // Derecha
        if (tecla == 75 && xV > 0) xV--;         // Izquierda

        vigilante.DibujarFigura(xV, yV);
    }
}

void Juego::MoverEnemigo() {
    if (nivel == 4) return; 

    static double acumulador1 = 0.0;
    acumulador1 += enemigo.ObtenerVelocidad();

    if (acumulador1 >= 1.0) {
        yE += dyE;
        if (yE <= 0 || yE + 4 >= 40) dyE *= -1;
        acumulador1 -= 1.0;
    }
}

void Juego::MoverEnemigo_2() {
    if (nivel == 4) return; 

    static double acumulador2 = 0.0;
    acumulador2 += enemigo2.ObtenerVelocidad2();

    if (acumulador2 >= 1.0) {
        xE2 += dxE2;
        if (xE2 <= 0 || xE2 >= 90) dxE2 *= -1;
        acumulador2 -= 1.0;
    }
}

void Juego::MoverEnemigo_3() {
    if (nivel == 4) return; 

    static double acumulador3 = 0.0;
    acumulador3 += enemigo3.ObtenerVelocidad3();

    if (acumulador3 >= 1.0) {
        xE3 += dxE3;
        yE3 += dyE3;
        if (xE3 <= 0 || xE3 >= 90) dxE3 *= -1;
        if (yE3 <= 0 || yE3 + 4 >= 40) dyE3 *= -1;
        acumulador3 -= 1.0;
    }
}

bool Juego::detectarColision() {
    if (nivel == 4) {
        return false;
    }

    if (xV + 6 >= xE && xV <= xE + 6) {
        if (yV + 4 >= yE && yV <= yE + 4) {
            return true;
        }
    }
    if (xV + 6 >= xE2 && xV <= xE2 + 6) {
        if (yV + 4 >= yE2 && yV <= yE2 + 4) {
            return true;
        }
    }
    if (xV + 6 >= xE3 && xV <= xE3 + 6) {
        if (yV + 4 >= yE3 && yV <= yE3 + 4) {
            return true;
        }
    }

    const int vLeft = xV;
    const int vRight = xV + 6;
    const int vTop = yV;
    const int vBottom = yV + 4;

    int ax = aliado.ObtenerX();
    int ay = aliado.ObtenerY();
    if (aliadoActivo &&
        ax >= vLeft && ax <= vRight &&
        ay >= vTop && ay <= vBottom) {
        aliado.Borrar();
        aliadoActivo = false;

        enemigo.CambiarVelocidad(0.0);

        enemigo2.CambiarVelocidad2(0.0);

        enemigo3.CambiarVelocidad3(0.0);

        tiempoReducirVelocidad = 120;
    }

    if (tiempoReducirVelocidad > 0) {
        tiempoReducirVelocidad--;

        if (tiempoReducirVelocidad == 0) {
            enemigo.RestablecerVelocidad();
            enemigo2.RestablecerVelocidad2();
            enemigo3.RestablecerVelocidad3();
        }
    }

    if (portalX >= vLeft && portalX <= vRight &&
        portalY >= vTop && portalY <= vBottom) {
        if (recursosRecogidos == recursosObjetivo) {
            Console::SetCursorPosition(30, 37);
            Console::ForegroundColor = ConsoleColor::Green;
            cout << "Nivel completado! Pasando al siguiente nivel...";
            _sleep(1000);

            if (nivel == 1) {
                ConfigurarNivel2();
            }
            else if (nivel == 2) {
                ConfigurarNivel3();
            }
            return true;
        }
    }

    return false;
}

void Juego::ConfigurarNivel2() {

    nivel = 2;
    Console::Clear();
    delete mapa; // Elimina el mapa actual
    mapa = new Mapa2(); // Cambia al segundo mapa
    mapa->genera_mapa();

    if (vigilante.ObtenerVidas() < 3) {
        vigilante.RestaurarVidas();
    }

    for (int i = 0; i < 6; i++) recursosRecogidosFlag[i] = false;
    recursosRecogidos = 0;
    CrearRecursos();

    enemigo.CambiarColor(ConsoleColor::Red);
    xV = 40;  yV = 20;
    xE = 5;  yE = 5;

    enemigo2.CambiarColor2(ConsoleColor::Red);
    xE2 = 25;  yE2 = 30;

    enemigo3.CambiarColor3(ConsoleColor::Red);
    xE3 = 60;  yE3 = 15;

    CrearPortal();

    aliado.GenerarPosicionAleatoria(90, 35);
    aliadoActivo = true;

    vigilante.MostrarVidas();
    vigilante.DibujarFigura(xV, yV);

    enemigo.DibujarFigura(xE, yE);
    enemigo2.DibujarFigura2(xE2, yE2);
    enemigo3.DibujarFigura3(xE3, yE3);

    aliado.Dibujar();
    Console::SetCursorPosition(0, 45);
    cout << "Recursos Obtenidos: " << recursosRecogidos << "/" << recursosObjetivo;
}

void Juego::ConfigurarNivel3() {
    nivel = 3;
    Console::Clear();

    if (vigilante.ObtenerVidas() < 3) {
        vigilante.RestaurarVidas();
    }

    xV = 50;  yV = 25;
    xE = 10;  yE = 10;
    xE2 = 35;  yE2 = 20;
    xE3 = 70;  yE3 = 10;

    enemigo.CambiarColor(ConsoleColor::Yellow);
    enemigo2.CambiarColor2(ConsoleColor::Yellow);
    enemigo3.CambiarColor3(ConsoleColor::Yellow);

    vigilante.MostrarVidas();
    vigilante.DibujarFigura(xV, yV);
    enemigo.DibujarFigura(xE, yE);
    enemigo2.DibujarFigura2(xE2, yE2);
    enemigo3.DibujarFigura3(xE3, yE3);

    // Dibujar aliado
    aliado.GenerarPosicionAleatoria(90, 35);
    aliadoActivo = true;
    aliado.Dibujar();

    int cajaX = 50, cajaY = 20; 
    Console::SetCursorPosition(cajaX, cajaY);
    Console::ForegroundColor = ConsoleColor::Yellow; 
    cout << (char)219;
    Console::ResetColor();

    Console::SetCursorPosition(0, 47);
    cout << "Nivel 3: Acércate a la caja para depositar los recursos.";
}

void Juego::ConfigurarNivelFinal() {
    nivel = 4; 
    Console::Clear();
    delete mapa; 
    mapa = new Mapa3(); 
    mapa->genera_mapa();


    enemigo.BorrarFigura(xE, yE);
    enemigo2.BorrarFigura2(xE2, yE2);
    enemigo3.BorrarFigura3(xE3, yE3);
    if (aliadoActivo) {
        aliado.Borrar();
        aliadoActivo = false; 
    }

    xV = 50; yV = 25;
    vigilante.MostrarVidas();
    vigilante.DibujarFigura(xV, yV);

    Console::SetCursorPosition(0, 47);
    cout << "Nivel Final: Solo el vigilante está presente.";
}

void Juego::CrearRecursos() {
    for (int i = 0; i < 6; i++) {
        recursos[i][0] = rand() % 90 + 10;
        recursos[i][1] = rand() % 30 + 5;
    }
}

void Juego::CrearPortal() {
    portalX = rand() % 90 + 10;
    portalY = rand() % 35 + 5;
}

void Juego::MostrarPortal() {
    if (nivel != 3 && nivel != 4 && recursosRecogidos >= recursosObjetivo) {
        
        Console::SetCursorPosition(portalX, portalY);
        Console::ForegroundColor = ConsoleColor::Magenta;
        cout << (char)219;
        Console::ResetColor();
    }
}

void Juego::GestionarRecursos() {
    for (int i = 0; i < 6; i++) {
        if (!recursosRecogidosFlag[i]) {
            int recursoX = recursos[i][0];
            int recursoY = recursos[i][1];

            if (abs(xV - recursoX) <= 2 && abs(yV - recursoY) <= 2) {

                Console::SetCursorPosition(0, 46);
                cout << "Presiona 'E' para recoger el recurso en (" << recursoX << ", " << recursoY << ").";

                if (_kbhit()) {
                    char tecla = _getch();
                    if (tecla == 'e' || tecla == 'E') {
                        recursosRecogidos++;
                        recursosRecogidosFlag[i] = true;
                        Console::SetCursorPosition(0, 45);
                        cout << "Recursos Obtenidos: " << recursosRecogidos << "/" << recursosObjetivo;

                        Console::SetCursorPosition(recursoX, recursoY);
                        cout << " ";

                        if (recursosRecogidos >= recursosObjetivo) {
                            CrearPortal();
                            Console::SetCursorPosition(0, 47);
                            cout << "¡Recursos completos! El portal aparece.";
                        }
                    }
                }
            }
        }
    }
}

void Juego::GestionarCaja() {
    int cajaX = 50, cajaY = 20; 


    if (abs(xV - cajaX) <= 2 && abs(yV - cajaY) <= 2) {
        Console::SetCursorPosition(30, 40);
        Console::ForegroundColor = ConsoleColor::Green;
        cout << "¡Avanzando al nivel final!";
        _sleep(1000);

        ConfigurarNivelFinal(); 
    }
}
