#pragma once

namespace gamejam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Creditos : public System::Windows::Forms::Form
	{
	public:
		Creditos(void)
		{
			InitializeComponent();
		}

	protected:
		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblNombres;
		System::Windows::Forms::Button^ btnVolver;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblNombres = gcnew System::Windows::Forms::Label();
			this->btnVolver = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.0F, System::Drawing::FontStyle::Bold);
			this->lblTitulo->Location = System::Drawing::Point(150, 30);
			this->lblTitulo->Size = System::Drawing::Size(250, 40);
			this->lblTitulo->Text = L"Créditos";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			// 
			// lblNombres
			// 
			this->lblNombres->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.0F);
			this->lblNombres->Location = System::Drawing::Point(100, 100);
			this->lblNombres->Size = System::Drawing::Size(350, 120);
			this->lblNombres->Text =
				L"Desarrollado por:\n\n"
				L"• Victor Hidalgo\n"
				L"• Cielo Atencio\n"
				L"• Sebastian Reyes";
			this->lblNombres->TextAlign = System::Drawing::ContentAlignment::TopCenter;

			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(220, 270);
			this->btnVolver->Size = System::Drawing::Size(100, 40);
			this->btnVolver->Text = L"Volver";
			this->btnVolver->Click += gcnew System::EventHandler(this, &Creditos::btnVolver_Click);

			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 350);
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblNombres);
			this->Controls->Add(this->btnVolver);
			this->Name = L"Creditos";
			this->Text = L"Créditos";
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close(); 
		}
	};
}
