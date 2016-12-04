#pragma once
#include "bonus.h"
class Vida2 : public Bonus
{
public:
	Vida2(void);
	Vida2(int px, int py);
	~Vida2(void);
};

Vida2::Vida2(void){}
Vida2::Vida2(int px, int py):Bonus(px,py,0,0,8,1,"vida2.png")
{
	Bonificacion = 3;
	Tipo = 3;
}
Vida2::~Vida2(void){}