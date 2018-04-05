/*--- functiiLG.c -- operatii de baza pentru lista simplu inlantuita generica---*/
#include "info.h"

void Destroy(ALista aL, TF free_elem) /* distruge lista */
{
  while(*aL != NULL)
    {
        TLista aux = *aL;     /* adresa celulei eliminate */
        if (!aux) return; /* lista vida */
        free_elem(aux->info);  /* elib.spatiul ocupat de element*/
        *aL = aux->urm;    /* deconecteaza celula din lista */
        free(aux);   /* elibereaza spatiul ocupat de celula */
    }
}

size_t LungimeLG(ALista a)      /* numarul de elemente din lista */
{
  size_t lg = 0;
  TLista p = *a;
  for (; p != NULL; p = p->urm) lg++;  /* parcurge lista, numarand celulele */
  return lg;
}
