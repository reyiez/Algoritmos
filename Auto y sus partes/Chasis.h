#pragma once
#include "iostream"
using namespace System;
using namespace std;

class Chasis
{
private:
	int x, y;
	char forma;
public:
	Chasis(int px, int py, char pforma);//constructor con parametros
	~Chasis();
	void dibujaChasis();
	void setX(int valor);
};//FIN DE LA CLASE
//IMPLEMENTACION
Chasis::Chasis(int px, int py, char pforma)
{
	this->x = px;
	this->y = py;
	this->forma = pforma;
}

Chasis::~Chasis()
{}

void Chasis::dibujaChasis()
{
	Console::SetCursorPosition(x, y);
	cout << forma << forma << forma<<forma;
}
void Chasis::setX(int valor)
{
	this->x = valor;
}