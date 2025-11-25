### Makefile para compilar todos os executáveis


all: encontraOrg.out encontraOrgInd.out encontraOrgEstruturado.out cadlista.out encontraNomeIndLista.out encontraNomeIndAvl.out

clean:
	rm *.o *.out

cadlista.out: cadlista.o arqutil.o 
	gcc -o cadlista.out cadlista.o arqutil.o 

encontraOrg.out: arqEncontraOrg.o  arqutil.o
	gcc -o encontraOrg.out arqEncontraOrg.o  arqutil.o
encontraOrgInd.out: encontraOrgIndice.o arqutil.o
	gcc -o encontraOrgInd.out encontraOrgIndice.o arqutil.o
encontraOrgEstruturado.out: encontraOrgEstruturado.o arqutil.o
	gcc -o encontraOrgEstruturado.out encontraOrgEstruturado.o arqutil.o
encontraNomeIndLista.out: encontraNomeIndLista.o arqutil.o
	gcc -o encontraNomeIndLista.out encontraNomeIndLista.o arqutil.o
encontraNomeIndAvl.out: encontraNomeIndAvl.o arqutil.o
	gcc -o encontraNomeIndAvl.out encontraNomeIndAvl.o arqutil.o

cadlista.o: cadlista.c cadlista.h arqutil.h
	gcc -g -c cadlista.c
arqEncontraOrg.o: arqEncontraOrg.c arqutil.h
	gcc -c arqEncontraOrg.c                      # gera arqEncontraOrg.o
encontraOrgIndice.o: encontraOrgIndice.c  arqutil.h
	gcc -c encontraOrgIndice.c
encontraOrgEstruturado.o: encontraOrgEstruturado.c arqutil.h
	gcc -c encontraOrgEstruturado.c
encontraNomeIndLista.o: encontraNomeIndLista.c arqutil.h
	gcc -g -c encontraNomeIndLista.c
encontraNomeIndAvl.o: encontraNomeIndAvl.c arqutil.h
	gcc -g -c encontraNomeIndAvl.c

arqutil.o: arqutil.c arqutil.h
	gcc -g -c arqutil.c