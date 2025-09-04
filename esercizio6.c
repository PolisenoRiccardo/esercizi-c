#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stringa_compatta {
    int len;
    int refcount;
    char data[];  // Flexible array member!
};

char* crea_stringa_rc(char *input, int len) {
  if (!input) return NULL;
  struct stringa_compatta *mystr = malloc(sizeof(struct stringa_compatta)+len+1);
  if (!mystr) return NULL;
  mystr->len = len;
  mystr->refcount = 1;
  strcpy(mystr->data, input);
  mystr->data[len] = 0;
  return mystr->data;
}

int ottieni_lunghezza(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)*2); 
  return mystr->len;
}

void stampa_str(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)*2);
  for (int i = 0; i < mystr->len; i++) {
    putchar(mystr->data[i]);
  }
  printf("\n");
}

void stampa_con_metadata(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)*2);
  stampa_str(mystr->data);
  printf("Lunghezza: %d\n", mystr->len);
}

void retain_str(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)*2);
  mystr->refcount++; 
}
  
void release_stringa(char *s) {
  struct stringa_compatta *mystr = (struct  stringa_compatta *)(s - sizeof(int)*2);
  if (mystr->refcount <= 0) {
    printf("Invalid counter\n");
  }
  mystr->refcount--; 
  if (mystr->refcount == 0) {
    free(mystr);
    printf("Stringa liberata\n");
  }
}

int main() {
  char* newstr = crea_stringa_compatta("Salsedine", 9);
  printf("%s\n",newstr);

  printf("Lughezza: %d\n", ottieni_lunghezza(newstr));
  stampa_con_metadata(newstr);


  return 0;
}
