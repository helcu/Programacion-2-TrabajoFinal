#pragma once
#include "figura.h"
class Fondo :
	public Figura

{
		bool tope;
public:
	Fondo(void);
	~Fondo(void);
	Fondo(int px,int py,int pdx);
	bool Entregar_tope();
	
	void Mover(System::Drawing::Graphics^gr,Tecla direccion);
	void Dibujar(System::Drawing::Graphics^gr);
};


Fondo::Fondo(void){}

Fondo::Fondo(int px,int py,int pdx):Figura(0,0,0,0,1,40,"fondo2.jpg"){

	tope=false;

}

	Fondo::~Fondo(void){delete []Nombre;}

	void Fondo::Dibujar(System::Drawing::Graphics^gr){

	System::Drawing::Bitmap^bmp=gcnew System::Drawing::Bitmap(gcnew System::String(Nombre));
	System::Drawing::Rectangle porcion=System::Drawing::Rectangle((W*c),H*f,gr->VisibleClipBounds.Width,H);
	System::Drawing::Rectangle zoom=System::Drawing::Rectangle(x,y,gr->VisibleClipBounds.Width,459);
		bmp->MakeTransparent(bmp->GetPixel(1,1));
		gr->DrawImage(bmp,zoom,porcion,System::Drawing::GraphicsUnit::Pixel);
		delete bmp;
	
	
	}
	void Fondo::Mover(System::Drawing::Graphics^gr,Tecla direccion){
	
	//Dx=0;
		tope=false;
	if(direccion==Tecla::derecha){
		c++;
			if(c>10){
				c=10; }

			if(c==10)
				tope=true;

		//Dx=-10;
	}

	if(direccion==Tecla::izquierda){
		c--;
	if(c<0){
		c=0; }

	if(c==0) tope=true;

		//Dx=10;
	}

	//x+=Dx;
	
	Dibujar(gr);
	}

	bool Fondo::Entregar_tope(){return tope;}