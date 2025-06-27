#include "pch.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Juego.h"
#include "Mapa.h"
using namespace System;
using namespace std;
void ventana() {
    Console::SetWindowSize(120, 50);
}
// Centra texto horizontalmente
void centrarTexto(const string& texto) {
    int anchoPantalla = 80;
    int espacios = (anchoPantalla - texto.length()) / 2;
    for (int i = 0; i < espacios; i++) {
        cout << " ";
    }
    cout << texto << endl;
}

// Cambiar color del texto
void cambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Mostrar título ASCII
void mostrarTitulo() {
    cambiarColor(10);
    centrarTexto(" ");
    centrarTexto(" ");
    centrarTexto(R"(
                     ##   ##  ######     ####            #####   ##   ##  #######   #####   ######
                     ##   ##   ##  ##   ##  ##          ##   ##  ##   ##   ##   #  ##   ##  # ## #
                     ##   ##   ##  ##  ##               ##   ##  ##   ##   ## #    #          ##
                     ##   ##   #####   ##               ##   ##  ##   ##   ####     #####     ##
                     ##   ##   ##      ##               ##   ##  ##   ##   ## #         ##    ##
                     ##   ##   ##       ##  ##          ##  ###  ##   ##   ##   #  ##   ##    ##
                      #####   ####       ####            #####    #####   #######   #####    ####
                                                           ##
    )");
    cambiarColor(7);
    centrarTexto(" ");
}

// Mostrar el logo UPC
void mostrarLogo(int x, int y) {
    cambiarColor(12);
    string upc[9] = {
        "	0	0	0	0	0	0	0	0	0	4	0	0	0	0	0	0	0	0	0	",
        "	0	0	0	4	0	0	0	0	4	1	0	0	0	0	4	0	0	0	0	",
        "	0	0	4	0	0	0	0	4	1	0	0	0	0	0	0	4	0	0	0	",
        "	0	4	1	0	0	0	0	0	1	1	2	0	0	0	0	4	1	0	0	",
        "	0	4	1	1	0	0	0	0	0	1	1	0	0	0	1	1	1	0	0	",
        "	0	1	1	1	1	0	0	0	1	1	0	0	0	1	1	1	1	0	0	",
        "	0	3	1	1	1	1	2	0	3	0	0	2	1	1	1	1	3	0	0	",
        "	0	0	3	1	1	1	1	1	1	1	1	1	1	1	1	3	0	0	0	",
        "	0	0	0	0	3	1	1	1	1	1	1	1	1	3	0	0	0	0	0	"
    };

    for (int i = 0; i < 9; i++) {
        COORD coord;
        coord.X = x;
        coord.Y = y + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (char c : upc[i]) {
            switch (c) {
            case '0': cambiarColor(0); cout << " "; break;
            case '1': cambiarColor(215); cout << " "; break;
            case '2': cambiarColor(172); cout << " "; break;
            case '3': cambiarColor(118); cout << " "; break;
            case '4': cambiarColor(237); cout << " "; break;
            default: break;
            }
        }
        cout << endl;
    }
}

// Mostrar las reglas del juego
void mostrarReglas() {
    system("cls");
    for (int i = 0; i < 8; ++i) centrarTexto(" ");
    cambiarColor(9);
    centrarTexto("                                    =============== REGLAS DEL JUEGO =============== ");
    cambiarColor(14);
    cout << "                            El jugador debe de recolectar los recursos dispersos por los 3 mundos\n";
    cout << "                            evitando que el contador llegue a cero, de lo contrario perdera y debera\n";
    cout << "                            volver a intentarlo. Si el jugador consigue los recursos necesarios viajara\n";
    cout << "                            hacia el siguiente mundo. Debera de evitar a los enemigos dispersos los cuales\n";
    cout << "                            quitan vida si los tocas.\n";
    cambiarColor(7);
    cout << "\n                                   Presiona cualquier tecla para regresar al menu principal.";
    _getch();
}

// Mostrar los créditos del juego
void mostrarCreditos() {
    system("cls");
    for (int i = 0; i < 8; ++i) centrarTexto(" ");
    cambiarColor(5);
    centrarTexto("                                    =============== CREDITO DEL JUEGO =============== ");
    cambiarColor(11);
    cout << "                                                   Desarrollado por:\n";
    centrarTexto(" ");
    cout << "                                                     Victor Hidalgo\n";
    cout << "                                                     Sebastian Reyes\n";
    cout << "                                                     Cielo Atencio\n";
    centrarTexto(" ");
    cout << "                                                        Ciclo:\n";
    cout << "                                                       2025-01\n";
    cambiarColor(7);
    cout << "\n                                   Presiona cualquier tecla para regresar al menu principal.";
    _getch();
}

// Mostrar menú principal
void mostrarMenu() {
    system("cls");
    for (int i = 0; i < 8; ++i) centrarTexto(" ");
    centrarTexto("                                    =============== MENU PRINCIPAL =============== ");
    cambiarColor(10);
    centrarTexto(" ");
    centrarTexto("                                      1. Iniciar Juego");
    cambiarColor(9);
    centrarTexto(" ");
    centrarTexto("                                      2. Reglas");
    cambiarColor(5);
    centrarTexto(" ");
    centrarTexto("                                      3. Creditos");
    cambiarColor(6);
    centrarTexto(" ");
    centrarTexto("                                      4. Salir");
    cambiarColor(7);
    centrarTexto(" ");
}

int main() {
    ventana();
    int posX = 48;
    int posY = 1;

    mostrarLogo(posX, posY);
    mostrarTitulo();

    cout << "                           Presiona cualquier tecla para continuar al menu de opciones...";
    _getch();

    char opcion;
    do {
        mostrarMenu();
        centrarTexto(" ");
        cout << "                                                Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            centrarTexto(" ");
            cambiarColor(10);
            cout << "                                                   Iniciando juego..." << endl;

            _sleep(1000);
            system("cls");

            {

                Juego juego;
                juego.Iniciar();

                system("cls");

            }
            system("cls");
            break;
        case '2':
            mostrarReglas();
            break;
        case '3':
            mostrarCreditos();
            break;
        case '4':
            centrarTexto(" ");
            cambiarColor(6);
            cout << "                                                      Saliendo..." << endl;
            break;
        default:
            centrarTexto(" ");
            cout << "                                                   Opcion no valida." << endl;
        }

    } while (opcion != '4');

    return 0;
}
