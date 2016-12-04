#pragma once
#include "Figura.h"
#include "soldado.h"
#include "Bonus.h"
#include "Vida.h"
#include "Vida2.h"
#include "BonusP.h"
#include "Oxigeno.h"
#include <stdio.h>
#include"Fondo.h"
#include"Enemigo.h"
#include"Enemigo1.h"
#include"Cara.h"
#include "Bala.h"
#include "DanoE.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include "Ovni.h"

using namespace System::Drawing;

class Juego
{
	Ovni* Obj_Ovni;
	soldado * obj_soldado;
	Bonus** arrBonus;
	Fondo* obj_fondo;
	Enemigo** Arrenemigo;
	Cara*obj_Cara;
	int vida;
	int oxigeno;
	int cantidad;
	int anchoForm,altoForm;
	int Frecuencia_Bonus;
	int cantidadE;
	int puntaje;
	int nivel;
	int demora;
	int cantmaxE;
	int cuentamuertos;

	Bala** arrBala;
	int cant_Bala;

	DanoE** arrDanoE;
	int cant_DanoE;

	Bala** arrBalaE;
	int cant_BalaE;

public:
	Juego(void);
	~Juego(void);
	void Mostrar_Todo(Graphics ^gr, Tecla teclapulsada);
	void Mover_soldado(int xm, int ym);
	void Insertar_Bonus(System::Random ^r);
	void Frencuencia_Bonus();
	void Colision_Bonus_Personaje();
	int Entregar_vida();
	int Entregar_oxigeno();
	void Eliminar_Bonus(int indice);
	void Eliminar_BonusxEstancia();
	void Insertar_Enemigos(System::Random ^r);
	void Eliminar_Enemigos(int indice);
	//bool Valida_movimiento_Bonus();

	void Disparar(int fp);
	void Mover_Bala(Graphics ^gr);
	void Eliminar_Bala(int indice);

	void ColisionEnemigoBala();
	void ColisionPersonajeEnemigo();

	void Insertar_DanoE(int indice);
	void Eliminar_DanoE(int indice);

	void DisparoOvni();
	void Mover_BalaE(Graphics ^gr);
	void Eliminar_BalaE(int indice);

	void ColisionPersonajeBalaE();


	bool GameOver();
	bool EpicWin();

	
};



Juego::Juego(void)
{
	Obj_Ovni=new Ovni(-100,50,5,0);
	obj_soldado = new soldado(0,250,0,0);
	obj_fondo= new Fondo(0,0,0);
	obj_Cara=new Cara(0,1);
	vida=240;
	oxigeno = 240;
	cantidad=0;
	Frecuencia_Bonus=0;
	altoForm=501;
	anchoForm=888;
	cantidadE=0;
	cant_Bala=0;
	cant_DanoE=0;
	puntaje=0;
	nivel=0;
	arrBala=NULL;
	arrBonus = NULL;
	Arrenemigo=NULL;
	arrDanoE=NULL;
	arrBalaE=NULL;
	cant_BalaE=0;
	demora=0;
	cantmaxE=3;
	cuentamuertos=0;
	
	System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);
	Insertar_Bonus(r);
	/*System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);*/
		/*for (int i=0;i<1 ;i++)
			Insertar_Enemigos(r);*/
}
Juego::~Juego(void)
{
	delete obj_soldado;
delete obj_Cara;
delete obj_fondo;

for(int i=0;i<cantidadE;i++)	delete Arrenemigo[i];
	delete Arrenemigo;

for(int i=0;i<cantidad;i++)		delete arrBonus[i]; 
	delete arrBonus;

for(int i=0;i<cant_Bala;i++)	delete arrBala[i];
	delete arrBala;

for(int i=0;i<cant_BalaE;i++)	delete arrBalaE[i];
	delete arrBalaE;

for(int i=0;i<cant_DanoE;i++)	delete arrDanoE[i];
	delete arrDanoE;


}
void Juego::Frencuencia_Bonus()
{	
   Frecuencia_Bonus++;
	if(Frecuencia_Bonus%5==0)
	{
		System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);
	    Insertar_Bonus(r);		
	}	
}


void Juego::Mostrar_Todo(Graphics ^gr, Tecla teclapulsada)
{
	demora++;
	if(demora%3==0)
	{
	if(oxigeno>0)		oxigeno--;
	
		demora=0;
	}

	if(cuentamuertos%3==0&&cuentamuertos!=0)
	{
		nivel++;
		cantmaxE++;
		cuentamuertos=0;
	}

	if(vida<0)	vida=0;
	if(oxigeno<0)	oxigeno=0;
	
	Frencuencia_Bonus();
		
	obj_fondo->Mover(gr,teclapulsada);
	
	obj_soldado->Mover(gr,teclapulsada);
	
	int Pa=obj_soldado->Entregar_x();
	int Pb=obj_soldado->Entregar_W();
	
	if (nivel>1)
	{
		Obj_Ovni->Mover(gr,Pa,Pb);
	
		if(obj_soldado->Entregar_x()+obj_soldado->Entregar_W()/2
				==Obj_Ovni->Entregar_x()+Obj_Ovni->Entregar_W()/2)
			DisparoOvni();

		if(arrBalaE!=NULL)
		{
			Mover_BalaE(gr);
			ColisionPersonajeBalaE();
		}	
	}

	if(puntaje>=1500)
	{
		puntaje=1500;
		Obj_Ovni->Cambiar_Dy(-15);
		Obj_Ovni->Cambiar_DX(0);
	}


	if(Arrenemigo!=NULL){ 
		for (int i=0;i<cantidadE;i++)
			Arrenemigo[i]->Mover(gr,Pa,Pb);}
			
	Mover_Bala(gr);

	if (teclapulsada==Tecla::disparo)
	{
		Disparar(obj_soldado->Entregar_f());
	}

	//if (Valida_movimiento_Bonus())
		if (arrBonus!=NULL){
			for (int i=0;i<cantidad;i++)
				arrBonus[i]->Mover(gr,teclapulsada);}

	if (arrDanoE!=NULL)
		for (int i=0;i<cant_DanoE;i++)
			arrDanoE[i]->Dibujar(gr);

	for (int i=0;i<cant_DanoE;i++)
		if(arrDanoE[i]->Entregar_c()==9)
			Eliminar_DanoE(i);	

	Eliminar_BonusxEstancia();
	gr->FillRectangle(Brushes::Gray,70,0,450,25);
	gr->DrawRectangle( Pens::Black,70,0,450,25);
	gr->FillRectangle(Brushes::Red,70,11,vida,10);
	gr->DrawRectangle( Pens::Black,70,11,240,10);
	gr->FillRectangle(Brushes::Blue,70,1,oxigeno,10);
	gr->DrawRectangle( Pens::Black,70,1,240,10);
	System::Drawing::Font^f1=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString("Oxigeno" ,f1,Brushes::Black,320,0);
	System::Drawing::Font^f2=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString("Vida" ,f2,Brushes::Black,320,11);
	System::Drawing::Font^f3=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString( "puntaje:" ,f3,Brushes::Black,400,11);
	System::Drawing::Font^f4=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString( puntaje.ToString() ,f4,Brushes::Black,450,11);
	System::Drawing::Font^f5=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString( "nivel:" ,f5,Brushes::Yellow,400,0);
	System::Drawing::Font^f6=gcnew System::Drawing::Font("Arial Black",7);
	gr->DrawString( nivel.ToString() ,f6,Brushes::Yellow,450,0);

	obj_Cara->Mostrar(gr);

	if(teclapulsada==Tecla::LOL)
		puntaje+=100;
	
	
}

void Juego::Mover_soldado(int xm, int ym)
{
	obj_soldado->Cambiar_x(xm-(125/2));
	obj_soldado->Cambiar_y(ym-(90/2));
} 
void Juego::Insertar_Bonus(System::Random ^r)
{    
	if (cantidad<cantmaxE)
	{
	Bonus** aux=new  Bonus*[cantidad+1];
	 if (aux!=NULL)
	{  for (int i = 0; i < cantidad; i++)
			aux[i]=arrBonus[i];

	 int randLOL=0;
	 randLOL=r->Next(1,5000);

	 if (randLOL%2==0&&randLOL%3==0&&randLOL%5!=0) aux[cantidad]=new Vida(r->Next(1,anchoForm-1), -20); //280
	 else if (randLOL%2==0&&randLOL%3!=0&&randLOL%5!=0) aux[cantidad]=new Oxigeno(r->Next(1,anchoForm-1), -20);
	 else if (randLOL%2!=0&&randLOL%3!=0&&randLOL%5==0)aux[cantidad]=new BonusP(r->Next(1,anchoForm-1), -20);
	 else  aux[cantidad]=new Vida2(r->Next(1,anchoForm-1), -20);	 
	 				
	    cantidad++;
		if (arrBonus!=NULL)
			delete[] arrBonus;
	   arrBonus=aux;
	}
	}
     	
}
void Juego::Colision_Bonus_Personaje()
{
	Rectangle r1 = Rectangle(obj_soldado->Entregar_x(),
		obj_soldado->Entregar_y(),obj_soldado->Entregar_W(),
		obj_soldado->Entregar_H());
	for(int i=0;i<cantidad;i++)
	{
		Rectangle r2 = Rectangle(arrBonus[i]->Entregar_x(),
			arrBonus[i]->Entregar_y(),arrBonus[i]->Entregar_W(),
			arrBonus[i]->Entregar_H());
		if(r1.IntersectsWith(r2))
		{
			if(arrBonus[i]->Entregar_Tipo()==1)//vida
				vida-=5;
			else if (arrBonus[i]->Entregar_Tipo()==2)//O2
			{
				oxigeno+=25;
				puntaje+=5;
			}
			else if (arrBonus[i]->Entregar_Tipo()==3)
			{
				vida+=30;
				puntaje+=5;
			}
			
			else if (arrBonus[i]->Entregar_Tipo()==4)
				puntaje+=10;

			if (oxigeno>240)
				oxigeno=240;

			if (vida>240)
				vida=240;			

			Eliminar_Bonus(i);
		}
	}
}
int Juego::Entregar_vida()
{return vida;
}
int Juego::Entregar_oxigeno()
{return oxigeno;
}
void Juego::Eliminar_Bonus(int indice)
{
	if(cantidad>0){
	Bonus **aux=new Bonus*[cantidad -1];
	if(aux!=NULL)
	{ 
		int h=0;
		for(int i=0;i<cantidad;i++)
		{
			if(i!=indice)
			{
			aux[h]=arrBonus[i];
			h++;
		    }
	   }//copiado de elementos
		cantidad--;
		if(arrBonus!=NULL) delete []arrBonus;
		arrBonus=aux;
	}
}
}
void Juego::Eliminar_BonusxEstancia(){
		if(cantidad>0){
			int contador;
			for(int i=0;i<cantidad;i++)
				if(arrBonus[i]->Entregar_Estancia()<=0)
					contador++;
	Bonus **aux=new Bonus*[cantidad-contador];
	if(aux!=NULL)
	{ 
		int h=0;
		for(int i=0;i<cantidad;i++)
		{
			if(arrBonus[i]->Entregar_Estancia()>0)
			{
			aux[h]=arrBonus[i];
			h++;
		    }
	   }
		cantidad=cantidad-contador;
		if(arrBonus!=NULL) delete []arrBonus;
		arrBonus=aux;
	}
  }
}

void Juego::Insertar_Enemigos(System::Random ^r)
	{   
		if(cantidadE<cantmaxE){
		Enemigo** aux=new Enemigo*[cantidadE+1];
		 if (aux!=NULL)
		{ 
			for (int i = 0; i < cantidadE; i++)
				aux[i]=Arrenemigo[i];
		 int lado;                                  // para que el enemigo aparesca en lados diferentes
		 if(r->Next() %2==0) lado=-120; 
		 else lado=888;
				   
		 int a=(r->Next(1,6000));

				if(a%2==0&&a%3!=0&&nivel>=5)
					aux[cantidadE]=new Enemigo3(lado,360,7,0);					
				else if(a%3==0&&a%2!=0&&nivel>=2)
					aux[cantidadE]=new Enemigo2(lado,360,5,0);
				else
					aux[cantidadE]=new Enemigo1(lado,360,3,0);
					

		    cantidadE++;
			if (Arrenemigo!=NULL)
				delete[] Arrenemigo;
		   Arrenemigo=aux;
		}

		}
}

		 void Juego::Eliminar_Enemigos(int indice)
{   		
		Enemigo ** aux =  new Enemigo*[cantidadE-1];
	if(aux!=NULL)
	{   int h=0;
		for(int i=0;i<cantidadE;i++)
			if(i!=indice)
				{aux[h] = Arrenemigo[i];
		         h++;
				}
		cantidadE--;
		if(Arrenemigo!=NULL) delete[] Arrenemigo;
		Arrenemigo = aux;
	}
		
}


/*
bool Juego::Valida_movimiento_Bonus(){
	
	if (obj_fondo->Entregar_x()==0 || obj_fondo->Entregar_x()==500)
		return false;
	else
		return true;
}*/


void Juego::Disparar(int fp){
Bala** aux=new Bala*[cant_Bala+1];
		if (aux!=NULL){
		for (int i=0;i<cant_Bala;i++)
			aux[i]=arrBala[i];

		if (fp%2==0)
		{
		aux[cant_Bala]=new Bala(
			obj_soldado->Entregar_x(),obj_soldado->Entregar_y()+32,-20,0);
		//obj_soldado->Cambiar_f(0);
		}
		else if (fp%2!=0)
		{
		aux[cant_Bala]=new Bala(
			obj_soldado->Entregar_x()+obj_soldado->Entregar_W()/2+50,obj_soldado->Entregar_y()+32,20,0);
		//obj_soldado->Cambiar_f(1);
		}
		cant_Bala++;
		if (arrBala!=NULL) 
		    delete[] arrBala;
		arrBala=aux;
		}
}

void Juego::Mover_Bala(Graphics ^gr){

	if (arrBala!=NULL)
	{
		for (int i=0;i<cant_Bala;i++)
		{
			arrBala[i]->Mover(gr,Tecla::ninguno);
		
			if (arrBala[i]->Entregar_x()+arrBala[i]->Entregar_Dx()<-120 ||
				arrBala[i]->Entregar_x()+arrBala[i]->Entregar_Dx()+arrBala[i]->Entregar_W()>888)
			{		                                            
				Eliminar_Bala(i);
			}
		}
	}
}


void Juego::Eliminar_Bala(int indice){

	Bala ** aux =  new Bala*[cant_Bala-1];
	if(aux!=NULL)
	{   int h=0;
		for(int i=0;i<cant_Bala;i++)
			if(i!=indice)
				{aux[h] = arrBala[i];
		         h++;
				}
		cant_Bala--;
		if(arrBala!=NULL) delete[] arrBala;
		arrBala = aux;
	}
}



void Juego::ColisionEnemigoBala(){

		for(int i=0;i<cantidadE;i++)
	{
	Rectangle r1 = Rectangle(Arrenemigo[i]->Entregar_x(),
	Arrenemigo[i]->Entregar_y(),Arrenemigo[i]->Entregar_W(),Arrenemigo[i]->Entregar_H());

		for(int j=0;j<cant_Bala;j++)
		{
			Rectangle r2 = Rectangle(arrBala[j]->Entregar_x(),
	arrBala[j]->Entregar_y(),arrBala[j]->Entregar_W(),arrBala[j]->Entregar_H());

			if(r1.IntersectsWith(r2))
			{	
				Arrenemigo[i]->Cambiar_VidaE(Arrenemigo[i]->Entregar_VidaE()-1);

				if (Arrenemigo[i]->Entregar_VidaE()==0)
				{
					if (cantidad<2*cantmaxE)
					{
					Bonus** aux2=new  Bonus*[cantidad+1];
					 if (aux2!=NULL)
					{  for (int i = 0; i < cantidad; i++)
							aux2[i]=arrBonus[i];

					 System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);
					 
					 int ab=Arrenemigo[i]->Entregar_x()+Arrenemigo[i]->Entregar_W();

					 if (r->Next(1,5000)%2==0) aux2[cantidad]=new Oxigeno(ab,400); //280
					 else  aux2[cantidad]=new Vida2(ab,400);	 
	 				
					cantidad++;
					if (arrBonus!=NULL)
						delete[] arrBonus;
					arrBonus=aux2;
				}
				}

					puntaje+=30;
					Eliminar_Enemigos(i);
					i--;
					cuentamuertos++;
				}

				else
				{
					Insertar_DanoE(j);				
				}

				Eliminar_Bala(j);				
				j--;

			}
		}
		}
}



void Juego::ColisionPersonajeEnemigo(){

	Rectangle r1 = Rectangle(obj_soldado->Entregar_x(),
	obj_soldado->Entregar_y()+5,obj_soldado->Entregar_W(),obj_soldado->Entregar_H());

	for(int i=0;i<cantidadE;i++)
	{
		Rectangle r2 = Rectangle(Arrenemigo[i]->Entregar_x(),
		Arrenemigo[i]->Entregar_y(),Arrenemigo[i]->Entregar_W(),Arrenemigo[i]->Entregar_H());

		if(r1.IntersectsWith(r2))
		{				
			vida-=1;
		}
	}
}



void Juego::Insertar_DanoE(int indice){

DanoE** aux=new DanoE*[cant_DanoE+1];
		if (aux!=NULL){
		for (int i=0;i<cant_DanoE;i++)
			aux[i]=arrDanoE[i];

		System::Random ^r=gcnew System::Random ((int) System::DateTime::Now.Ticks);

		int a=r->Next(1,20);
		int b=r->Next(1,20);

		aux[cant_DanoE]=new DanoE(arrBala[indice]->Entregar_x()+arrBala[indice]->Entregar_W()/2-15+a,
			arrBala[indice]->Entregar_y()+arrBala[indice]->Entregar_H()/2-30+b);

		//Arrenemigo[indice]->Entregar_x(),Arrenemigo[indice]->Entregar_y()
			
		cant_DanoE++;
		if (arrDanoE!=NULL) 
		    delete[] arrDanoE;
		arrDanoE=aux;
		}
}




void Juego::Eliminar_DanoE(int indice){

DanoE ** aux =  new DanoE*[cant_DanoE-1];
	if(aux!=NULL)
	{   int h=0;
		for(int i=0;i<cant_DanoE;i++)
			if(i!=indice)
				{aux[h] = arrDanoE[i];
		         h++;
				}
		cant_DanoE--;
		if(arrDanoE!=NULL) delete[] arrDanoE;
		arrDanoE = aux;
	}
}


void Juego::DisparoOvni(){

	Bala** aux=new Bala*[cant_BalaE+1];
		if (aux!=NULL){
		for (int i=0;i<cant_BalaE;i++)
			aux[i]=arrBalaE[i];

		aux[cant_BalaE]=new Bala(
			Obj_Ovni->Entregar_x()+Obj_Ovni->Entregar_W()/2,
			Obj_Ovni->Entregar_y()+Obj_Ovni->Entregar_H()/2,0,20);
		
		cant_BalaE++;
		if (arrBalaE!=NULL) 
		    delete[] arrBalaE;
		arrBalaE=aux;
		}
}



void Juego::Mover_BalaE(Graphics ^gr){

	if (arrBalaE!=NULL)
	{
		for (int i=0;i<cant_BalaE;i++)
		{
			arrBalaE[i]->Mover(gr,Tecla::ninguno);
		
			if (arrBalaE[i]->Entregar_y()+arrBalaE[i]->Entregar_Dy()>501)
			{		                                            
				Eliminar_BalaE(i);
			}
		}
	}
}


void Juego::Eliminar_BalaE(int indice){

	Bala ** aux =  new Bala*[cant_BalaE-1];
	if(aux!=NULL)
	{   int h=0;
		for(int i=0;i<cant_BalaE;i++)
			if(i!=indice)
				{aux[h] = arrBalaE[i];
		         h++;
				}
		cant_BalaE--;
		if(arrBalaE!=NULL) delete[] arrBalaE;
		arrBalaE = aux;
	}
}



void Juego::ColisionPersonajeBalaE(){

	Rectangle r1 = Rectangle(obj_soldado->Entregar_x(),
	obj_soldado->Entregar_y()+5,obj_soldado->Entregar_W(),obj_soldado->Entregar_H());

	for(int i=0;i<cant_BalaE;i++)
	{
		Rectangle r2 = Rectangle(arrBalaE[i]->Entregar_x(),
		arrBalaE[i]->Entregar_y(),arrBalaE[i]->Entregar_W(),arrBalaE[i]->Entregar_H());

		if(r1.IntersectsWith(r2))
		{				
			vida-=10;
			Eliminar_BalaE(i);
		}
	}
}




bool Juego::GameOver(){

	if (vida==0 || oxigeno==0)
		return true;
	else
		return false;
}


bool Juego::EpicWin(){

	if(Obj_Ovni->Entregar_y()+Obj_Ovni->Entregar_H()<0)
		return true;
	else
		return false;
}