#pragma once
#include "bonus.h"
class Vida : public Bonus
{
public:
	Vida(void);
	Vida(int px, int py);
	~Vida(void);
};

Vida::Vida(void){}
Vida::Vida(int px, int py):Bonus(px,py,0,0,9,1,"obstaculo.png")
{
	Bonificacion = 1;
	Tipo = 1;
}
Vida::~Vida(void){}