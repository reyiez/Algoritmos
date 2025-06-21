#pragma once
#include"Bala.h"
#include<ctime>
#include<cstdlib>
#include"Entidad.h"
class CHeroe :public::Entidad
{
private:
	Direcciones direccion;
	CBalas* balas;
	int vidas;
public:
	
	CHeroe() {

		x =y = 100;
		dx = 0; dy = 0;
		indiceX = 0;
		alto = 256 / 4;
		ancho =256 / 4;
		direccion = Abajo;
		balas = new CBalas();
		escala = 1;
		vidas = 5;
	}
	~CHeroe() {}


	void mover(Graphics^ g )
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width)
			x += dx;
		if (y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)
			y += dy;
		balas->Mover(g);
	}
	void dibujar(Graphics^ g, Bitmap^ img)
	{
		Rectangle porcionAUsar = Rectangle(indiceX * ancho, direccion * alto, ancho, alto);
		g->DrawImage(img, Zoom(), porcionAUsar, GraphicsUnit::Pixel);
		indiceX = (indiceX + 1) % 4;
		if (dx == 0 && dy == 0)
			indiceX = 0;
	}

	void setDireccion(Direcciones nueva) {
	
		direccion = nueva;
	}
	int getVidas() { return vidas; }

	void MovimientoJugadorDX(int dx)
	{
		this->dx = dx;
	}
	void MovimientoJugadorDY(int dy)
	{
		this->dy = dy;
	}


	void mostrarMensaje(Graphics^ g, Bitmap^ img)
	{
		balas->Mostrar(g, img);
	}

	void SetVidas(int n)
	{
		vidas = n;
	}


	void disparar()
	{
		int dx1 = 0, dy1 = 0;
		if (direccion == Abajo)
			dy1 = 20;
		else if (direccion==Arriba)
			dy1 = -20;
		else if (direccion==Izquierda)
			dx1 = -20;
		else if (direccion==Derecha)
			dx1 = 20;

		CBala* msj = new CBala(x, y, dx1, dy1,rand()%3);
		balas->agregarBala(msj);
	}

	CBalas* getBalas()
	{
		return balas;
	}
};