#pragma once
#include "figura.h"

class DanoE:	public Figura
{
public:
	DanoE(void);
	~DanoE(void);
	DanoE(int px,int py);
	void Dibujar(Graphics ^gr);
};

DanoE::DanoE(void){}
DanoE::~DanoE(void){}
DanoE::DanoE(int px,int py):Figura(px,py,0,0,1,10,"danoe.png"){}


void DanoE::Dibujar(Graphics ^gr){
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	//Rectangle zoom = Rectangle(x,y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	//gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	gr->DrawImage(bmp,x,y,porcion,GraphicsUnit::Pixel);
	
	delete bmp;
	c++;
	if(c>9)		c = 0;
	
	}
