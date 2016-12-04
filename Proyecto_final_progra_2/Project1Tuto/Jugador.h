#pragma once
#include "figura.h"
//public enum Tecla {Derecha,Izquierda,Disparar,Ninguno};
using namespace System::Drawing;
class Jugador :public Figura
{
	Tecla direccion;
public:
	Jugador(void);
	Jugador(int pX, int pY, int pDx, int pDy);
	~Jugador(void);
	void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr, Tecla teclapulsada);
};
Jugador::Jugador(void){}
Jugador::Jugador(int pX, int pY, int pDx, int pDy)
	:Figura(pX,pY,pDx,pDy,7,4,"soldado.png")
{}
Jugador::~Jugador(void){}
void Jugador::Mostrar(Graphics ^gr)
{	Bitmap ^bmp = 
      gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(Iw*W,Ih*H,W,H);
	Rectangle zoom = Rectangle(X,Y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	gr->DrawImage(bmp,zoom,porcion
		,GraphicsUnit::Pixel);
	delete bmp;
	Iw++;
	if(Iw > 3)
		Iw = 0;
	
}

void Jugador::Mover(Graphics ^gr, Tecla teclapulsada){

	    Dx=0;
		direccion=teclapulsada;

		if (direccion==Tecla::derecha){ Ih=5; Dx=10;}
		if (direccion==Tecla::izquierda){Ih=4; Dx=-10;}
		if (direccion==Tecla::ninguno)	    {Ih=3; Dx=0;}
	
		if (X+Dx<0 || X+Dx+W >=gr->VisibleClipBounds.Right)
		{ Dx=0; direccion=Tecla::ninguno; }
		X+=Dx;
		
		Mostrar(gr);
		/*Mover_Balas(gr);*/

}