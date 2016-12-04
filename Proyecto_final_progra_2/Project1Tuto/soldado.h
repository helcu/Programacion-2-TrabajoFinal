#pragma once
#include "figura.h"
#include <conio.h>

using namespace System::Drawing;
class soldado :public Figura
{
	Tecla direccion;
	int gravedad;


public:
	soldado(void);
	soldado(int px, int py, int pDx, int pDy);
	~soldado(void);
	void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr, Tecla teclapulsada);
	

};
soldado::soldado(void){}
soldado::soldado(int px, int py, int pDx, int pDy)	:Figura(px,py,pDx,pDy,7,4,"soldado.png")
{
	gravedad=+10;
	
}
soldado::~soldado(void){}

void soldado::Mostrar(Graphics ^gr)
{	Bitmap ^bmp = 
      gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	Rectangle zoom = Rectangle(x,y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	gr->DrawImage(bmp,zoom,porcion
		,GraphicsUnit::Pixel);
	delete bmp;	
}

void soldado::Mover(Graphics ^gr, Tecla teclapulsada){

	Dy+=gravedad;

	if(y+Dy+H>gr->VisibleClipBounds.Bottom-50)
	{
		y=gr->VisibleClipBounds.Bottom-H-50;
		Dy=0;
	}

	Dx=0;
	direccion=teclapulsada;
	if (direccion==Tecla::derecha){ f=5; Dx=15;}
	if (direccion==Tecla::izquierda){f=4; Dx=-15;}
	if (direccion==Tecla::ninguno)
	{
		if (f%2!=0) f=3;
		else if (f%2==0) f=2;
		else f=3;
		Dx=0;			
	}

	if(direccion==Tecla::salto){if(Dy==0)Dy=-30;}

	if (direccion==Tecla::disparo)
	{
		if (f%2!=0)			f=1;
		else if (f%2==0)	f=0;	
	}

	if(y+Dy<150){Dy=0;}

	if (x+Dx<0 || x+Dx+W >gr->VisibleClipBounds.Right)
	{
		Dx=0;
		direccion=Tecla::ninguno;
	}

	x+=Dx;
	y+=Dy;		

	Mostrar(gr);

	c++;
	if(c > 3)	c = 0;
}



