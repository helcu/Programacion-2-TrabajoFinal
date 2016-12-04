#pragma once
#include "figura.h"
class Cara :
	public Figura
{


public:
	Cara(void);
	~Cara(void);
	Cara(int px, int py);
	void Cara::Mostrar(Graphics ^gr);
	
};
void Cara::Mostrar(Graphics ^gr)
{
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	Rectangle zoom = Rectangle(x,y,70,70);
	/*bmp->MakeTransparent(bmp->EntregarPixel(1,1));*/
	gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	delete bmp;
	c++;
	if(c > 9)		c = 0;
	
	}

Cara::Cara(void){}
Cara::~Cara(void){}
	Cara::Cara(int px, int py):Figura(px,py,0,0,1,10,"Cara.jpg"){}