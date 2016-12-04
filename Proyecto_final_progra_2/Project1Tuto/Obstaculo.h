#pragma once
#include "Objetos.h"
class Obstaculo : public Objetos
{
public:
	Obstaculo(void);
	Obstaculo(int pX, int pY);
	~Obstaculo(void);
};

Obstaculo::Obstaculo(void){}
Obstaculo::Obstaculo(int pX, int pY):Objetos(pX,pY,0,0,8,1,"Obstaculo.png")
{
	Bonificacion = 5;
	Tipo = 1;
}
Obstaculo::~Obstaculo(void){}