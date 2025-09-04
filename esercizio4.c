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

// TODO: Scrivi una funzione che legge una stringa in modo sicuro
// Usa fgets() e crea una struct string_semplice
struct string_semplice* leggi_stringa_utente() {
  char str[100];
  if (fgets(str, 100, stdin) != NULL) {
    int len = strlen(str);
    struct string_semplice *mystr = crea_stringa(str, len);
    return mystr;
  } 
  return NULL;
}

int main() {
  struct string_semplice *mystr = crea_stringa("Apollineo", 9);
  stampa_stringa(mystr);
  printf("%d\n", lunghezza_stringa(mystr));
  libera_stringa(mystr);
  struct string_semplice *newstr = leggi_stringa_utente();
  stampa_stringa(newstr);
  libera_stringa(newstr);
  return 0;
}

