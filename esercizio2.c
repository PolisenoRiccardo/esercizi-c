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

// TODO: Scrivi una funzione che scambia due interi
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// TODO: Scrivi una funzione che modifica una struct tramite puntatore
void aumenta_eta(struct persona *p) {
   p->eta++;
}


// TODO: Alloca dinamicamente un array di 5 interi
// Riempilo con valori
// Stampalo
// RICORDA: free() alla fine!

int* esercizio2_2() {
  int *arr = malloc(5 * sizeof(*arr));
  int buff[5] = {1, 43, 56, 643 ,35};
  int buff_length = sizeof(buff) / sizeof(buff[0]);
  for (int j = 0; j < buff_length; j++) {
    arr[j] = buff[j];
  }
  return arr;
}


int main() {
  
// esercizio 2.1
  int a = 3;
  int b = 5;
  printf("a: %d, b: %d\n", a, b);
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
  
  struct persona pers1 = create_persona("Alberto", 42, 1.76);
  printf("%s ha %d anni.\n", pers1.nome, pers1.eta);
  aumenta_eta(&pers1);
  printf("%s ha %d anni.\n", pers1.nome, pers1.eta);

// esercizio 2.2
  int *arr1 = esercizio2_2();
  if (arr1) {
    for (int j = 0; j < 5; j++) {
      printf("%d \n",arr1[j]);
    }
    printf("\n");
    free(arr1);
  } else {
    printf("Errore"); 
  }
  return 0;
}

