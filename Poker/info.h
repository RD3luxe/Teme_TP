#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct celulag
{
	void *info;
	struct celulag *urm;
} Celula, *TLista, **ALista;

typedef struct jucator
{
	char* nume;
	int nrMaini;
} *Jucator;

typedef struct masa
{
	char* numeMasa;
	TLista jucatori;
	int nrCrtJucatori;
	int nrMaxJucatori;
} *Masa;

typedef struct sala
{
	TLista masa;
	int nrMese;
	int nrLocCrt;
	int nrLocMax;
} *Sala;

typedef void (*TF)(void*);          /* functie afisare/eliberare un element */

void Distruge(ALista aL, TF fe);    /* distruge lista */
size_t LungimeLG(ALista);           /* numarul de elemente din lista */

#endif
