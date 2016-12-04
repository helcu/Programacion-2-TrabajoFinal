#pragma once
#include "figura.h"
using namespace System::Drawing;
class Bala :
	public Figura
{
public:
	Bala(void);
	~Bala(void);
	Bala(int px,int py,int pdx,int pdy);

	void Dibujar(Graphics ^gr);
	void Mover(Graphics ^gr, Tecla teclapulsada);

};



Bala::Bala(void){}
Bala::~Bala(void){}
Bala::Bala(int px, int py,int pdx,int pdy):Figura(px,py,pdx,pdy,1,3,"Bala.png") {}

void Bala::Dibujar(Graphics ^gr){
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	//Rectangle zoom = Rectangle(x,y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	//gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	gr->DrawImage(bmp,x,y,porcion,GraphicsUnit::Pixel);
	delete bmp;
	c++;
	if(c>2)		c=0;
	
	}


	void Bala::Mover(Graphics ^gr, Tecla teclapulsada){
	
		x+=Dx;
		y+=Dy;
		
		Dibujar(gr);	
	}