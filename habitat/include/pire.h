#ifndef PIRE_H
#define PIRE_H

#include <stdio.h>
#include <stdlib.h>
 
#include "canli.h"
#include "bocek.h"

struct PIRE{
	bocek super;
	
	void (*yoket)(struct PIRE*);
	
};
typedef struct PIRE* pire;

pire pireOlustur(int);
void pireYoket(const pire);


#endif