#ifndef SINEK_H
#define SINEK_H

#include <stdio.h>
#include <stdlib.h>

#include "bocek.h"

struct SINEK{
	bocek super;
	
	void (*yoket)(struct SINEK*);
	
};
typedef struct SINEK* sinek;

sinek sinekOlustur(int);
void sinekYoket(const sinek);



#endif