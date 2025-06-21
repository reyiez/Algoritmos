#pragma once
#include"Entidad.h"
#include<vector>
class CAdvAsintomatico :public::Entidad
{

	int marcado;
	int vida ;
public:

	CAdvAsintomatico()
	{
		srand(time(NULL));
		x = rand() % 500;
		y = rand() % 500;
		indiceX = indiceY = 0;
		alto = 579 / 12;
		ancho = 138 / 3;
		escala = 2.0;
		dx = 10;
		vida= 3;
		marcado = 0;
	}
	void setVida(int valor) { vida = valor; }

	void Mover(Graphics^ g)
	{

		if (vida== 3)
		{
			if (x < 0 || x + ancho > g->VisibleClipBounds.Width) dx *= -1;
			if (dx > 0) {
				indiceY = 1; 
			}
			else
				indiceY = 3;
			x += dx;
			indiceX++;
			if (indiceX > 2)indiceX = 0;
		}
		else if (vida== 2)
		{
			if (x < 0 || x + ancho > g->VisibleClipBounds.Width) dx *= -1;
			if (dx > 0) {
				indiceY = 5;
			}
			else
				indiceY = 7;
			x += dx;
			indiceX++;
			if (indiceX > 2)indiceX = 0;

		}
		else if (vida== 1)
		{
			if (x < 0 || x + ancho > g->VisibleClipBounds.Width) dx *= -1;
			if (dx > 0) {
				indiceY = 9;
			}
			else
				indiceY = 11;
			x += dx;
			indiceX++;
			if (indiceX > 2)indiceX = 0;
		}
	
	
	}

	void setmarcado(int v) { marcado = v; }

	int getmarcado() { return marcado; }

	int getVida() { return vida; }

	void dibujar(Graphics^ g, Bitmap^ bmp)
	{

		g->DrawImage(bmp, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
	}
	
};
class ADVSAintomaticos
	{
		std::vector<CAdvAsintomatico*>advAsintomaticoss;
	
	public:
		
		void agregarEnemigo(CAdvAsintomatico* enemigos)
		{
			advAsintomaticoss.push_back(enemigos);
		}
		
		void EliminarEnemigo(int pos)
		{
			advAsintomaticoss.erase(advAsintomaticoss.begin() + pos);
		}

		int getCantidad() 
		{
			return advAsintomaticoss.size();
		}

		CAdvAsintomatico* getADVASintomatico(int i)
		{
			return advAsintomaticoss[i];
		}

		void mover(Graphics^ g)
		{
			for each (CAdvAsintomatico * E in advAsintomaticoss)
				E->Mover(g);
		}

		void Mostrar(Graphics^ g, Bitmap^ bmp)
		{
			for each (CAdvAsintomatico * E in advAsintomaticoss)
				E->dibujar(g, bmp);
		}

		void cambiarColor(int color, int pos)
		{
			advAsintomaticoss[pos]->setVida(color);
		}
		int getColor(int pos) {
			return advAsintomaticoss[pos]->getVida();
		}
		int getMarcado(int pos) { return advAsintomaticoss[pos]->getmarcado(); }

		void setMarcado(int pos, int v) { advAsintomaticoss[pos]->setmarcado(v); }
		

	};
