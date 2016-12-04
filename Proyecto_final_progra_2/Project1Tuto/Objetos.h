#pragma once
#include "figura.h"
using namespace System::Drawing;
class Objetos : public Figura
{protected:
	int estancia;int Bonificacion;int Tipo;
public:
	Objetos(void);
	Objetos(int pX, int pY, int pDx
		, int pDy,int Numerof
		, int Numeroc, char * pNombre);
	~Objetos(void);
	void Dibujar(Graphics ^gr);
	int Get_Estancia();
	int Get_Tipo();
};

Objetos::Objetos(void){}
Objetos::Objetos(int pX, int pY, int pDx,
int pDy,int Numerof, int Numeroc
, char * pNombre):Figura(pX,pY,pDx,pDy
,Numerof,Numeroc,pNombre)
{ estancia = 1000;}
Objetos::~Objetos(void){}
void Objetos::Dibujar(Graphics ^gr)
{	Bitmap ^bmp =
		gcnew Bitmap(gcnew 
		System::String(Nombre));
	Rectangle porcion = 
		Rectangle(Iw*W,Ih*H,W,H);
	Rectangle zoom = Rectangle(X,Y,30,30);
bmp->MakeTransparent(bmp->GetPixel(1,1));
	gr->DrawImage(bmp,zoom
		,porcion,GraphicsUnit::Pixel);
	if(estancia>1)estancia--;
	if(estancia % 2 ==0)Ih++;	
}
int Objetos::Get_Estancia(){
	return estancia;}
int Objetos::Get_Tipo(){return Tipo;}
