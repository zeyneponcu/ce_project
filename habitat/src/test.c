#include <stdio.h>
#include <stdlib.h>

#include "bitki.h"
#include "canli.h"
#include "bocek.h"
#include "pire.h"
#include "sinek.h"
#include "satir.h"
#include "dugum.h"


int main(){
	
	FILE *veri=fopen("veri.txt","r");
	int sayi=0, index=0;
	char satirsonukontrol,kontrol;
	bitki b;
	bocek c;
	sinek s;
	pire p;
	Satir satir;
	printf("%d\n",sizeof(struct BITKI));
	printf("%d\n",sizeof(struct BOCEK));
	printf("%d\n",sizeof(struct PIRE));
	printf("%d\n",sizeof(struct SINEK));
	printf("%d\n",sizeof(struct CANLI));
	printf("%d\n",sizeof(struct SATIR));
	satir= satirOlustur();
	while (fscanf(veri,"%d",&sayi)!=EOF ) {
		if(sayi>=1&&sayi<=9){
			b=bitkiOlustur(sayi);
			//b->super->gorunum(b->super);
			satir->add(satir,b,sayi);
			
		}
		else if(sayi>=10&&sayi<=20){
			c=bocekOlustur(sayi);
			//c->super->gorunum(c->super);
			satir->add(satir,c,sayi);
		}
		else if(sayi>=21&&sayi<=50){
			s=sinekOlustur(sayi);
			//s->super->super->gorunum(s->super->super);
			satir->add(satir,s,sayi);
		}
		else if(sayi>=51&&sayi<=99){
			p=pireOlustur(sayi);
			//p->super->super->gorunum(p->super->super);
			satir->add(satir,p,sayi);
		}
		else {
			printf("bu canli gecerli degil");
		}
		satirsonukontrol = fgetc(veri);
		if (satirsonukontrol == '\n' || satirsonukontrol == EOF) {
            printf("\n");
        } 
	}
	
	
	fclose(veri);
} 