#pragma once
#include"llama.h"
namespace llama {

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
	private:
		CLlama* nuevaLLama;
	    Bitmap^ bmp = gcnew Bitmap("caballo.png");
	private: System::Windows::Forms::Timer^ timer1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			nuevaLLama = new CLlama(30, 30);
			bmp->MakeTransparent(bmp->GetPixel(0, 0));
		
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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(658, 461);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		g->Clear(SystemColors::Control);
		nuevaLLama->dibujar(g, bmp);
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		
		
		switch (e->KeyCode)
		{

		case Keys::Down:
			if (nuevaLLama->getColor() == 1) { nuevaLLama->setIndiceY(0); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0);}
			if (nuevaLLama->getColor() == 2) { nuevaLLama->setIndiceY(4); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0);}
			if (nuevaLLama->getColor() == 3) { nuevaLLama->setIndiceY(4); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0);}
			if (nuevaLLama->getColor() == 4) { nuevaLLama->setIndiceY(0); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0);}
			break;
		case Keys::Up:
			if (nuevaLLama->getColor() == 1) { nuevaLLama->setIndiceY(3); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0);
			}
			if (nuevaLLama->getColor() == 2) { nuevaLLama->setIndiceY(7); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 3) { nuevaLLama->setIndiceY(7); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 4) { nuevaLLama->setIndiceY(3); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			
			
			break;

		case Keys::Left:
			if (nuevaLLama->getColor() == 1) { nuevaLLama->setIndiceY(1); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0);
			}
			if (nuevaLLama->getColor() == 2) { nuevaLLama->setIndiceY(5); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 3) { nuevaLLama->setIndiceY(5); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 4) { nuevaLLama->setIndiceY(1); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }


			break;
		case Keys::Right:
			if (nuevaLLama->getColor() == 1) { nuevaLLama->setIndiceY(2); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0);
			}
			if (nuevaLLama->getColor() == 2) { nuevaLLama->setIndiceY(6); nuevaLLama->setImdiceX(0); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 3) { nuevaLLama->setIndiceY(6); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			if (nuevaLLama->getColor() == 4) { nuevaLLama->setIndiceY(2); nuevaLLama->setImdiceX(3); nuevaLLama->setdX(0); nuevaLLama->setdY(0); }
			break;

			
		default:
			nuevaLLama->setDireccion(Direccion::Ninguno);
			break;
		}


	}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	nuevaLLama->mover();
	switch (e->KeyCode)
	{

	case Keys::Up:
	
		nuevaLLama->setDireccion(Arriba);
		
		break;
	case Keys::Down:
		nuevaLLama->setDireccion(Abajo);
		
		break;
	case Keys::Left:
		nuevaLLama->setDireccion(Izquierda);
		
		break;
	case Keys::Right:
		nuevaLLama->setDireccion(Derecha);
		
		break;

	case Keys::B:
		nuevaLLama->setColor(1);
		break;

	case Keys::V:
		nuevaLLama->setColor(2);
		break;

	case Keys::Z:
		nuevaLLama->setColor(3);
		break;

	case Keys::A:
		nuevaLLama->setColor(4);
		break;
	default:
		break;
	}
}
};
}
