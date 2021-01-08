typedef struct fila Fila;
Fila *fila_cria (void);
int fila_vazia (Fila * f);
void fila_enq (Fila * f, void *v);
void *fila_deq (Fila * f);
void fila_libera (Fila * f);
