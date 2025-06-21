#pragma once
#include "iostream"
using namespace System;
using namespace std;

class Neumatico
{
private:
	int x, y;
	char forma;

public:
	Neumatico(int px, int py, char pforma);
	~Neumatico();
	void dibujaNeumatico();
	void setX(int valor);
};//FIN DE LA CLASE

//IMPLEMENTACION
Neumatico::Neumatico(int px, int py, char pforma)
{
	this->x = px;
	this->y = py;
	this->forma = pforma;
}

Neumatico::~Neumatico(){}

void Neumatico::dibujaNeumatico()
{
	Console::SetCursorPosition(x, y);
	cout << forma;
}

void Neumatico::setX(int valor)
{
	this->x = valor;
}




