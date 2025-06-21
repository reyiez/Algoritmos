#pragma once
#include "Auto.h"

class Carrera
{
private: 
	Auto** arreglo;
	Auto* ObjAuto;
public:
	Carrera();
	~Carrera();
	void IniciaCarrera();
};//FIN DE LA CLASE

//IMPLEMENTACION
Carrera::Carrera()
{
	//crea 3 autos
	arreglo = new Auto * [3];
	//en que posicion incian los 3 autos
	ObjAuto = new Auto(1, 5); arreglo[0] = ObjAuto;
	ObjAuto = new Auto(1, 12); arreglo[1] = ObjAuto;
	ObjAuto = new Auto(1, 20); arreglo[2] = ObjAuto;
}
Carrera::~Carrera()
{
	delete ObjAuto;
	delete arreglo;
}

void Carrera::IniciaCarrera()
{
	//dibuja los 3 AUTOS
	for (int i = 0; i < 3; i++) arreglo[i]->dibujar();
	int i = 0;
	while (1)
	{
		arreglo[i]->borrar();
		arreglo[i]->mover();
		arreglo[i]->dibujar();

		i++;
		if (i > 2) i = 0;

		_sleep(100);
	}
}
