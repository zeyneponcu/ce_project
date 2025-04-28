#ifndef PIRE_C
#define PIRE_C

#include "pire.h"

pire pireOlustur(int deger){
	pire this;
	this = (pire)malloc(sizeof(struct PIRE));
	this->super = bocekOlustur(deger);
	this->yoket = &pireYoket;
	return this;
}
void pireYoket(const pire this){
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}

#endif