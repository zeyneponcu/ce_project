#ifndef SATIR_C
#define SATIR_C

#include "satir.h"
#include "dugum.h"
#include "bitki.h"
#include "canli.h"
#include "bocek.h"
#include "pire.h"
#include "sinek.h"

// Yeni bir düğüm oluşturma fonksiyonu
dugum dugumEkle(int deger ,void* tur, dugum next) {
    dugum d = dugumOlustur(deger,tur,next);
    return d;
}

// Yeni bir bağlı liste oluşturma fonksiyonu
Satir satirOlustur() {
    Satir satir;
	satir=(Satir)malloc(sizeof(struct SATIR));
    satir->ilk=dugumEkle(0,NULL,NULL);
	satir->dugumEkle=&dugumEkle;
	satir->FindByPosition=&FindByPosition;
	satir->add=&add;
	satir->removeAt=&removeAt;
	satir->okuyucu=&okuyucu;
	satir->clear=&clear;
	satir->yoket=&satirYoket;
    return satir;
}

// İlgili indisteki düğümü bulma fonksiyonu
dugum FindByPosition(Satir satir, int position) {
    if (position < 0) {
        printf("Girilen indis yanlis\n");
    }
    int index = 0;
    dugum itr = satir->ilk;
    for (; itr != NULL; itr = itr->next, index++) {
        if (position == index) return itr;
    }
    printf("Girilen indis bulunamadi\n");
}

// Yeni bir sayi ekleme fonksiyonu
void add(Satir satir, void *tur,int deger) {
	if(satir->ilk->next==NULL){
		satir->ilk->next=dugumEkle(deger,tur,satir->ilk->next);
		printf("%d",satir->ilk->next->deger);
		return;
	}
	else {
		int index=0;
		printf("girdi99");
		for(dugum itr=satir->ilk->next;itr!=NULL;itr=itr->next){
				index++;
			}
		dugum prev=FindByPosition(satir,index);
		prev->next= dugumEkle(deger,tur,prev->next);
		printf("girdi66");
		printf("%d",prev->next->deger);
	}
}

// Düğüm silme fonksiyonu
void removeAt(Satir satir, int index) {
    if (satir->ilk == NULL) {
        printf("Liste bos\n");
    }
    if (index == 0) {
        dugum del = satir->ilk->next;
        satir->ilk->next = satir->ilk->next->next;
        free(del);
    } else {
        dugum prev = FindByPosition(satir, index-1);
        if (prev->next == NULL) {
            printf("Girilen indis bulunamadi\n");
			return;
        }
        dugum del = prev->next;
        prev->next = prev->next->next;
        free(del);
    }
}
void okuyucu(Satir satir){
	dugum itr = satir->ilk->next;
	bitki b;
	bocek c;
	sinek s;
	pire p;
    for (; itr != NULL; itr = itr->next){
		int sayi=itr->deger;
		if(sayi>=1&&sayi<=9){
			b=itr->tur;
			b->super->gorunum(b->super);
		}
		else if(sayi>=10&&sayi<=20){
			c=itr->tur;
			c->super->gorunum(c->super);
		}
		else if(sayi>=21&&sayi<=50){
			s=itr->tur;
			s->super->super->gorunum(s->super->super);
		}
		else if(sayi>=51&&sayi<=99){
			p=itr->tur;
			p->super->super->gorunum(p->super->super);
		}
		else {
			printf("bu canli gecerli degil");
		}
		 
	} 
}

// Liste temizleme fonksiyonu
void clear(Satir satir) {
    while (satir->ilk != NULL)
        removeAt(satir, 0);
}

// Liste yok etme fonksiyonu
void satirYoket(Satir satir) {
    clear(satir);
    free(satir);
}

#endif