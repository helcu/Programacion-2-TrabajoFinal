#pragma once
#include "enemigo.h"
class Enemigo3 :
	public Enemigo
{

public:
	Enemigo3(void);
	~Enemigo3(void);
	 Enemigo3(int px, int py, int pDx, int pDy);
	 void Mostrar(Graphics ^gr);

};

Enemigo3::Enemigo3(void){}
Enemigo3::~Enemigo3(void){}
Enemigo3::Enemigo3(int px, int py, int pDx, int pDy):Enemigo(px,py,pDx,pDy,2,4,"Enemigo3.png") {

	VidaE=10;
}

void Enemigo3::Mostrar(Graphics ^gr){
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	Rectangle zoom = Rectangle(x,y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	delete bmp;
	c++;
	if(c > 3)		c = 0;
	
	}