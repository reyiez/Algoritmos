#pragma once
#include "Figura.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "DatosJugador.h"

namespace gamejam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Juego : public System::Windows::Forms::Form {
	public:
		Juego(void) {
			InitializeComponent();
			this->DoubleBuffered = true;

			figuras = gcnew List<Figura^>();
			timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 300;
			timer->Tick += gcnew EventHandler(this, &Juego::timer_Tick);
			timer->Start();

			agregarFiguraAleatoria();
			startCayendo = false;
			DatosJugador::puntaje = 0;
		}

	protected:
		~Juego() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Timer^ timer;
		List<Figura^>^ figuras;
		Figura^ figuraActual;
		bool startCayendo;
		bool puedeMoverAbajo = true;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 553);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Juego::Juego_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Juego::Juego_FormClosed);
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {}

	private: void agregarFiguraAleatoria() {
		Random^ rnd = gcnew Random();
		int tipo = rnd->Next(3);
		int x = 300;
		int y = 120;
		int valor = rnd->Next(10);
		array<Color>^ colores = gcnew array<Color>{ Color::Red, Color::Blue, Color::Yellow };
		Color color = colores[rnd->Next(colores->Length)];

		if (tipo == 0)
			figuraActual = gcnew Circulo(x, y, valor, color);
		else if (tipo == 1)
			figuraActual = gcnew Cuadrado(x, y, valor, color);
		else
			figuraActual = gcnew Triangulo(x, y, valor, color);
	}

	private: System::Void Juego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		for each (Figura ^ f in figuras)
			f->Dibujar(e->Graphics);

		if (figuraActual != nullptr)
			figuraActual->Dibujar(e->Graphics);

		e->Graphics->DrawString("Puntaje: " + DatosJugador::puntaje.ToString(),
			gcnew System::Drawing::Font("Arial", 14),
			Brushes::Black, 10, 10);

		e->Graphics->DrawString("Jugador: " + DatosJugador::nombrejugador,
			gcnew System::Drawing::Font("Arial", 14),
			Brushes::Black, 10, 40);

		int limiteY = 170;
		Pen^ penLimite = gcnew Pen(Color::Black, 3);
		e->Graphics->DrawLine(penLimite, 0, limiteY, this->ClientSize.Width, limiteY);

		int limiteBase = 400;
		Pen^ penBase = gcnew Pen(Color::Black, 3);
		e->Graphics->DrawLine(penBase, 0, limiteBase, this->ClientSize.Width, limiteBase);
	}

	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (figuraActual == nullptr) return;

		switch (e->KeyCode) {
		case Keys::Left:
			figuraActual->mover(-20, 0);
			break;
		case Keys::Right:
			figuraActual->mover(20, 0);
			break;
		case Keys::Down:
			if (!startCayendo && figuraActual->getY() + figuraActual->getAlto() < this->ClientSize.Height)
				startCayendo = true;
			break;
		case Keys::Escape:
			this->Close();
			break;
		}
		Refresh();
	}

	private: int contarFigurasApiladas(int xRef) {
		int conteo = 0;
		for each (Figura ^ f in figuras) {
			if (Math::Abs(f->getX() - xRef) <= 10)
				conteo++;
		}
		return conteo;
	}

	private: void mostrarMensajeFinal(String^ mensaje, String^ titulo) {
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			mensaje + "\n¿Deseas jugar otra vez?", titulo,
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			figuras->Clear();
			agregarFiguraAleatoria();
			DatosJugador::puntaje = 0;
			startCayendo = false;
			timer->Start();
		}
		else {
			this->Close();
		}
	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (figuraActual == nullptr || !startCayendo)
			return;

		bool colision = false;
		int limiteY = 400;

		for each (Figura ^ f in figuras) {
			if (figuraActual->colisionaCon(f)) {
				colision = true;

				if (figuraActual->GetType() == f->GetType() && figuraActual->getColor() == f->getColor()) {
					f->setValor(f->getValor() + figuraActual->getValor());
					DatosJugador::puntaje += f->getValor() * 10;
					f->setTamano(f->getAncho() + 10, f->getAlto() + 10);
				}
				else {
					figuras->Add(figuraActual);
				}

				figuraActual = nullptr;
				agregarFiguraAleatoria();
				startCayendo = false;
				break;
			}
		}

		if (!colision) {
			if (figuraActual->getY() + figuraActual->getAlto() < limiteY) {
				figuraActual->mover(0, 10);
			}
			else {
				figuraActual->mover(0, limiteY - (figuraActual->getY() + figuraActual->getAlto()));
				figuras->Add(figuraActual);
				figuraActual = nullptr;
				agregarFiguraAleatoria();
				startCayendo = false;
			}
		}

		Refresh();

		if (DatosJugador::puntaje >= 500) {
			timer->Stop();
			mostrarMensajeFinal("¡Felicidades! Alcanzaste 500 puntos. ¡Ganaste!", "Ganaste");
			return;
		}

		for each (Figura ^ f in figuras) {
			int cantidad = contarFigurasApiladas(f->getX());
			if (cantidad >= 5) {
				timer->Stop();
				mostrarMensajeFinal("¡Perdiste! Se apilaron 5 figuras.\nTu puntaje fue: " + DatosJugador::puntaje.ToString(), "Derrota");
				return;
			}
		}
	}

	private: System::Void Juego_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		DatosJugador::nombres->Add(DatosJugador::nombrejugador);
		DatosJugador::puntajes->Add(DatosJugador::puntaje);
	}
	};
}
