#ifndef BITKI_C
#define BITKI_C

#include "bitki.h"

bitki bitkiOlustur(int deger){
	bitki this;
	this= (bitki)malloc(sizeof(struct BITKI));
	this->super = canliOlustur(deger);
	this->yoket =&bitkiYoket;
	return this;
}

void bitkiYoket(const bitki this){
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}

#endif