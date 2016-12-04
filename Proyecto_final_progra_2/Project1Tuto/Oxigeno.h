#pragma once
#include "bonus.h"
class Oxigeno :
	public Bonus
{
public:
	Oxigeno(void);
	Oxigeno(int px,int py);
	~Oxigeno(void);
};

Oxigeno::Oxigeno(void)
{
}
Oxigeno::Oxigeno(int px,int py):Bonus(px,py,0,0,8,1,"vida.png")
{
	Bonificacion = 10;
	Tipo = 2;
}
Oxigeno::~Oxigeno(void)
{
}