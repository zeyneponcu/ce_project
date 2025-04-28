#ifndef DUGUM_H
#define DUGUM_H

#include <stdio.h>
#include <stdlib.h>


struct DUGUM{		 
		int kontrol;
		int deger;
		void *tur;
		struct DUGUM* next;
		
		void (*yoket)(struct DUGUM*);
		
};
typedef struct DUGUM* dugum;

dugum dugumOlustur(int,void*,dugum);
void dugumYoket(const dugum);

#endif
