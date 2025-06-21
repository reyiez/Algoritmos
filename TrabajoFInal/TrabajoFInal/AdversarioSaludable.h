#pragma once
#include"Entidad.h"
#include"BalaEemigo.h"
#include<vector>
class CAdvSaludable :public::Entidad
{
	BalasEnemigos* nuevo;
	int vida;
	int jX;
	int jY;
	int marcado;
public:

	CAdvSaludable() {
		
		srand(time(NULL));
		nuevo = new BalasEnemigos();
		x = rand() % 400;
		y = rand() % 400;
		ancho = 576 / 9;
		alto = 768 / 12;
		indiceX = 0;
		indiceY = 0;
		dy = 10;
		escala = 1.8;
		vida = 3;
		marcado = 0;
	}
	~CAdvSaludable() {}
	void setVida(int valor)
	{
		vida = valor;
	}

	void mover(Graphics^ g)
	{

		if (vida == 3) {
			if (y < 0 || y + alto + dy >= g->VisibleClipBounds.Height) dy *= -1;
			if (dy > 0) {
				indiceY = 2;
			}
			else
				indiceY = 0;
			y += dy;
			indiceX++;
			if (indiceX > 8)indiceX = 0;
		}
		else if (vida == 2) {
			if (y < 0 || y + alto + dy >= g->VisibleClipBounds.Height) dy *= -1;
			if (dy > 0) {
				indiceY = 6;
			}
			else
				indiceY = 4;
			y += dy;
			indiceX++;
			if (indiceX > 8)indiceX = 0;


		}
		else if (vida == 1) {

			if (y < 0 || y + alto + dy >= g->VisibleClipBounds.Height) dy *= -1;
			if (dy > 0) {
				indiceY = 10;
			}
			else
				indiceY = 8;
			y += dy;
			indiceX++;
			if (indiceX > 8)indiceX = 0;
		}
	}

	void disparar(int fx, int fy) {

		srand(time(NULL));
		if (rand() % 100 == 0);
		nuevo->Agregar(new balaEnemigo(this->x, this->y, fx, fy));
	}

	void moverBala() {
		nuevo->Mover();
	
	}

	void dibujarbala(Graphics ^g)
	{
		nuevo->Mostrar(g);
	}
	
	BalasEnemigos* getBalas() { return nuevo; }

	void dibujar(Graphics^ g, Bitmap^ img)
	{
		nuevo->Mostrar(g);
		g->DrawImage(img, Zoom(), AreaVisible(), GraphicsUnit::Pixel);
	}

	Rectangle areaBala() {
		return nuevo->areas();
	}

	void setmarcado(int v) { marcado = v; }

	int getmarcado() { return marcado; }


	int getVida() { return vida; }

};

class ADVSSaludables
{
	std::vector<CAdvSaludable*>advSaludabless;

public:

	void agregarEnemigo(CAdvSaludable* enemigos)
	{
		advSaludabless.push_back(enemigos);
	}

	void eliminarEnemigo(int pos)
	{
		advSaludabless.erase(advSaludabless.begin() + pos);
	}

	int getCantidad()
	{
		return advSaludabless.size();
	}

	CAdvSaludable* getADVSaludable(int i)
	{
		return advSaludabless[i];
	}

	void mover(Graphics^ g)
	{
		for each (CAdvSaludable * E in advSaludabless)
			E->mover(g);
	}

	void mostrar(Graphics^ g, Bitmap^ bmp)
	{
		for each (CAdvSaludable * E in advSaludabless)
			E->dibujar(g, bmp);
	}

	void cambiarColor(int color, int pos)
	{
		advSaludabless[pos]->setVida(color);
	}
	int getColor(int pos) {
		return advSaludabless[pos]->getVida();
	}
	int getMarcado(int pos) { return advSaludabless[pos]->getmarcado(); }

	void setMarcado(int pos, int v) { advSaludabless[pos]->setmarcado(v); }


};
