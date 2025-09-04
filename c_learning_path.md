# Percorso di Apprendimento C - Da Base a Avanzato

## Livello 1: Fondamenti Sicuri (Settimana 1-2)

### Esercizio 1.1: Struct Semplici
```c
#include <stdio.h>

struct persona {
    char nome[50];
    int eta;
    float altezza;
};

// TODO: Scrivi una funzione che:
// 1. Crei una struct persona
// 2. La riempia con dati fissi (no input utente)
// 3. La stampi
```

**Obiettivo**: Familiarizzare con struct e inizializzazione.

### Esercizio 1.2: Array di Struct
```c
// TODO: Crea un array di 3 persone
// Riempilo con dati diversi
// Stampa tutte le persone con un ciclo
```

**Obiettivo**: Gestire collezioni di dati strutturati.

### Esercizio 1.3: Funzioni Helper
```c
// TODO: Scrivi queste funzioni:
// void stampa_persona(struct persona p);
// float altezza_media(struct persona persone[], int count);
// struct persona trova_piu_alto(struct persona persone[], int count);
```

**Obiettivo**: Modularizzare il codice, passaggio per valore vs riferimento.

---

## Livello 2: Introduzione ai Puntatori (Settimana 3)

### Esercizio 2.1: Puntatori Base
```c
// TODO: Scrivi una funzione che scambia due interi
void swap(int *a, int *b) {
    // Implementa qui
}

// TODO: Scrivi una funzione che modifica una struct tramite puntatore
void aumenta_eta(struct persona *p) {
    // Implementa qui
}
```

### Esercizio 2.2: Array Dinamici Semplici
```c
#include <stdlib.h>

// TODO: Alloca dinamicamente un array di 5 interi
// Riempilo con valori
// Stampalo
// RICORDA: free() alla fine!
```

**Obiettivo**: Prima introduzione a malloc/free senza complicazioni.

---

## Livello 3: Gestione Memoria (Settimana 4)

### Esercizio 3.1: Struct Dinamiche
```c
// TODO: Alloca dinamicamente una struct persona
// Riempila con dati
// Stampala
// Liberala correttamente
```

### Esercizio 3.2: Array Dinamico di Struct
```c
// TODO: Crea una funzione che:
// 1. Alloca un array di N struct persona
// 2. Le riempie con dati
// 3. Le stampa
// 4. Libera tutta la memoria

struct persona* crea_persone(int count) {
    // Implementa qui
}

void libera_persone(struct persona *persone) {
    // Implementa qui
}
```

---

## Livello 4: Stringhe Dinamiche Base (Settimana 5)

### Esercizio 4.1: String Length Prefix (Semplificata)
```c
struct string_semplice {
    int len;
    char *data;
};

// TODO: Implementa queste funzioni:
struct string_semplice* crea_stringa(char *input, int len);
void stampa_stringa(struct string_semplice *s);
int lunghezza_stringa(struct string_semplice *s);
void libera_stringa(struct string_semplice *s);
```

**Obiettivo**: Primo approccio alle stringhe con metadata, ma ancora con allocazioni separate.

### Esercizio 4.2: Input Sicuro
```c
// TODO: Scrivi una funzione che legge una stringa in modo sicuro
// Usa fgets() e crea una struct string_semplice
struct string_semplice* leggi_stringa_utente();
```

---

## Livello 5: Avvicinamento al Modello Antirez (Settimana 6)

### Esercizio 5.1: Struct con Flexible Array Member
```c
struct stringa_compatta {
    int len;
    char data[];  // Flexible array member!
};

// TODO: Implementa la creazione come nel codice di antirez
// Ma SENZA reference counting per ora
char* crea_stringa_compatta(char *input, int len);
```

**Obiettivo**: Capire l'allocazione in un blocco unico.

### Esercizio 5.2: Pointer Arithmetic
```c
// TODO: Data una stringa creata con l'esercizio precedente,
// scrivi funzioni che recuperano len senza passarlo come parametro
// Hint: usa il pointer arithmetic per tornare alla struct

int ottieni_lunghezza(char *s);
void stampa_con_metadata(char *s);
```

---

## Livello 6: Reference Counting (Settimana 7)

### Esercizio 6.1: Aggiungi Reference Count
```c
struct stringa_rc {
    int len;
    int refcount;
    char data[];
};

// TODO: Aggiungi reference counting alla tua implementazione
char* crea_stringa_rc(char *input, int len);
void retain_stringa(char *s);
void release_stringa(char *s);
```

### Esercizio 6.2: Magic Number e Validazione
```c
// TODO: Aggiungi magic number per validazione
// Implementa controlli di sicurezza
// Gestisci casi edge (refcount = 0, etc.)
```

---

## Livello 7: Progetto Finale

### Esercizio 7.1: Ricostruisci il Codice di Antirez
Ora prova a riimplementare completamente il sistema di prefixed length strings con:
- Allocazione in blocco unico
- Reference counting
- Magic numbers
- Validazione
- Gestione errori robusta

### Esercizio 7.2: Estendi il Sistema
Aggiungi funzionalità come:
- Concatenazione di stringhe
- Substring
- Confronto stringhe
- Resize dinamico

---

## Tips per Ogni Livello

**Compila sempre con warning:**
```bash
gcc -Wall -Wextra -std=c99 -g programma.c
```

**Usa strumenti di debug:**
```bash
valgrind ./programma  # Controlla memory leaks
```

**Test ogni funzione:**
- Crea casi di test semplici
- Prova con input edge case
- Verifica sempre malloc() success

**Non avere fretta**: Ogni livello costruisce sul precedente. Meglio padroneggiare completamente un livello prima di passare al successivo.

---

## Domande da Farti a Ogni Step

1. "Ho controllato tutti i malloc() con if (!p)?"
2. "Ogni malloc() ha il suo free()?"
3. "Ho testato con input vuoti/NULL?"
4. "Il codice compila senza warning?"
5. "Valgrind trova memory leaks?"

Inizia dall'Esercizio 1.1 e procedi con calma. Quando completi ogni esercizio, condividilo qui per feedback!
