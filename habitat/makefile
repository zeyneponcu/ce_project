hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/canli.o -c ./src/canli.c
	gcc -I ./include/ -o ./lib/bitki.o -c ./src/bitki.c
	gcc -I ./include/ -o ./lib/bocek.o -c ./src/bocek.c
	gcc -I ./include/ -o ./lib/sinek.o -c ./src/sinek.c
	gcc -I ./include/ -o ./lib/pire.o -c ./src/pire.c
	gcc -I ./include/ -o ./lib/dugum.o -c ./src/dugum.c
	gcc -I ./include/ -o ./lib/satir.o -c ./src/satir.c
	gcc -I ./include/ -o ./bin/test ./lib/canli.o ./lib/bitki.o ./lib/bocek.o ./lib/sinek.o ./lib/pire.o ./lib/dugum.o ./lib/satir.o ./src/test.c
	
calistir:
	./bin/test	