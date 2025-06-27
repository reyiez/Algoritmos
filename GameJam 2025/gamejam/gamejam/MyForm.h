#include "Registro.h"
#include "Instrucciones.h"
#include "Creditos.h"
#include "Juego.h"
#include "Puntaje.h"
#pragma once
namespace gamejam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnIniciar;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnInstruccion;
	private: System::Windows::Forms::Button^ btnPuntaje;


	private: System::Windows::Forms::Button^ btnCreditos;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnInstruccion = (gcnew System::Windows::Forms::Button());
			this->btnPuntaje = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnIniciar
			// 
			this->btnIniciar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnIniciar.BackgroundImage")));
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(222, 216);
			this->btnIniciar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(114, 54);
			this->btnIniciar->TabIndex = 0;
			this->btnIniciar->Text = L"Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &MyForm::btnIniciar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS PGothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(264, 103);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 48);
			this->label1->TabIndex = 1;
			// 
			// btnInstruccion
			// 
			this->btnInstruccion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInstruccion.BackgroundImage")));
			this->btnInstruccion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstruccion->Location = System::Drawing::Point(437, 216);
			this->btnInstruccion->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnInstruccion->Name = L"btnInstruccion";
			this->btnInstruccion->Size = System::Drawing::Size(114, 54);
			this->btnInstruccion->TabIndex = 2;
			this->btnInstruccion->Text = L"Instrucciones";
			this->btnInstruccion->UseVisualStyleBackColor = true;
			this->btnInstruccion->Click += gcnew System::EventHandler(this, &MyForm::btnInstruccion_Click);
			// 
			// btnPuntaje
			// 
			this->btnPuntaje->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuntaje.BackgroundImage")));
			this->btnPuntaje->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPuntaje->Location = System::Drawing::Point(222, 335);
			this->btnPuntaje->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPuntaje->Name = L"btnPuntaje";
			this->btnPuntaje->Size = System::Drawing::Size(114, 54);
			this->btnPuntaje->TabIndex = 3;
			this->btnPuntaje->Text = L"Puntaje";
			this->btnPuntaje->UseVisualStyleBackColor = true;
			this->btnPuntaje->Click += gcnew System::EventHandler(this, &MyForm::btnPuntaje_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreditos.BackgroundImage")));
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->Location = System::Drawing::Point(437, 335);
			this->btnCreditos->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(114, 54);
			this->btnCreditos->TabIndex = 4;
			this->btnCreditos->Text = L"Creditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MyForm::btnCreditos_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(771, 486);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnPuntaje);
			this->Controls->Add(this->btnInstruccion);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnIniciar);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
	Registro^ registro = gcnew Registro();
	this->Visible = false; 
	registro->ShowDialog();
	this->Visible = true;
	
}
private: System::Void btnInstruccion_Click(System::Object^ sender, System::EventArgs^ e) {
	Instrucciones^ instrucciones = gcnew Instrucciones();
	this->Visible = false;
	instrucciones->ShowDialog();
	this->Visible = true;
}

private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	Creditos^ creditos = gcnew Creditos();
	this->Visible = false;
	creditos->ShowDialog();
	this->Visible = true;

}

private: System::Void btnPuntaje_Click(System::Object^ sender, System::EventArgs^ e) {
	Puntajes^ puntajes = gcnew Puntajes();
	this->Visible = false;
	puntajes->ShowDialog();
	this->Visible = true;
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

};
}
