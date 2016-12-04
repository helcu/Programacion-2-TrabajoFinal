#pragma once
#include "bonus.h"
class BonusP : public Bonus
{
public:
	BonusP(void);
	BonusP(int px, int py);
	~BonusP(void);
};

BonusP::BonusP(void){}
BonusP::BonusP(int px, int py):Bonus(px,py,0,0,8,1,"BonusP.png")
{
	Bonificacion = 1;
	Tipo = 4;
}
BonusP::~BonusP(void){}