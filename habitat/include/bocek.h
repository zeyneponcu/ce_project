#ifndef BOCEK_H
#define BOCEK_H

#include "canli.h"
#include <stdio.h>
#include <stdlib.h>


struct BOCEK{
	canli super;
	
	void (*yoket)(struct BOCEK*);
	
};
typedef struct BOCEK* bocek;

bocek bocekOlustur(int);
void bocekYoket(const bocek);


#endif