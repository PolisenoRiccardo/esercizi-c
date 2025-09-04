#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stringa_compatta {
    int len;
    char data[];  // Flexible array member!
};

// TODO: Implementa la creazione come nel codice di antirez
// Ma SENZA reference counting per ora
char* crea_stringa_compatta(char *input, int len) {
  if (!input) return NULL;
  struct stringa_compatta *mystr = malloc(sizeof(struct stringa_compatta)+len+1);
  if (!mystr) return NULL;
  mystr->len = len;
  strcpy(mystr->data, input);
  return mystr->data;
}

// scrivi funzioni che recuperano len senza passarlo come parametro
// Hint: usa il pointer arithmetic per tornare alla struct

int ottieni_lunghezza(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)); 
  return mystr->len;
}

void stampa_str(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int));
  for (int i = 0; i < mystr->len; i++) {
    putchar(mystr->data[i]);
  }
  printf("\n");
}

void stampa_con_metadata(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int));
  stampa_str(mystr->data);
  printf("Lunghezza: %d\n", mystr->len);
}

void free_str(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int));
  free(mystr);
}

int main() {
  char* newstr = crea_stringa_compatta("Salsedine", 9);
  printf("%s\n",newstr);

  printf("Lughezza: %d\n", ottieni_lunghezza(newstr));
  stampa_con_metadata(newstr);

  free_str(newstr);
  return 0;
}
