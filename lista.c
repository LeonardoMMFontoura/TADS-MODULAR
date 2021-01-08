#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
  void *info;
  struct no *prox;
  struct no *ant;
};

struct lista
{
  int tam;
  No *ini;
  No *fin;
  No *corr;
};

void *
aloca_e_testa (size_t size)
{
  void *mem = malloc (size);

  if (mem == NULL)
    {
      printf ("*** Erro na alocacao de memoria ***\n");
      exit (1);
    }

  return mem;
}

No *
cria_no (void *info)
{
  No *no = (No *) aloca_e_testa (sizeof (No));
  no->ant = NULL;
  no->info = info;
  no->prox = NULL;

  return no;
}

void
define_lista (Lista * lista, No * no)
{
  lista->ini = no;
  lista->corr = no;
  lista->fin = no;
  lista->tam = no == NULL ? 0 : 1;
}

Lista *
lst_cria (void)
{
  Lista *lista = (Lista *) aloca_e_testa (sizeof (Lista));
  define_lista (lista, NULL);
  return lista;
}

int
lst_vazia (Lista * lista)
{
  return lista->tam == 0;
}

void
lst_insIni (Lista * lista, void *info)
{
  No *no = cria_no (info);

  if (lista->tam == 0)
    define_lista (lista, no);
  else
    {
      no->prox = lista->ini;
      no->prox->ant = no;
      lista->ini = no;
      lista->tam++;
    }
}

void
lst_insFin (Lista * lista, void *info)
{
  No *no = cria_no (info);

  if (lista->tam == 0)
    define_lista (lista, no);
  else
    {
      no->ant = lista->fin;
      no->ant->prox = no;
      lista->fin = no;
      lista->tam++;
    }
}

void *
lst_retIni (Lista * lista)
{
  if (lst_vazia (lista))
    return NULL;
  if (lista->tam == 1)
    {
      void *info = lista->ini->info;
      define_lista (lista, NULL);
      return info;
    }
  else
    {
      No *ini = lista->ini;
      void *info = lista->ini->info;
      lista->ini = lista->ini->prox;
      lista->ini->ant = NULL;
      if (lista->corr == ini)
	lista->corr = lista->ini;
      free (ini);
      lista->tam--;
      return info;
    }
}

void *
lst_retFin (Lista * lista)
{
  if (lst_vazia (lista))
    return NULL;
  if (lista->tam == 1)
    {
      void *info = lista->fin->info;
      define_lista (lista, NULL);
      return info;
    }
  else
    {
      No *fin = lista->fin;
      void *info = lista->fin->info;
      lista->fin = lista->fin->ant;
      lista->fin->prox = NULL;
      if (lista->corr == fin)
	lista->corr = lista->fin;
      free (fin);
      lista->tam--;
      return info;
    }
}

void
lst_posIni (Lista * lista)
{
  lista->corr = lista->ini;
}


void
lst_posFin (Lista * lista)
{
  lista->corr = lista->fin;
}

void *
lst_prox (Lista * lista)
{
  if (lista->corr == NULL)
    return NULL;
  void *info = lista->corr->info;
  lista->corr = lista->corr->prox;
  return info;
}

void *
lst_ant (Lista * lista)
{
  if (lista->corr == NULL)
    return NULL;
  void *info = lista->corr->info;
  lista->corr = lista->corr->ant;
  return info;
}

void
lst_libera (Lista * lista)
{
  No *prox;
  for (No * no = lista->ini; no != NULL; no = prox)
    {
      prox = no->prox;
      free (no->info);
      free (no);
    }
  free (lista);
}
