#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string_semplice {
    int len;
    char data[]; // il testo della stringa
};

// TODO: Implementa queste funzioni:
struct string_semplice* crea_stringa(char *input, int len) {
  struct string_semplice *str  = malloc(sizeof(struct string_semplice)+len+1);
  if (!str) return NULL;
  str->len = len;
  for (int j = 0; j < len; j++) {
    str->data[j] = input[j];
  }
  str->data[len] = 0;
  return str;
};

void stampa_stringa(struct string_semplice *s) {
  for (int j = 0; j < s->len; j++) {
    printf("%c",s->data[j]);
  }
  printf("\n");
}

int lunghezza_stringa(struct string_semplice *s) {
  return (int)s->len;
};

void libera_stringa(struct string_semplice *s) {
  free(s);
}

int main() {
  struct string_semplice *mystr = crea_stringa("Apollineo", 9);
  stampa_stringa(mystr);
  printf("%d\n", lunghezza_stringa(mystr));
  libera_stringa(mystr);
  return 0;
}

