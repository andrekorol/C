#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LENGTH 256
typedef unsigned long long ull;
typedef long double ld;

typedef struct s_guests
{
    bool *alta;
    short *qtd_dias;
    ull *numero_ficha;
    ld *peso_inicial, *peso_final, *peso_perdido, **calorias;
    char *nome;
} Guests;

bool all_discharged(Guests **fichas, int *i) {
    bool not_discharged = false;
    for (int j = 0; j < *i; ++j) {
	if (fichas[j]->alta == false) {
	    not_discharged = true;
	}
    }
    if (not_discharged) {
	return false;
    }
    else {
	return true;
    }
}

void add_guest(Guests **fichas, int *i) {
    fichas = (Guests **)realloc(fichas, sizeof(Guests*) * (*i + 1));
    fichas[*i] = (Guests *)malloc(sizeof(Guests));
    fichas[*i]->alta = false;
    fichas[*i]->numero_ficha = (ull *) 5555;
    printf("Adding guest %d\n", *i);
    ++*i;
    printf("%d\n", *i);
}

int main(int argc, char *argv[argc])
{
    Guests **fichas = malloc(sizeof(Guests));
    int index = 0;
    // If add_guest is called at least once, *fichas is not NULL,
    // hence (*!fichas) = false, i.e., (*fichas) = true
    // Otherwise, *fichas is NULL, thus (!*fichas) = true, i.e., (*fichas) = false 
    add_guest(fichas, &index);
    if (!*fichas) {
	printf("Null\n");
    }
    else {
	printf("Not Null\n");
    }
    for (int i = 0; i < 5; ++i) printf("%d\n", i);
    fichas[0]->nome = malloc(MAX_LENGTH);
    
    printf("Entre o nome: ");
    fgets(fichas[0]->nome, MAX_LENGTH, stdin);
    if ((strlen(fichas[0]->nome) > 0) && (fichas[0]->nome[strlen(fichas[0]->nome) -1] == '\n'))
	fichas[0]->nome[strlen(fichas[0]->nome) - 1] = '\0';
    printf("\n");
    printf("Nome = %s\n", fichas[0]->nome);
    free(fichas[0]->nome);
    /* int index = 0; */
    /* add_guest(fichas, &index); */
    /* if (all_discharged(fichas, &index)) { */
    /* 	printf("Yay\n"); */
    /* } */
    /* printf("%d\n", index); */
    /* /\* printf("Entre n\n"); *\/ */
    /* /\* scanf(" %llu", &fichas[0]->numero_ficha); *\/ */
    /* if ((ull) fichas[0]->numero_ficha == 5555) { */
    /* 	printf("%llu ficha\n", fichas[0]->numero_ficha);	 */
    /* } */
    /* printf("s\n"); */
    /* ld num = 4.566; */
    /* if (num > 0) { */
    /* 	printf("%Lf kg greater than 0\n", num); */
    /* } */
    return 0;
}
