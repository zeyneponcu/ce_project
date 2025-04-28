#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CANLI{
	int deger;
	
	char* (*gorunum)(struct CANLI*);
	void (*yoket)(struct CANLI*);
	
};
typedef struct CANLI* canli;

canli canliOlustur(int);
char* gorunum(const canli);
void canliYoket(const canli);



#endif