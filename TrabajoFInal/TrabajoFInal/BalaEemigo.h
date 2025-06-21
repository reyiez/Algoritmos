#pragma once
#include<math.h>
using namespace System;
using namespace System::Drawing;
using namespace std;
#include<vector>

class balaEnemigo {

private:
	int ancho, alto;
	int dy, dx;
	int x, y;
	
public:
	balaEnemigo(int  x, int y, int fx, int fy)
	{
		fx += 32;
		fy += 32;

		this->x = x;
		this->y = y;
		ancho = alto = 10;
			
		double V = 10;
		double c1 = fx - x;
		double c2 = fy - y;
		double h = Math::Sqrt(c1 * c1 + c2 * c2);
		double C = V / h;
		dx = c1 * C;
		dy = c2 * C;
		
		}

	void dibujar(Graphics ^g) {
		Rectangle Area= Rectangle(x, y, 10, 10);;
		g->FillRectangle(Brushes::Black, Area);
	}
	void mover() {
		x += dx;
		y += dy;
	
	}

	Rectangle Zoom()
	{
		return Rectangle(x, y,10, 10);
	}

};


class BalasEnemigos
{
	std::vector<balaEnemigo*> balas;
public:
	void Agregar(balaEnemigo* bala)
	{
		balas.push_back(bala);
	}
	void Eliminar(int pos)
	{
		balas.erase(balas.begin() + pos);
	}
	int Size()
	{
		return (int)balas.size();
	}
	balaEnemigo* Get(int pos)
	{
		return balas[pos];
	}

	void Mover()
	{
		for each (balaEnemigo * e in balas)
			e->mover();
	}

	void Mostrar(Graphics^ g)
	{
		for each (balaEnemigo* e in balas)
			e->dibujar(g );
	}

	Rectangle areas() {
		for each (balaEnemigo * e in balas)
			return e->Zoom();
	}
	
};