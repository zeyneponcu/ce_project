#ifndef DUGUM_C
#define DUGUM_C

#include "dugum.h"

dugum dugumOlustur(int deger,void* tur,dugum next){
	dugum this;
	this=(dugum)malloc(sizeof(struct DUGUM));
	this->kontrol=1;
	this->tur=tur;
	this->next=next;
	this->deger=deger;
	this->yoket=&dugumYoket;
	return this;
	
}
void dugumYoket(const dugum this){
	if(this==NULL) return;
	free(this);
}

#endif