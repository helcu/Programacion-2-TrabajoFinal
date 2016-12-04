#pragma once
#include "figura.h"
class Ovni :
	public Figura
{
public:
	Ovni(void);
	~Ovni(void);
	Ovni(int px,int py,int pDx,int pDy);

	 void Mostrar(Graphics ^gr);
	void Ovni::Mover(Graphics ^gr,int Pa,int Pb);
};



Ovni::Ovni(void){}
Ovni::~Ovni(void){}
Ovni::Ovni(int px,int py,int pDx,int pDy):Figura(px,py,pDx,pDy,1,7,"ovni.png"){}


void Ovni::Mostrar(Graphics ^gr){
	Bitmap ^bmp = gcnew Bitmap(gcnew System::String(Nombre));
	Rectangle porcion = Rectangle(c*W,f*H,W,H);
	//Rectangle zoom = Rectangle(x,y,125,90);
	bmp->MakeTransparent(bmp->GetPixel(1,1));
	//gr->DrawImage(bmp,zoom,porcion,GraphicsUnit::Pixel);
	gr->DrawImage(bmp,x,y,porcion,GraphicsUnit::Pixel);
	delete bmp;
	c++;
	if(c > 6)		c = 0;
	
	}

void Ovni::Mover(Graphics ^gr,int Pa,int Pb){

	//if ((Dx<0)&&(x+Dx<-150) || (Dx>0)&&(x+Dx+W >1000))
	if ((Dx<0)&&(x+Dx<Pa-100) || (Dx>0)&&(x+Dx+W >Pa+Pb+100))
		Dx*=-1;
		
		x+=Dx;
		y+=Dy;
		
		Mostrar(gr);	
	}