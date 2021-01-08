#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor.h"

struct vetor
{
  float x, y;
};

Vetor *
vet_cria (float x, float y)
{
  Vetor *vet = (Vetor *) malloc (sizeof (Vetor));
  if (vet == NULL)
    {
      printf ("Memoria insuficiente!\n");
      exit (1);
    }
  vet->x = x;
  vet->y = y;
  return vet;
}

float
vet_prod_int (Vetor * vet1, Vetor * vet2)
{
  return vet1->x * vet2->x + vet1->y + vet2->y;
}

Vetor *
vet_soma (Vetor * vet1, Vetor * vet2)
{
  Vetor *novo = vet_cria (0., 0.);
  novo->x = vet1->x + vet2->x;
  novo->y = vet1->y + vet2->y;
  return novo;
}

float
vet_norma (Vetor * vet)
{
  return sqrt (pow (vet->x, 2) + pow (vet->y, 2));
}

char *
vet_format (Vetor * novo, char *str)
{
  sprintf (str, "(%.1f,%.1f)", novo->x, novo->y);
  return str;
}

void
vet_libera (Vetor * vet)
{
  free (vet);
}
