#pragma once
#include"Entidad.h"

class CBala :public::Entidad
{
public:
	CBala(int x , int y , int dx , int dy , int indY) {
		
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		alto =674/3 ;
		ancho =442 ;
		escala = 0.3;
		indiceY = indY;
	}

	void dibujar(Graphics^ g, Bitmap^ bmp)
	{
		//Rectangle corte = Rectangle(indiceX* ancho, indiceY* alto, ancho, alto);
		g->DrawImage(bmp, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
		indiceX = (indiceX + 1) % 1;
	}
};

class CBalas 
{
private:
	CBala** arreglo;
	int cant;

public:

	CBalas()
	{
		cant = 0;
	}
	~CBalas()
	{
		for (int i = 0; i < cant; i++)
			delete arreglo[i];
		delete[]arreglo;
	}
	void agregarBala(CBala *bala)
	{
		CBala** aux = new CBala * [cant + 1];

		for (int i = 0; i < cant; i++)
			aux[i] = arreglo[i];
		aux[cant] = bala;
		cant++;

		arreglo = aux;
	
	}

	void eliminarBala(CBala * eliminado)
	{
		CBala** aux = new CBala * [cant - 1];
		int i;
		for (i = 0; arreglo[i] != eliminado; i++)
			aux[i] = arreglo[i];

		for (int j = i; j < cant-1; j++)
			aux[j] = arreglo[j + 1];

		delete eliminado;
		cant--;
		arreglo = aux;
	}


	void eliminarBala(int pos)
	{
		CBala** aux = new CBala * [cant - 1];
		
		for (int i = 0; i<pos; i++)
			aux[i] = arreglo[i];

		for (int j = pos; j < cant - 1; j++)
			aux[j] = arreglo[j + 1];

		delete arreglo[pos];
		cant--;
		arreglo = aux;
	}


	CBala *getBala(int pos)
	{
		return arreglo[pos];
	}

	int getCantidad()
	{
		return cant;
	}

	void Mover(Graphics ^g)
	{
		for (int i = 0; i < cant; i++)
		{
			CBala* bala = arreglo[i];
			if (bala->GetX() >= g->VisibleClipBounds.Width || 
				bala->GetX() + bala->GetAncho() < 0 ||
				bala->GetY() >= g->VisibleClipBounds.Height ||
				bala->GetY() + bala->GetAlto() < 0)
				eliminarBala(i--);
		}

		for (int i = 0; i < cant; i++)
			arreglo[i]->Mover(g);
	}

	void Mostrar(Graphics^ g, Bitmap^ img)
	{	
		for (int i = 0; i < cant; i++)
			arreglo[i]->dibujar(g, img);
	}
};