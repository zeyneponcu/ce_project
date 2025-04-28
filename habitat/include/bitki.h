#ifndef BITKI_H
#define BITKI_H

#include "canli.h"
#include <stdio.h>
#include <stdlib.h>


struct BITKI{
	canli super;
	
	void (*yoket)(struct BITKI*);
	
};
typedef struct BITKI* bitki;

bitki bitkiOlustur(int);
void bitkiYoket(const bitki);

#endif