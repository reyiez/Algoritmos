#pragma once
enum Direccion {Arriba,Abajo ,Izquierda,Derecha,Ninguno};
using namespace System::Drawing;
class CLlama {

public:
	CLlama(int x, int y) {
		ancho = 288 / 6;
		largo = 384 / 8;
		this->x = x;
		this->y = y;
		indiceX = 0; indiceY = 0;
		color = 1;
		dx = 0;
		dy = 0;
		direccion = Direccion::Ninguno;
		ultima = Direccion::Abajo;
	}

	void dibujar(Graphics^ g, Bitmap^ bmp)

	{

		Rectangle areaAUsar = Rectangle(ancho * indiceX, largo * indiceY, ancho, largo);
		Rectangle aumentar = Rectangle(x, y, ancho, largo);
		g->DrawImage(bmp, aumentar, areaAUsar, GraphicsUnit::Pixel);
		x += dx;
		y += dy;


	}



	void color1() {
		switch (direccion)
		{
		case Direccion::Arriba:
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 0;
			dy = -10;
			ultima = Arriba;
			break;

		case Direccion::Abajo:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 0;
			dy = +10;
			ultima = Abajo;
			break;

		case Direccion::Izquierda:
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Izquierda;
			break;
		case Direccion::Derecha:
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = +10;
			dy = 0;
			ultima = Derecha;

			break;
		case Direccion::Ninguno:
			dx = dy = 0;
			if (ultima == Direccion::Abajo) {
				indiceX = 0;
				indiceY = 0;
			}
			if (ultima == Direccion::Arriba) {
				indiceX = 0;
				indiceY = 3;
			}
			if (ultima == Direccion::Derecha) {
				indiceX = 0;
				indiceY = 2;
			}
			if (ultima == Direccion::Izquierda) {
				indiceX = 0;
				indiceY = 1;
			}
			break;
		default:
			break;
		}

	}
	void color2() {
		switch (direccion)
		{
		case Direccion::Arriba:
			indiceY = 7;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 0;
			dy = -10;
			ultima = Arriba;
			break;

		case Direccion::Abajo:
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = 0;
			dy = +10;
			ultima = Abajo;
			break;

		case Direccion::Izquierda:
			indiceY = 5;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = -10;
			dy = 0;
			ultima = Izquierda;
			break;
		case Direccion::Derecha:
			indiceY = 6;
			if (indiceX >= 0 && indiceX < 2)
				indiceX++;
			else
				indiceX = 1;
			dx = +10;
			dy = 0;
			ultima = Derecha;

			break;
		case Direccion::Ninguno:
			dx = dy = 0;
			if (ultima == Direccion::Abajo) {
				indiceX = 0;
				indiceY = 4;
			}
			if (ultima == Direccion::Arriba) {
				indiceX = 0;
				indiceY = 7;
			}
			if (ultima == Direccion::Derecha) {
				indiceX = 0;
				indiceY = 6;
			}
			if (ultima == Direccion::Izquierda) {
				indiceX = 0;
				indiceY = 5;
			}
			break;
		default:
			break;
		}
	}
	void color3() {
		switch (direccion)
		{
		case Direccion::Arriba:
			indiceY = 7;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = 0;
			dy = -10;
			ultima = Arriba;
			break;

		case Direccion::Abajo:
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = 0;
			dy = +10;
			ultima = Abajo;
			break;

		case Direccion::Izquierda:
			indiceY = 5;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = -10;
			dy = 0;
			ultima = Izquierda;
			break;
		case Direccion::Derecha:
			indiceY = 6;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = +10;
			dy = 0;
			ultima = Derecha;

			break;
		case Direccion::Ninguno:
			dx = dy = 0;
			if (ultima == Direccion::Abajo) {
				indiceX = 3;
				indiceY = 4;
			}
			if (ultima == Direccion::Arriba) {
				indiceX = 3;
				indiceY = 7;
			}
			if (ultima == Direccion::Derecha) {
				indiceX = 3;
				indiceY = 6;
			}
			if (ultima == Direccion::Izquierda) {
				indiceX = 3;
				indiceY = 5;
			}
			break;
		default:
			break;
		}
	}
	void color4() {
		switch (direccion)
		{
		case Direccion::Arriba:
			indiceY = 3;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = 0;
			dy = -10;
			ultima = Arriba;
			break;

		case Direccion::Abajo:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = 0;
			dy = +10;
			ultima = Abajo;
			break;

		case Direccion::Izquierda:
			indiceY = 1;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = -10;
			dy = 0;
			ultima = Izquierda;
			break;
		case Direccion::Derecha:
			indiceY = 2;
			if (indiceX >= 3 && indiceX < 5)
				indiceX++;
			else
				indiceX = 3;
			dx = +10;
			dy = 0;
			ultima = Derecha;

			break;
		case Direccion::Ninguno:
			dx = dy = 0;
			if (ultima == Direccion::Abajo) {
				indiceX = 3;
				indiceY = 0;
			}
			if (ultima == Direccion::Arriba) {
				indiceX = 3;
				indiceY = 3;
			}
			if (ultima == Direccion::Derecha) {
				indiceX = 3;
				indiceY = 2;
			}
			if (ultima == Direccion::Izquierda) {
				indiceX = 3;
				indiceY = 1;
			}
			break;
		default:
			break;
		}
	}

	void mover() {
		switch (color)
		{
		case 1:color1(); break;
		case 2:color2(); break;
		case 3:color3(); break;
		case 4:color4(); break;
		default:

			if (color == 1) {
				dx = dy = 0;
				if (ultima == Direccion::Abajo) {
					indiceX = 0;
					indiceY = 0;
				}
				if (ultima == Direccion::Arriba) {
					indiceX = 0;
					indiceY = 3;
				}
				if (ultima == Direccion::Derecha) {
					indiceX = 0;
					indiceY = 2;
				}
				if (ultima == Direccion::Izquierda) {
					indiceX = 0;
					indiceY = 1;
				}
			}
			if (color == 2) {

				if (ultima == Direccion::Abajo) {
					indiceX = 0;
					indiceY = 4;
				}
				if (ultima == Direccion::Arriba) {
					indiceX = 0;
					indiceY = 7;
				}
				if (ultima == Direccion::Derecha) {
					indiceX = 0;
					indiceY = 6;
				}
				if (ultima == Direccion::Izquierda) {
					indiceX = 0;
					indiceY = 5;
				}

			}
			if (color == 3) {
				if (ultima == Direccion::Abajo) {
					indiceX = 3;
					indiceY = 4;
				}
				if (ultima == Direccion::Arriba) {
					indiceX = 3;
					indiceY = 7;
				}
				if (ultima == Direccion::Derecha) {
					indiceX = 3;
					indiceY = 6;
				}
				if (ultima == Direccion::Izquierda) {
					indiceX = 3;
					indiceY = 5;
				}

			}
			if (color == 4) {
				dx = dy = 0;
				if (ultima == Direccion::Abajo) {
					indiceX = 3;
					indiceY = 0;
				}
				if (ultima == Direccion::Arriba) {
					indiceX = 3;
					indiceY = 3;
				}
				if (ultima == Direccion::Derecha) {
					indiceX = 3;
					indiceY = 2;
				}
				if (ultima == Direccion::Izquierda) {
					indiceX = 3;
					indiceY = 1;
				}

			}
			break;
		}

	}
	void setColor(int color1) { color = color1; }
	void setDireccion(Direccion dire) { direccion = dire; }
	void setImdiceX(int indiX) { indiceX = indiX; }
	void setIndiceY(int indiY) { indiceY = indiY; }
	int getColor() { return color; }
	int getIndiceX() { return indiceX; }
	int getIndiceY() { return indiceY; }
	void setdY(int ddy) { dy = ddy; }
	void setdX(int ddx) { dx = ddx; }
private:
	int x,y;
	int dx, dy;
	int ancho, largo;
	int indiceX, indiceY;
	int color;
	Direccion direccion;
	Direccion ultima;
	bool v1, v2, v3, v4;
};