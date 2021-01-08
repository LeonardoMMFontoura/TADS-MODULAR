typedef struct hash Hash;
Hash *hash_cria (int tam);
int hash_put (Hash * hash, int key, void *value);
void *hash_get (Hash * hash, int key);
