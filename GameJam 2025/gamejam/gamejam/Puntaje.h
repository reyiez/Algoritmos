#pragma once
#include "DatosJugador.h"

namespace gamejam {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class Puntajes : public System::Windows::Forms::Form
	{
	public:
		Puntajes()
		{
			InitializeComponent();

			// Mostrar historial de jugadores con puntajes
			int y = 60;
			for (int i = 0; i < DatosJugador::nombres->Count; i++) {
				System::Windows::Forms::Label^ lbl = gcnew System::Windows::Forms::Label();
				lbl->AutoSize = true;
				lbl->Font = gcnew System::Drawing::Font("Arial", 12);
				lbl->Location = System::Drawing::Point(30, y);
				lbl->Text = "Jugador: " + DatosJugador::nombres[i] + " - Puntaje: " + DatosJugador::puntajes[i].ToString();
				this->Controls->Add(lbl);
				y += 30;
			}
		}

	private:
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Button^ btnCerrar;

		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblTitulo->Location = System::Drawing::Point(22, 16);
			this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(222, 26);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Historial de Puntajes";
			// 
			// btnCerrar
			// 
			this->btnCerrar->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->btnCerrar->Location = System::Drawing::Point(278, 260);
			this->btnCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(75, 24);
			this->btnCerrar->TabIndex = 1;
			this->btnCerrar->Text = L"Cerrar";
			this->btnCerrar->UseVisualStyleBackColor = true;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Puntajes::btnCerrar_Click);
			// 
			// Puntajes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 325);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->btnCerrar);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Puntajes";
			this->Text = L"Puntajes";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
