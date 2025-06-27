#pragma once

namespace gamejam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Instrucciones : public System::Windows::Forms::Form
	{
	public:
		Instrucciones(void)
		{
			InitializeComponent();
		}

	protected:
		~Instrucciones()
		{
			if (components)
				delete components;
		}

	private:
		System::Windows::Forms::Label^ lblInstrucciones;
		System::Windows::Forms::Button^ btnCerrar;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblInstrucciones->Location = System::Drawing::Point(15, 16);
			this->lblInstrucciones->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(270, 146);
			this->lblInstrucciones->TabIndex = 0;
			this->lblInstrucciones->Text = L"Instrucciones del Juego :\n\n1. Usa las flechas <- y -> \n2. Une las formas iguales "
				L"para pasar\n3. Si se llega al tope pierdes.\n\nBuena suerte";
			this->lblInstrucciones->Click += gcnew System::EventHandler(this, &Instrucciones::lblInstrucciones_Click);
			// 
			// btnCerrar
			// 
			this->btnCerrar->Location = System::Drawing::Point(105, 171);
			this->btnCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(75, 28);
			this->btnCerrar->TabIndex = 1;
			this->btnCerrar->Text = L"Volver";
			this->btnCerrar->Click += gcnew System::EventHandler(this, &Instrucciones::btnCerrar_Click);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 219);
			this->Controls->Add(this->lblInstrucciones);
			this->Controls->Add(this->btnCerrar);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close(); 
		}
	private: System::Void lblInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
