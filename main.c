// #include <stdio.h>
// #include <stdlib.h>
// #include "fila.h"
// #include "vetor.h"

// int main(void) {
//     Fila *f=fila_cria();
//     Vetor *v1=vet_cria(1.0,1.0);
//     Vetor *v2=vet_cria(2.0,2.0);
//     Vetor *v3=vet_cria(3.0,3.0);
//     fila_enq(f,v1);
//     fila_enq(f,v2);
//     fila_enq(f,v3);
//     while(!fila_vazia(f)) {
//         Vetor *aux=(Vetor *) fila_deq(f);
//         char vet[20];
//         puts(vet_format(aux,vet));
//     }
//     fila_libera(f);
   
    
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "vetor.h"
int
main (void)
{
  int ret;
  char vet[20];
  Vetor *v;
  Vetor *v1 = vet_cria (1.0, 1.0);
  Vetor *v2 = vet_cria (2.0, 2.0);
  Vetor *v3 = vet_cria (3.0, 3.0);
  Vetor *v4 = vet_cria (4.0, 4.0);
  Hash *th = hash_cria (10);
  ret = hash_put (th, 123, v1);
  if (ret == 0)
    printf ("Chave ja! existente v1\n");
  ret = hash_put (th, 223, v2);
  if (ret == 0)
    printf ("Chave ja! existente v2\n");
  ret = hash_put (th, 123, v3);
  if (ret == 0)
    printf ("Chave ja! existente v3\n");
  ret = hash_put (th, 300, v4);
  if (ret == 0)
    printf ("Chave ja! existente v4\n");
  v = hash_get (th, 123);
  if (v == NULL)
    printf ("Nao achou\n");
  else
    puts (vet_format (v, vet));
  v = hash_get (th, 223);
  if (v == NULL)
    printf ("Nao achou\n");
  else
    puts (vet_format (v, vet));
  v = hash_get (th, 323);
  if (v == NULL)
    printf ("Nao achou\n");
  else
    puts (vet_format (v, vet));
  v = hash_get (th, 300);
  if (v == NULL)
    printf ("Nao achou\n");
  else
    puts (vet_format (v, vet));
  return 0;
}
