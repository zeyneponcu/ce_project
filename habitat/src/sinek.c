#ifndef SINEK_C
#define SINEK_C

#include "sinek.h"

sinek sinekOlustur(int deger){
	sinek this;
	this = (sinek)malloc(sizeof(struct SINEK));
	
	this->super = bocekOlustur(deger);
	
	this->yoket = &sinekYoket;
	return this;
}
void sinekYoket(const sinek this){
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}



#endif