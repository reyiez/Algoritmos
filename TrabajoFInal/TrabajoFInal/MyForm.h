#pragma once
#include"Control.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
enum Pantalla {Menu1,nivelUno , nivelDos, Ganaste , Perdiste, Instrucciones1 };
namespace TrabajoFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		SoundPlayer^ musicaDisparo;
		Bitmap^ tiempoimg = gcnew Bitmap("tiempo.png");
		Bitmap^ corazon = gcnew Bitmap("corazon.jpg");
		Bitmap^ bmpHeroe = gcnew Bitmap("heroe.png");
		Bitmap^ bmpAdversarioAsintomatico = gcnew Bitmap("aAsintomatico.png");
		Bitmap^ bmpAdvSaludable = gcnew Bitmap("adversarioSaludable.png");
		Bitmap^ bmpPolicia = gcnew Bitmap("policia.png");
		Bitmap^ bmpAmbulancia = gcnew Bitmap("ambulancia.png");
		Bitmap^ bmpBala = gcnew Bitmap("balas.png");
		Bitmap^ bmpMundo = gcnew Bitmap("mundo.png");
		Bitmap^ bmpMundoDos = gcnew Bitmap("mundodos.jpg");
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Controladora* objControl;
		int nivel;
		int tiempo;
		int vida;


	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::Panel^ Instrucciones;

	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Timer^ timer2;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ pictureBox12;



	private: System::Windows::Forms::Panel^ panel1;

	public:
		MyForm(void)
		{


			InitializeComponent();
			nivel = 1;
			corazon->MakeTransparent(corazon->GetPixel(0, 0));
			tiempoimg->MakeTransparent(tiempoimg->GetPixel(0, 0));
			bmpAmbulancia->MakeTransparent(bmpAmbulancia->GetPixel(0, 0));
			bmpPolicia->MakeTransparent(bmpPolicia->GetPixel(0, 0));
			musicaDisparo = gcnew SoundPlayer("Plopplop.wav");
			MostrarPantalla(Menu1);

		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Instrucciones = (gcnew System::Windows::Forms::Panel());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->panelMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->Instrucciones->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1322, 192);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(18, 26);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(1325, 244);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(24, 27);
			this->panel2->TabIndex = 1;
			// 
			// panelMenu
			// 
			this->panelMenu->Controls->Add(this->comboBox1);
			this->panelMenu->Controls->Add(this->pictureBox7);
			this->panelMenu->Controls->Add(this->pictureBox6);
			this->panelMenu->Controls->Add(this->textBox2);
			this->panelMenu->Controls->Add(this->textBox1);
			this->panelMenu->Controls->Add(this->pictureBox5);
			this->panelMenu->Controls->Add(this->pictureBox4);
			this->panelMenu->Controls->Add(this->pictureBox3);
			this->panelMenu->Controls->Add(this->pictureBox2);
			this->panelMenu->Controls->Add(this->pictureBox1);
			this->panelMenu->Location = System::Drawing::Point(1325, 147);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(22, 27);
			this->panelMenu->TabIndex = 2;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Principiante", L"Avanzado" });
			this->comboBox1->Location = System::Drawing::Point(508, 291);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(161, 37);
			this->comboBox1->TabIndex = 13;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(689, 433);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(325, 50);
			this->pictureBox7->TabIndex = 12;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &MyForm::pictureBox7_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(730, 302);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(231, 103);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 11;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(508, 445);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(85, 25);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(508, 372);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(85, 28);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(363, 433);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(120, 50);
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(338, 360);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(145, 50);
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(287, 291);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(196, 50);
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(287, 36);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(674, 227);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1351, 798);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Instrucciones
			// 
			this->Instrucciones->Controls->Add(this->pictureBox10);
			this->Instrucciones->Controls->Add(this->pictureBox9);
			this->Instrucciones->Controls->Add(this->textBox3);
			this->Instrucciones->Controls->Add(this->pictureBox8);
			this->Instrucciones->Location = System::Drawing::Point(1322, 299);
			this->Instrucciones->Name = L"Instrucciones";
			this->Instrucciones->Size = System::Drawing::Size(23, 23);
			this->Instrucciones->TabIndex = 3;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.BackgroundImage")));
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(747, 644);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(166, 50);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 3;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.BackgroundImage")));
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(77, 35);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(569, 133);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 2;
			this->pictureBox9->TabStop = false;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(105, 277);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(541, 417);
			this->textBox3->TabIndex = 1;
			this->textBox3->Text = resources->GetString(L"textBox3.Text");
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(3, 0);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(1318, 782);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 0;
			this->pictureBox8->TabStop = false;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->pictureBox11);
			this->panel3->Location = System::Drawing::Point(1327, 380);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(20, 28);
			this->panel3->TabIndex = 4;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(3, 3);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(1298, 717);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox11->TabIndex = 0;
			this->pictureBox11->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox12);
			this->panel4->Location = System::Drawing::Point(1330, 427);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(25, 28);
			this->panel4->TabIndex = 5;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(0, 0);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(1313, 730);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox12->TabIndex = 0;
			this->pictureBox12->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1318, 738);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->Instrucciones);
			this->Controls->Add(this->panelMenu);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panelMenu->ResumeLayout(false);
			this->panelMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->Instrucciones->ResumeLayout(false);
			this->Instrucciones->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion





		void MostrarPantalla(Pantalla pantalla)
		{

			panel2->Visible = false;
			panelMenu->Visible = false;
			Instrucciones->Visible = false;
			panel3->Visible = false;
			panel4->Visible = false;


			panel3->Dock = System::Windows::Forms::DockStyle::None;
			panel4->Dock = System::Windows::Forms::DockStyle::None;
			panel2->Dock = System::Windows::Forms::DockStyle::None;
			Instrucciones->Dock = System::Windows::Forms::DockStyle::None;
			panelMenu->Dock = System::Windows::Forms::DockStyle::None;


			if (pantalla == Menu1) {
				panelMenu->Visible = true;
				panelMenu->Dock = System::Windows::Forms::DockStyle::Fill;
				panelMenu->Focus();
			}
			else if (pantalla == nivelUno) {

				if (this->Focused == false)
					this->Focus();
			}
			else if (pantalla == nivelDos)
			{
				panel2->Visible = true;
				panel2->Dock = System::Windows::Forms::DockStyle::Fill;
				panel2->Focus();
			}
			else if (pantalla == Instrucciones1)
			{
				Instrucciones->Visible = true;
				Instrucciones->Dock = System::Windows::Forms::DockStyle::Fill;
				Instrucciones->Focus();

			}
			else if (pantalla == Ganaste)
			{
				panel3->Visible = true;
				panel3->Dock = System::Windows::Forms::DockStyle::Fill;
				panel3->Focus();
			}
			else if (pantalla == Perdiste) {

				panel4->Visible = true;
				panel4->Dock = System::Windows::Forms::DockStyle::Fill;
				panel4->Focus();

			}
		}

		void guardar()
		{

			ofstream file("save.txt");
			file << objControl->getJugador()->GetX() << "  " << objControl->getJugador()->GetY() << endl;
			file << objControl->getVidas();
			file << objControl->getTiempo();
			
		file.close();
		}

		void abrir()
		{
			ifstream file("save.txt");
			int a, b, vida, time;

			file >> a >> b;
	

				file.close();
		}



	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		g = this->CreateGraphics();

		space = BufferedGraphicsManager::Current;
		buffer = space->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(bmpMundo, 0, 0, bmpMundo->Width, bmpMundo->Height);
		buffer->Graphics->DrawImage(corazon, 1150, 10, tiempoimg->Width / 15, tiempoimg->Height / 15);
		buffer->Graphics->DrawImage(tiempoimg, 0, 0, tiempoimg->Width / 10, tiempoimg->Height / 10);
		objControl->getJugador()->SetVidas(vida);
		objControl->dibujar(buffer->Graphics, bmpHeroe, bmpAdversarioAsintomatico, bmpAdvSaludable, bmpPolicia, bmpAmbulancia, bmpBala);
		objControl->mover(buffer->Graphics);
		objControl->colisionAdvAsintomaticoBala();
		objControl->colisionAdvSaludableBala();
		guardar();

		if (objControl->cantTotal() == 0)
		{
			int vidaAux = objControl->getJugador()->getVidas();
			nivel++;
			if (nivel < 3) {

				delete objControl;
				objControl = new Controladora(nivel, tiempo, vidaAux);
			}
			else {
				timer1->Enabled = false;
				MostrarPantalla(Ganaste);
				delete objControl;
				nivel = 1;
			}
		}


		else if (objControl->getJugador()->getVidas() == 0 || objControl->getTiempo() == 0)
		{
			timer1->Enabled = false;
			MostrarPantalla(Perdiste);
			delete objControl;
			nivel = 1;
		}
		buffer->Render(g);
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

		g = this->CreateGraphics();
		space = BufferedGraphicsManager::Current;
		buffer = space->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(bmpMundoDos, 0, 0, bmpMundoDos->Width * 2.2, bmpMundoDos->Height * 3.0);
		buffer->Graphics->DrawImage(corazon, 1150, 10, tiempoimg->Width / 15, tiempoimg->Height / 15);
		buffer->Graphics->DrawImage(tiempoimg, 0, 0, tiempoimg->Width / 10, tiempoimg->Height / 10);
		objControl->setVidas(vida);
		objControl->dibujar(buffer->Graphics, bmpHeroe, bmpAdversarioAsintomatico, bmpAdvSaludable, bmpPolicia, bmpAmbulancia, bmpBala);
		objControl->mover2(buffer->Graphics);
		objControl->colisionAdvSaludableBala();
		objControl->colisionAdvAsintomaticoBala();
		objControl->disparoBalaEnemiga(buffer->Graphics);
		objControl->colisionBalaEnemigaHeroe();
		objControl->


		if (objControl->cantTotal() == 0)
		{
			int vidaAux = objControl->getVidas();
			nivel++;
			if (nivel < 4) {
				delete objControl;
				objControl = new Controladora(nivel, tiempo, vidaAux);
			}
			else {
				timer2->Enabled = false;
				MostrarPantalla(Ganaste);
				delete objControl;
				nivel = 1;
			}
		}


		if (objControl->getVidas() == 0 || objControl->getTiempo() == 0)
	{
		timer2->Enabled = false;
		MostrarPantalla(Perdiste);
		delete objControl;
		nivel = 1;
		
	}
	buffer->Render(g);

}




	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		
		switch (e->KeyCode)
		{

		case Keys::Up:
			objControl->getJugador()->MovimientoJugadorDY(-10);
			objControl->getJugador()->setDireccion(Direcciones::Arriba);
			
			break;

		case Keys::Down:
			objControl->getJugador()->MovimientoJugadorDY(10);
			objControl->getJugador()->setDireccion(Direcciones::Abajo);
			break;

		case Keys::Left:
			objControl->getJugador()->MovimientoJugadorDX(-10);
			objControl->getJugador()->setDireccion(Direcciones::Izquierda);
			break;

		case Keys::Right:
			objControl->getJugador()->MovimientoJugadorDX(+10);
			objControl->getJugador()->setDireccion(Direcciones::Derecha);
			break;

		case Keys::Space:
		
			break;

		case Keys::E:
			//musicaDisparo->PlayLooping();
			objControl->disparar();
			break;
		default:
			break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case  Keys::Up:
			objControl->getJugador()->MovimientoJugadorDY(0);
			break;

		case Keys::Down:
			objControl->getJugador()->MovimientoJugadorDY(0);
			break;

		case Keys::Left:
			objControl->getJugador()->MovimientoJugadorDX(0);
			break;

		case Keys::Right:
			objControl->getJugador()->MovimientoJugadorDX(0);
			break;

		case Keys::E:
			//musicaDisparo->Stop();
				break;
		}

	}

	private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {


		
		if (comboBox1->SelectedIndex==0)
		{
		objControl = new Controladora(nivel,tiempo,vida);
		objControl->getJugador()->SetVidas(vida);
		MostrarPantalla(nivelUno);
		timer1->Enabled = true;
			

	    }
		else if (comboBox1->SelectedIndex == 1) {
		objControl = new Controladora(nivel, tiempo, vida);
		objControl->getJugador()->SetVidas(vida);
		MostrarPantalla(nivelUno);
		timer2->Enabled = true;
		
		
		}
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarPantalla(Menu1);
}
private: System::Void pictureBox7_Click(System::Object^ sender, System::EventArgs^ e) {
	MostrarPantalla(Instrucciones1);
}



private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	tiempo = Convert::ToInt32(textBox1->Text);

}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vida = Convert::ToInt32(textBox2->Text);


}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
