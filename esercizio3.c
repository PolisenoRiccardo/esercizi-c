#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct persona {
    char nome[50];
    int eta;
    float altezza;
};

struct persona create_persona(char nome[], int eta, float altezza) {
  struct persona pers;

  for (int j = 0; j < (int)strlen(nome); j++) {
    pers.nome[j] = nome[j];
  }
  pers.nome[strlen(nome)] = 0;
  pers.eta = eta;
  pers.altezza = altezza;
  return pers;
}

void stampa_persona(struct persona pers) {
    printf("Nome: %s, Età: %d, Altezza: %f\n", pers.nome, pers.eta, pers.altezza);
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void aumenta_eta(struct persona *p) {
   p->eta++;
}

struct persona* esercizio3_1() {
  struct persona *p = malloc(sizeof(*p));
  if (!p) return NULL;
  strcpy(p->nome, "Mario");
  p->eta = 37;
  p->altezza = 1.85;
  return p;
} 

// TODO: Alloca dinamicamente una struct persona
// Riempila con dati
// Stampala
// Liberala correttamente

// TODO: Crea una funzione che:
// 1. Alloca un array di N struct persona
// 2. Le riempie con dati
// 3. Le stampa
// 4. Libera tutta la memoria

struct persona* esercizio3_2() {
  struct persona *people = malloc(sizeof(struct persona)*3);
  if (!people)  return NULL;
  people[0] = create_persona("Luigi", 29, 1.52);  
  people[1] = create_persona("Francesco", 38, 1.67);  
  people[2] = create_persona("Otto", 18, 1.90);  
  return people; 
}

int main() {
// esercizio 3.1
  struct persona *pers1 = esercizio3_1();
  stampa_persona(*pers1);
  free(pers1);

// esercizio 3.2
  struct persona *persone = esercizio3_2();
  for (int j = 0; j < 3; j++) {
    stampa_persona(*(persone+j));
  }
  free(persone);
  return 0;
}

