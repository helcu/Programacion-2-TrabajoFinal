#pragma once
#include <string.h>
using namespace System::Drawing;
public enum Tecla{ninguno,izquierda,derecha,disparo,salto,LOL};
class Figura
{
protected:
	int x,y,Dx,Dy,c,f,W,H,Numerof,Numeroc;
	char * Nombre;
public:
	Figura(void);

	~Figura(void);

	Figura(int px, int py, int pDx, int pDy,
		int Numerof, int Numeroc, char * pNombre);

	int Entregar_x();
	void Cambiar_x(int nuevo);
	int Entregar_y();
	void Cambiar_y(int nuevo);
	int Entregar_W();
	int Entregar_H();
	int Entregar_f();
	void Cambiar_f(int nuevo);
	int Entregar_Dx();
	void Cambiar_DX(int nuevo);
	int Entregar_Dy();
	void Cambiar_Dy(int nuevo);
	int Entregar_c();

	virtual void Mover(Graphics ^gr, Tecla teclapulsada);
};


Figura::Figura(void){}
Figura::Figura(int px, int py, int pDx, int pDy  , int Numerof, int Numeroc, char * pNombre)
{
	x = px;  y = py;  Dx = pDx; Dy = pDy;
	f = c = 0;
	Nombre = new char [50];
	strcpy(Nombre,pNombre);
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	W = bmp->Width / Numeroc;
	H = bmp->Height / Numerof;
}
Figura::~Figura(void)
{	delete [] Nombre;}
int Figura::Entregar_x(){return x;}
void Figura::Cambiar_x(int nuevo){x = nuevo;}
int Figura::Entregar_y(){return y;}
void Figura::Cambiar_y(int nuevo){y = nuevo;}
int Figura::Entregar_W(){return W;}
int Figura::Entregar_H(){return W;}
int Figura::Entregar_f(){return f;}
void Figura::Cambiar_f(int nuevo){f = nuevo;}
int Figura::Entregar_Dx(){return Dx;}
void Figura::Cambiar_DX(int nuevo){Dx=nuevo;}
int Figura::Entregar_Dy(){return Dx;}
void Figura::Cambiar_Dy(int nuevo){Dx=nuevo;}
int Figura::Entregar_c(){return c;}

void Figura::Mover(Graphics ^gr, Tecla teclapulsada){}