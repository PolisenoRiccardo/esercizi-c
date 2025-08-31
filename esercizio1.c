#include <stdio.h>
#include <string.h>

struct persona {
    char nome[50];
    int eta;
    float altezza;
};

// TODO: Scrivi una funzione che:
// 1. Crei una struct persona
// 2. La riempia con dati fissi (no input utente)
// 3. La stampi


struct persona create_persona(char nome[], int eta, float altezza) {
  struct persona pers;

  for (int j = 0; j < strlen(nome); j++) {
    pers.nome[j] = nome[j];
  }
  pers.nome[strlen(nome)] = 0;
  pers.eta = eta;
  pers.altezza = altezza;
  return pers;
//  printf("Nome: %s, Età: %d, Altezza: %f\n", pers1.nome, pers1.eta, pers1.altezza);
}

void stampa_persona(struct persona pers) {
    printf("Nome: %s, Età: %d, Altezza: %f\n", pers.nome, pers.eta, pers.altezza);
}

// TODO: Crea un array di 3 persone
// Riempilo con dati diversi
// Stampa tutte le persone con un ciclo

// TODO: Scrivi queste funzioni:
// void stampa_persona(struct persona p);
// float altezza_media(struct persona persone[], int count);
// struct persona trova_piu_alto(struct persona persone[], int count);

float altezza_media(struct persona persone[], int size) {
  float media = 0;
  int array_length = size / sizeof(persone[0]);
  for (int j = 0; j < array_length; j++) {
    media += persone[j].altezza;
  }
  media /= array_length;
  return media;
}

struct persona trova_piu_alto(struct persona persone[], int size) {
  struct persona max = create_persona("max", 0, 0);
  int array_length = size / sizeof(persone[0]);
  for (int j = 1; j < array_length; j++) {
    if (persone[j].altezza > max.altezza) {
      max = persone[j];
    } 
  }
  return max;
}

int main(void) {

// Esercizio 1.1
  struct persona pers1 = create_persona("Alberto", 42, 1.76);  
  stampa_persona(pers1);

// Esercizio 1.2
  struct persona persone[] = {create_persona("Finessi", 19, 1.23),create_persona("Concadennis", 25, 1.73),create_persona("Aspiocefali", 64, 1.62)};
  int array_length = sizeof(persone) / sizeof(persone[0]);
  for (int j = 0; j < array_length; j++) {
    stampa_persona(persone[j]);
  }

// Esercizio 1.3
  printf("L'altezza media è %f\n", altezza_media(persone, sizeof(persone)));
  printf("Il più alto è ");
  stampa_persona(trova_piu_alto(persone, sizeof(persone)));
  return 0;
}
