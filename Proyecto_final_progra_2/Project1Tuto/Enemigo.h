#pragma once
#include "figura.h"
class Enemigo :
	public Figura
{
protected:
	int VidaE;
	int e;
public:
	Enemigo(int px, int py, int pDx, int pDy,int pNumerof,int pNumeroc,char* pnombre);
	Enemigo(void);
	~Enemigo(void);
	virtual void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr,int Pa,int Pb);

	int Entregar_VidaE();
	void Cambiar_VidaE(int nuevo);


};

Enemigo::Enemigo(void){}

Enemigo::Enemigo(int px, int py, int pDx, int pDy,int pNumerof,int pNumeroc,char* pnombre):Figura(px,py,pDx,pDy,pNumerof,pNumeroc,pnombre)
{}
	Enemigo::~Enemigo(void){}
	

	void Enemigo::Mostrar(Graphics ^gr){}

	void Enemigo::Mover(Graphics ^gr,int Pa,int Pb){

	//if ((Dx<0)&&(x+Dx<-150) || (Dx>0)&&(x+Dx+W >1000))
	if ((Dx<0)&&(x+Dx<Pa-100) || (Dx>0)&&(x+Dx+W >Pa+Pb+100))
	{		                                                   //rebote
		f++;
		if(f>1) f=0;
		Dx*=-1; 
	}

		x+=Dx;
		
		Mostrar(gr);	
	}
	
	
	int Enemigo::Entregar_VidaE(){return VidaE;}
	void Enemigo::Cambiar_VidaE(int nuevo){VidaE=nuevo;}