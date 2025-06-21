#pragma once
#include"Heroe.h"
#include"AdversarioAsintomatico.h"
#include"AdversarioSaludable.h"
#include"Ambulancia.h"
#include"Policia.h"
#include<time.h>

using namespace std;
#include<iostream>

class Controladora {

private:
	int nivel;
	CHeroe* jugador;
	ADVSSaludables* objSaludable;
	ADVSAintomaticos* objAsintomaticos;
	Policias* objPolicias;
	Ambulancias* objAmbulancias;
	int tiempo;
	clock_t start;
	int vida;

public:
	Controladora(int nivel, int tiempo, int vida)
	{

		start = clock();
		this->vida = vida;
		//tiempo=110;
		this->tiempo = tiempo;
		jugador = new CHeroe();
		objSaludable = new ADVSSaludables();
		objAsintomaticos = new ADVSAintomaticos();
		objPolicias = new Policias();
		objAmbulancias = new Ambulancias();
		jugador->SetVidas(vida);
		this->nivel = nivel;
		int cant = 3 * nivel;

		for (int i = 0; i < cant; i++)
		{
			srand(time(NULL));
			_sleep(300);
			CAdvSaludable* enemigosSaludable = new CAdvSaludable();
			enemigosSaludable->SetX(rand() % 900);
			enemigosSaludable->SetY(rand() % 600);
			objSaludable->agregarEnemigo(enemigosSaludable);


			CAdvAsintomatico* enemigoAsintomatico = new CAdvAsintomatico();
			enemigoAsintomatico->SetX(rand() % 900);
			enemigoAsintomatico->SetY(rand() % 600);
			objAsintomaticos->agregarEnemigo(enemigoAsintomatico);

		}


		for (int i = 0; i < 2; i++)
		{
			_sleep(300);
			CPolicia* policia = new CPolicia();
			policia->SetX(rand() % 1000);
			policia->SetY(rand() % 700);
			objPolicias->agregarPolicia(policia);

			CAmbulancia* ambulancia = new CAmbulancia();
			ambulancia->SetX(rand() % 1000);
			ambulancia->SetY(rand() % 700);
			objAmbulancias->agregarAmbulancia(ambulancia);
		}
	}
	~Controladora() {
		delete jugador;
	}
	
	void setTiempo(int valor)
	{
		tiempo = valor;
	}
	
	void setVidas(int n)
	{
		vida = n;
	}

	void disparar()
	{
		jugador->disparar();
	}

	void colisionAdvAsintomaticoBala()
	{
		CBalas* balas = jugador->getBalas();

		for (int i = 0; i < balas->getCantidad(); i++) {
			for (int j = 0; j < objAsintomaticos->getCantidad(); j++)
			{
				CBala* msj = balas->getBala(i);
				CAdvAsintomatico* enm = objAsintomaticos->getADVASintomatico(j);
				if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 0)
				{
					objAsintomaticos->cambiarColor(2, j);
					objAsintomaticos->setMarcado(j, 1);

					balas->eliminarBala(i--);
					break;
				}
				else if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 1)
				{
					objAsintomaticos->cambiarColor(1, j);
					objAsintomaticos->setMarcado(j, 2);
					balas->eliminarBala(i--);
					break;
				}
				else if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 2)
				{
					objAsintomaticos->EliminarEnemigo(j--);
					balas->eliminarBala(i--);
					break;


				}

			}
		}
	}

	void colisionAdvSaludableBala()
	{
		CBalas* balas = jugador->getBalas();

		for (int i = 0; i < balas->getCantidad(); i++) {
			for (int j = 0; j < objSaludable->getCantidad(); j++)
			{
				CBala* msj = balas->getBala(i);
				CAdvSaludable* enm = objSaludable->getADVSaludable(j);
				if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 0)
				{
					objSaludable->cambiarColor(2, j);
					objSaludable->setMarcado(j, 1);
					balas->eliminarBala(i--);
					break;
				}
				else if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 1)
				{
					objSaludable->cambiarColor(1, j);
					objSaludable->setMarcado(j, 2);
					balas->eliminarBala(i--);
					break;
				}
				else if (msj->Zoom().IntersectsWith(enm->Zoom()) && enm->getmarcado() == 2)
				{
					objSaludable->eliminarEnemigo(j--);
					balas->eliminarBala(i--);
					break;
				}

			}

		}
	}

	void agregarAsintomatico()
	{
		objAsintomaticos->agregarEnemigo(new CAdvAsintomatico());

	}

	void agregarSaludable()
	{
		objSaludable->agregarEnemigo(new CAdvSaludable());

	}

	void acelerarEnemigos()

	{
		for (int i = 0; i < objAsintomaticos->getCantidad(); i++)
		{
			CAdvAsintomatico* enm = objAsintomaticos->getADVASintomatico(i);
			enm->SetDX(20);
			break;
		}

		for (int j = 0; j < objSaludable->getCantidad(); j++)
		{
			CAdvSaludable* enm = objSaludable->getADVSaludable(j);
			enm->SetDY(20);
			break;
		}

	}


	void mover(Graphics^ g) {
		jugador->mover(g);
		objSaludable->mover(g);
		objAsintomaticos->mover(g);
		objPolicias->mover(g);
		objAmbulancias->mover(g);

		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			tiempo--;
			start = clock();
		}

	}

	void mover2(Graphics^ g) {
		acelerarEnemigos();
		for (int i = 0; i < objAsintomaticos->getCantidad(); i++)
		{
			CAdvAsintomatico* enm = objAsintomaticos->getADVASintomatico(i);

			if (jugador->Zoom().IntersectsWith(enm->Zoom()))
			{
				jugador->SetVidas(jugador->getVidas() - 1);
				break;
			}
		}

		for (int i = 0; i < objSaludable->getCantidad(); i++)
		{
			CAdvSaludable* enm = objSaludable->getADVSaludable(i);

			if (jugador->Zoom().IntersectsWith(enm->Zoom()))
			{

				jugador->SetVidas(jugador->getVidas() - 1);
				break;
			}
		}

		jugador->mover(g);
		objSaludable->mover(g);
		objAsintomaticos->mover(g);
		objPolicias->mover(g);
		objAmbulancias->mover(g);

		if (clock() - start >= (double)CLOCKS_PER_SEC)
		{
			tiempo--;
			start = clock();
		}
	}


	void dibujar(Graphics^ g, Bitmap^ bmpheroe, Bitmap^ AdvAsintomatico, Bitmap^ AdvSaludable,
		Bitmap^ bmpPolicia, Bitmap^ bmpAmbulancia, Bitmap^ bmpbala)
	{

		g->DrawString(jugador->getVidas().ToString(), gcnew Font("Arial", 20), Brushes::White, 1200, 20);

		g->DrawString(tiempo.ToString(), gcnew Font("Arial", 20), Brushes::White, 85, 20);

		jugador->dibujar(g, bmpheroe);
		jugador->mostrarMensaje(g, bmpbala);
		objSaludable->mostrar(g, AdvSaludable);
		objAsintomaticos->Mostrar(g, AdvAsintomatico);
		objPolicias->mostrar(g, bmpPolicia);
		objAmbulancias->mostrar(g, bmpAmbulancia);
	}

	void disparoBalaEnemiga(Graphics^ g) {

		for (int i = 0; i < objSaludable->getCantidad(); i++)
		{
			CAdvSaludable* enm = objSaludable->getADVSaludable(i);

			enm->moverBala();
			enm->dibujarbala(g);

			enm->disparar(jugador->GetX(), jugador->GetY());
		}
	}
	void colisionBalaEnemigaHeroe() {
	

		for (int i = 0; i < objSaludable->getCantidad(); i++)
		{
			CAdvSaludable* enm = objSaludable->getADVSaludable(i);
			if (jugador->Zoom().IntersectsWith(enm->areaBala()))
				jugador->SetVidas(jugador->getVidas() - 1);
			break;

		}
	}
	
	CHeroe* getJugador() { return jugador; }

	int getVidas() { return jugador->getVidas(); }
	int cantADVSaludable() { return objSaludable->getCantidad(); }
	int cantADVAsintiomatico() { return objAsintomaticos->getCantidad(); }
	int cantTotal() { return cantADVAsintiomatico() + cantADVSaludable(); }
	int getTiempo() { return tiempo; }

};