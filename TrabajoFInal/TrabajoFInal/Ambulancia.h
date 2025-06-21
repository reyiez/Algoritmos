#pragma once
#include"Entidad.h"
#include<vector>
class CAmbulancia :public::Entidad{

	int JX, JY;

public:

	CAmbulancia() 
	{
		x = y = 400;
		ancho = 102/6;
		alto = 26;
		indiceX = 0;
		indiceY = 0;
		dx = 10; dy = 10;
		escala = 3.0;
	}

	void mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width) { x += dx; }
		else
		{
			dx *= -1;
		}
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height) { y += dy; }
		else
		{
			dy *= -1;
		}
	
		if (dx > 0) {
			indiceY = 1;
		}
		else if(dy<0){
			indiceY = 3;
		}
		if (dy > 0) {
			indiceY = 2;
		}
		else if(dy<0) {
			indiceY = 0;
		}
	indiceX++;
	if (indiceX > 2)indiceX = 0;


	}

	void Atrapar(Graphics^ g)
	{
		double V = 5;
		double c1 = JX - x;
		double c2 = JY - y;
		double H = Math::Sqrt(c1 * c1 + c2 * c2);
		double C = V / H;

		dx = C * c1;
		dy = C * c2;
		x += dx;
		y += dy;
	}

	void dibujar(Graphics^ g, Bitmap^img) 
	{
		g->DrawImage(img, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
	}

	void SetJX(int n){JX = n;}
	
	void SetJY(int n){JY = n;}
	
	int getJX() { return JX; }
	
	int getJY() { return JY; }

};

class Ambulancias
{
	std::vector<CAmbulancia*>ambulancias;
public:

	void agregarAmbulancia(CAmbulancia * ambulancia)
	{
		ambulancias.push_back(ambulancia);
	}

	void eliminarAmbulancia(int pos)
	{
		ambulancias.erase(ambulancias.begin() + pos);
	}

	int getCantidad()
	{
		return ambulancias.size();
	}

	CAmbulancia* getAmbulancias(int i)
	{
		return ambulancias[i];
	}

	void mover(Graphics^ g)
	{
		for each (CAmbulancia* E in ambulancias)
			E->mover(g);
	}

	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		for each (CAmbulancia * E in ambulancias)
			E->dibujar(g, bmp);
	}

	void atrapar(Graphics^ g)
	{
		for each (CAmbulancia * E in ambulancias)
			E->Atrapar(g);
	}
};