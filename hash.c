#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "hash.h"

struct hash
{
  Lista **lst;
  int tam;
};

typedef struct elemHash
{
  int key;
  void *value;
} ElemHash;

static ElemHash *hash_busca (Lista * lst, int key);

Hash *
hash_cria (int tam)
{
  Hash *tab = (Hash *) malloc (sizeof (Hash));
  tab->tam = tam;
  tab->lst = (Lista **) malloc (tam * sizeof (Lista *));
  for (int i = 0; i < tam; i++)
    tab->lst[i] = NULL;
  return tab;
}

static void
hash_insere (Lista * lst, int key, void *value)
{
  ElemHash *el = (ElemHash *) malloc (sizeof (ElemHash));
  el->key = key;
  el->value = value;
  lst_insFin (lst, el);
}

int
hash_put (Hash * hash, int key, void *value)
{
  int ind = (key % hash->tam);
  if (hash->lst[ind] == NULL)
    {
      hash->lst[ind] = lst_cria ();
    }
  if (hash_busca (hash->lst[ind], key) != NULL)
    return 0;
  else
    {
      hash_insere (hash->lst[ind], key, value);
      return 1;
    }
}

void *
hash_get (Hash * hash, int key)
{
  ElemHash *el = hash_busca (hash->lst[key % hash->tam], key);
  if (el == NULL)
    return NULL;
  else
    return el->value;
}

static ElemHash *
hash_busca (Lista * lst, int key)
{
  lst_posIni (lst);
  void *info;
  while (!0)
    {
      info = lst_prox (lst);
      if (info == NULL)
	break;
      else
	{
	  ElemHash *el = (ElemHash *) info;
	  if (el->key == key)
	    return el;
	}
    }
  return NULL;
}
