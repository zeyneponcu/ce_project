#ifndef SATIR_H
#define SATIR_H

#include <stdio.h>
#include <stdlib.h>

#include "dugum.h"

struct SATIR{		 
		dugum ilk;
		
		dugum (*dugumEkle)(int,void*, dugum);
		dugum (*FindByPosition)(struct SATIR*,int);
		void (*add)(struct SATIR*, void *,int);
		void (*removeAt)(struct SATIR*, int);
		void (*okuyucu)(struct SATIR*);
		void (*clear)(struct SATIR*);
		void (*yoket)(struct SATIR*);
};
typedef struct SATIR* Satir;

Satir satirOlustur();
dugum dugumEkle(int,void*, dugum);
dugum FindByPosition(const Satir,int);
void add(const Satir, void *,int);
void removeAt(const Satir, int);
void okuyucu(const Satir);
void clear(const Satir);
void satirYoket(const Satir);


#endif