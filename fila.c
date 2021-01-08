#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"

struct fila
{
  Lista *lst;
};

Fila *
fila_cria (void)
{
  Fila *f = (Fila *) malloc (sizeof (Fila));
  if (f == NULL)
    {
      printf ("Memoria Insuficiente!\n");
      exit (1);
    }
  Lista *n = lst_cria ();
  f->lst = n;
  return f;
}

int
fila_vazia (Fila * f)
{
  return lst_vazia (f->lst);
}

void
fila_enq (Fila * f, void *v)
{
  lst_insFin (f->lst, v);
}

void *
fila_deq (Fila * f)
{
  void *sai = lst_retIni (f->lst);
  return sai;
}

void
fila_libera (Fila * f)
{
  lst_libera (f->lst);
  free (f);
}
