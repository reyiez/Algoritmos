#pragma once
#include "Juego.h"
#include "DatosJugador.h" // Agrega esto al inicio

namespace gamejam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Registro : public System::Windows::Forms::Form
	{
	public:
		Registro(void)
		{
			InitializeComponent();
		}

	protected:
		~Registro()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ txtUsuario;
		System::Windows::Forms::Button^ btnPlay;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(126, 68);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese su usuario:";
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(120, 126);
			this->txtUsuario->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(188, 20);
			this->txtUsuario->TabIndex = 1;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(156, 176);
			this->btnPlay->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(98, 32);
			this->btnPlay->TabIndex = 2;
			this->btnPlay->Text = L"Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &Registro::btnPlay_Click);
			// 
			// Registro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 264);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Registro";
			this->Text = L"Registro de Usuario";
			this->Load += gcnew System::EventHandler(this, &Registro::Registro_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ nombre = txtUsuario->Text->Trim();
			if (!String::IsNullOrEmpty(nombre)) {
				DatosJugador::nombrejugador = nombre;
				this->Close(); // cierra el formulario de registro
			}
			else {
				MessageBox::Show("Por favor, ingresa tu nombre");
			}

			Juego^ juego = gcnew Juego();
			this->Visible = false;
			juego->ShowDialog();
			this->Visible = true;
			
			txtUsuario->Clear(); // Limpiar el campo de texto para un nuevo registro
		
		}
	
	private: System::Void Registro_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
