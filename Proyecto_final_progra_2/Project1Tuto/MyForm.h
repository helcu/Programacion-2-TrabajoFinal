#pragma once

namespace Project1Tuto {
	#include "Juego.h"
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Juego * obj_juego;
		Tecla teclapulsada;
		int cont_aparicion;
		int ndisp;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			obj_juego = new Juego();
			//
			cont_aparicion=0;
			ndisp=10;
			teclapulsada=Tecla::ninguno;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(872, 463);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 
				 

				 Graphics ^gr=this->CreateGraphics();
				 cont_aparicion++;
				 ndisp++;
				 BufferedGraphicsContext ^bgc= BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg=bgc->Allocate(gr, this->ClientRectangle);
				 this->Cursor->Hide();
				 bg->Graphics->Clear(Drawing::Color::LightGray);
				 if(cont_aparicion==15){
				 System::Random^r=gcnew System::Random(System::DateTime::Now.Ticks);
				 obj_juego->Insertar_Enemigos(r);
				 cont_aparicion=0;
				 }
				 obj_juego->ColisionEnemigoBala();
				 obj_juego->Colision_Bonus_Personaje();
				 obj_juego->ColisionPersonajeEnemigo();
				 obj_juego->Mostrar_Todo(bg->Graphics,teclapulsada);
				 
			    /*this->Text = "vida: " + obj_juego->Entregar_vida().ToString();*/

				 this->Text="Space Marines : Zerg Rush";
				 bg->Render(gr);
				 delete bg; 				 
				 delete bgc; 				 
				 delete gr;
				 teclapulsada=Tecla::ninguno;


				 if(obj_juego->GameOver()==true)
				 {	
					this->Text="¡Perdiste!. Presiona ""R"" para volver a intentarlo (LOL)";
					timer1->Enabled=false;
				 }

				 if(obj_juego->EpicWin()==true)
				 {
					this->Text="¡Ganaste!. Presiona ""R"" para volver a intentarlo (LOL)";
					timer1->Enabled=false;
				 
				 }


			 }


	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				// obj_juego->Mover_soldado(e->x,e->y);
			 }


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }


	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				  if (e->KeyCode==Keys::Left)  teclapulsada=Tecla::izquierda;
				 if (e->KeyCode==Keys::Right)  teclapulsada=Tecla::derecha;
				 if (e->KeyCode==Keys::Space)  teclapulsada=Tecla::salto;

				 if (ndisp>1)
				 {
				 if (e->KeyCode==Keys::Up)		teclapulsada=Tecla::disparo;
				 ndisp=0;
				 }

				 if (e->KeyCode==Keys::Escape) Close();

				 if (e->KeyCode==Keys::P)
				 {
					if (timer1->Enabled==true)
						timer1->Enabled=false;
					else
						timer1->Enabled=true;

					teclapulsada=Tecla::ninguno;
				 }

				 if (e->KeyCode==Keys::R)
				 {
					obj_juego = new Juego();
			
					cont_aparicion=0;
					ndisp=10;
					teclapulsada=Tecla::ninguno;
					timer1->Enabled=true;
				 }

				 if (e->KeyCode==Keys::A)	teclapulsada=Tecla::LOL;

			 }
	};
}
