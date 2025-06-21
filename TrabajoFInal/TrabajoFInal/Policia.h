#pragma once
#include"Entidad.h"
#include<vector>
class CPolicia:public::Entidad
{
	int JX, JY;
	int movimiento;
public:
	CPolicia() {
		x = y = 100;
		ancho = 128 / 4;
		alto = 192 / 4;
		indiceX = 0;
		indiceY = 0;
		dx = dy = 10;
		escala = 1.5;
		movimiento = 1;
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
			indiceY = 2;
		}
		else if (dy < 0) {
			indiceY = 1;
		}
		if (dy > 0) {
			indiceY = 0;
		}
		else if (dy < 0) {
			indiceY = 3;
		}
		indiceX++;
		if (indiceX > 3)indiceX = 0;


	}

	void dibujar(Graphics^ g, Bitmap^ img)
	{
		g->DrawImage(img, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
	}

	void Atrapar(Graphics^ g)
	{


		double V = 10;
		double c1 = JX - x;
		double c2 = JY - y;
		double H = Math::Sqrt(c1 * c1 + c2 * c2);
		double C = V / H;

		dx = C * c1;
		dy = C * c2;


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

		/*x += dx;
		y += dy;*/
	}

	int getMovimiento() { return movimiento; }

	void setMovimientos(int valor) { movimiento = valor; }

	void cambioMovimiento(Graphics^ g ,int movimiento) {
		this->movimiento = movimiento;

		switch (movimiento)
		{

		case 1:
			mover(g);
			break;

		case 2:
			Atrapar(g);
			break;

		default:
			break;
		}
	}

	void SetJX(int n) { JX = n; }

	void SetJY(int n) { JY = n; }
	
	int getJX() { return JX; }
	
	int getJY() { return JY; }
};

class Policias
{
	std::vector<CPolicia*>policias;

public:

	void agregarPolicia(CPolicia* policia)
	{
		policias.push_back(policia);
	}

	void eliminarPolicia(int pos)
	{
		policias.erase(policias.begin() + pos);
	}

	int getCantidad()
	{
		return policias.size();
	}

	CPolicia* getCPolicia(int i)
	{
		return policias[i];
	}

	void mover(Graphics^ g)
	{
		for each (CPolicia * E in policias)
			E->mover(g);
	}

	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		for each (CPolicia * E in policias)
			E->dibujar(g, bmp);
	}
	
	void atrapar(Graphics^ g)
	{
		for each (CPolicia * E in policias)
			E->Atrapar(g);
	}

	void cambioMovimiento(Graphics^ g, int movimimiento)
	{
		for each (CPolicia * E in policias)
			E->cambioMovimiento(g, movimimiento);
	}
};