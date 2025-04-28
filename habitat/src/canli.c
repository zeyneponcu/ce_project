#ifndef CANLI_C
#define CANLI_C

#include "canli.h"

canli canliOlustur(int deger){
	canli can;
	can=(canli)malloc(sizeof(struct CANLI));
	can->deger=deger;
	can->gorunum=&gorunum;
	
	can->yoket=&canliYoket;
	return can;
}

char* gorunum(const canli this){
	int sayi=this->deger;
	if(sayi>=1&&sayi<=9){
		printf("B");
	}
	else if(sayi>=10&&sayi<=20){
		printf("C");
	}
	else if(sayi>=21&&sayi<=50){
		printf("S");
	}
	else if(sayi>=51&&sayi<=99){
		printf("P");
	}
	else {
		printf("bu canli gecerli degil");
	}
}

void canliYoket(const canli this){
	if(this==NULL) return;
	free(this);
}


#endif