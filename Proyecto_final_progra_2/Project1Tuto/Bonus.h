#pragma once
#include "figura.h"
using namespace System::Drawing;
class Bonus : public Figura
{protected:
	int estancia;int Bonificacion;int Tipo;int gravedad;Tecla direccion;
public:
	Bonus(void);
	Bonus(int px, int py, int pDx
		, int pDy,int Numerof
		, int Numeroc, char * pNombre);
	~Bonus(void);
	void Dibujar(Graphics ^gr);
	int Entregar_Estancia();
	int Entregar_Tipo();
	void Mover(Graphics ^gr, Tecla teclapulsada);
};

Bonus::Bonus(void){}
Bonus::Bonus(int px, int py, int pDx,
int pDy,int Numerof, int Numeroc
, char * pNombre):Figura(px,py,pDx,pDy
,Numerof,Numeroc,pNombre)
{ estancia = 100; gravedad=1; direccion=Tecla::ninguno;}
Bonus::~Bonus(void){}
void Bonus::Dibujar(Graphics ^gr)
{	Bitmap ^bmp =
		gcnew Bitmap(gcnew 
		System::String(Nombre));
	Rectangle porcion = 
		Rectangle(c*W,f*H,W,H);
	Rectangle zoom = Rectangle(x,y,30,30);
bmp->MakeTransparent(bmp->GetPixel(1,1));
	gr->DrawImage(bmp,zoom
		,porcion,GraphicsUnit::Pixel);
	if(estancia>1)estancia--;
	if(estancia % 5 ==0)f++;	
}
int Bonus::Entregar_Estancia(){
	return estancia;}
int Bonus::Entregar_Tipo(){return Tipo;}

void Bonus::Mover(Graphics ^gr, Tecla teclapulsada){

	Dy+=gravedad;
	
	if(y+Dy+H>gr->VisibleClipBounds.Bottom-25){	
		y=gr->VisibleClipBounds.Bottom-H-25;
		Dy=0;
	}


	System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);
	Dx=(r->Next(-7,7));
		
		/*
		direccion=teclapulsada;
		if (direccion==Tecla::derecha){Dx=-15;}
		if (direccion==Tecla::izquierda){Dx=+15;}
		if (direccion==Tecla::ninguno){Dx=0;}
		*/
		//if(y+Dy<150){Dy=0;}

		x+=Dx;
		y+=Dy;
		
		Dibujar(gr);
}
