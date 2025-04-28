#ifndef BOCEK_C
#define BOCEK_C

#include "bocek.h"

bocek bocekOlustur(int deger){
	bocek this;
	
	this = (bocek)malloc(sizeof(struct BOCEK));
	
	this->super = canliOlustur(deger);
	
	this->yoket = &bocekYoket;
	return this;
}

void bocekYoket(const bocek this){
	if(this==NULL) return;
	this->super->yoket(this->super);
	free(this);
}


#endif