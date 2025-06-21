#pragma once
#include "Chasis.h"
#include "Neumatico.h"

class Auto
{
private:
	Chasis* ObjChasis;
	Neumatico** arreglo;
	Neumatico* ObjNeumatico;
	double x, dx;
	int y;
public:
	Auto(double px, double py);
	~Auto();
	void borrar();
	void mover();
	void dibujar();

	double getx();
	double getDx();
};//Fin de la clase
//Implementacion
Auto::Auto(double px, double py)
{
	this->x = px;
	this->y = py;
	dx = 0.1 + (double)rand() / RAND_MAX;
	//instancia los 4 neumaticos
	arreglo = new Neumatico * [4];//arreglo de 4 elementos
	//4 llantas
	ObjNeumatico = new Neumatico(x, y, (char)157);
	arreglo[0] = ObjNeumatico;
	ObjNeumatico = new Neumatico(x+2, y, (char)157);
	arreglo[1] = ObjNeumatico;
	ObjNeumatico = new Neumatico(x, y+2, (char)157);
	arreglo[2] = ObjNeumatico;
	ObjNeumatico = new Neumatico(x+2, y+2, (char)157);
	arreglo[3] = ObjNeumatico;
	//1 chasis
	ObjChasis = new Chasis(x, y + 1, (char)178);
}
Auto::~Auto()
{
	delete ObjNeumatico;
	delete ObjChasis;
	delete arreglo;
}

void Auto::borrar(){
	Console::SetCursorPosition(x, y); cout << "        ";
	Console::SetCursorPosition(x, y+1); cout << "        ";
	Console::SetCursorPosition(x, y+2); cout << "        ";
	
}
void Auto::mover(){
	x = x + dx;
	//mover los neumaticos
	arreglo[0]->setX(x);
	arreglo[1]->setX(x+2);
	arreglo[2]->setX(x);
	arreglo[3]->setX(x+2);
	//mueve chasis
	ObjChasis->setX(x);

}
void Auto::dibujar() 
{
	for (int i = 0; i < 4; i++)
	{
		arreglo[i]->dibujaNeumatico();
	}
	ObjChasis->dibujaChasis();

}


double Auto::getx() { return this->x; }
double Auto::getDx() { return this->dx; }
