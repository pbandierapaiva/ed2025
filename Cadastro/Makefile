### Makefile para compilar todos os executáveis


all: encontraOrg.out encontraOrgInd.out encontraOrgEstruturado.out

clean:
	rm *.o *.out

encontraOrg.out: arqEncontraOrg.o  arqutil.o
	gcc -o encontraOrg.out arqEncontraOrg.o  arqutil.o
encontraOrgInd.out: encontraOrgIndice.o arqutil.o
	gcc -o encontraOrgInd.out encontraOrgIndice.o arqutil.o
encontraOrgEstruturado.out: encontraOrgEstruturado.o arqutil.o
	gcc -o encontraOrgEstruturado.out encontraOrgEstruturado.o arqutil.o

arqEncontraOrg.o: arqEncontraOrg.c arqutil.h
	gcc -c arqEncontraOrg.c                      # gera arqEncontraOrg.o
encontraOrgIndice.o: encontraOrgIndice.c  arqutil.h
	gcc -c encontraOrgIndice.c
encontraOrgEstruturado.o: encontraOrgEstruturado.c arqutil.h
	gcc -c encontraOrgEstruturado.c


arqutil.o: arqutil.c arqutil.h
	gcc -c arqutil.c