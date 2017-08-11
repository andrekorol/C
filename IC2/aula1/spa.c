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

Guests** create_fichas(void) {
    Guests **fichas = malloc(sizeof(Guests));
    return fichas;
}

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

bool is_valid(Guests **fichas, char *option, int *i, ull *n) {
    bool validation = false;
    if (*option == 'n' || *option == 'N') {
	if ((*n >= 1) && (*n <= *i + 1)) {
	    validation = true;
	}
    }
    else {
	for (int j = 0; j < *i; ++j) {
	    if ((ull) fichas[j]->numero_ficha == *n) {
		validation = true;
	    }
	}
    }
    return validation;
}

int get_pos(Guests **fichas, int *i, ull *n) {
    for (int j = 0; j < *i; ++j) {
	if ((ull) fichas[j]->numero_ficha == *n) {
	    return j;
	}
    }
}

int discharge(Guests **fichas, int *i) {
    char option, command;
    ull n;
    while (true) {
	if (all_discharged(fichas, i)) {
		printf("\nTodos os hóspede já estão com alta.\n");
		break;
	    }
	else {
	    while (true) {
		printf("\nEntre n para entrar com o número da ficha do(a hóspede que receberá alta )\n");
		printf("Ou i para entrar com a posição dele(a) nas fichas de cadastro(1-20): ");
		scanf(" %c", &option);
		printf("\n");
		if (option == 'n' || option == 'N' || option == 'i' || option == 'I') {
		    break;
		}
		else {
		    continue;
		}
	    }
	    if (option == 'n' || option == 'N') {
		printf("Entre o número da ficha do(a) hóspede que receberá alta: ");
		scanf(" %llu", &n);
		printf("\n");
		if (is_valid(fichas, &option, i, &n)) {
		    *fichas[get_pos(fichas, i, &n)]->alta = true;
		    printf("Entre o peso de saída (g) de %s, hóspedede número %d, ficha %llu: ",
			   fichas[get_pos(fichas, i, &n)]->nome, get_pos(fichas, i, &n) + 1, n);
		    scanf(" %Lf", &fichas[get_pos(fichas, i, &n)]->peso_final);
		    printf("\n");
		    *fichas[get_pos(fichas, i, &n)]->peso_perdido = ((fichas[get_pos(fichas, i, &n)]->peso_inicial - fichas[get_pos(fichas, i, &n)]->peso_final) / 1000.0);
		    if (*fichas[get_pos(fichas, i, &n)]->peso_perdido > 0) {
			printf("%s, hóspede de número %d, ficha %llu, perdeu %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[get_pos(fichas, i, &n)]->nome, get_pos(fichas, i, &n) + 1, n, fichas[get_pos(fichas, i, &n)]->peso_perdido, fichas[get_pos(fichas, i, &n)]->qtd_dias);
		    }
		    else if (*fichas[get_pos(fichas, i, &n)]->peso_perdido < 0) {
			printf("%s, hóspede de número %d, ficha %llu, ganhou %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[get_pos(fichas, i, &n)]->nome, get_pos(fichas, i, &n) + 1, n, *fichas[get_pos(fichas, i, &n)]->peso_perdido * (-1), fichas[get_pos(fichas, i, &n)]->qtd_dias);
		    }
		    else {
			printf("Após %hi dias de tratamento no Spa, o peso de %s, hóspede de número %d, ficha %llu não se alterou.\n\n",
			       fichas[get_pos(fichas, i, &n)]->qtd_dias, fichas[get_pos(fichas, i, &n)]->nome, get_pos(fichas, i, &n) + 1, n);
		    }
		}
		else {
		    printf("Número de ficha de hóspede inválida!\n\n");
		}
	    }
	    else {
		printf("Entre o número (1-20) do(a) hóspede que receberá alta: ");
		scanf(" %llu", &n);
		printf("\n");
		if (is_valid(fichas, &option, i, &n)) {
		    *fichas[n - 1]->alta = true;
		    printf("Entre o peso de saída (g) de %s, hóspede de número %llu, ficha %llu: ",
			   fichas[n - 1]->nome, n, fichas[n - 1]->numero_ficha);
		    scanf(" %Lf", &fichas[n - 1]->peso_final);
		    printf("\n");
		    *fichas[n - 1]->peso_perdido = ((fichas[n - 1]->peso_inicial - fichas[n - 1]->peso_final) / 1000.0);
		    if (*fichas[n - 1]->peso_perdido > 0) {
			printf("%s, hóspede de número %llu, ficha %llu, perdeu %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[n - 1]->nome, n, fichas[n - 1]->numero_ficha, fichas[n - 1]->peso_perdido, fichas[n - 1]->qtd_dias);
		    }
		    else if (*fichas[n - 1]->peso_perdido < 0) {
			printf("%s, hóspede de número %llu, ficha %llu, ganhou %Lfkg em %hi dias de tratamento no Spa.\n\n", fichas[n - 1]->nome, n, fichas[n - 1]->numero_ficha, *fichas[n - 1]->peso_perdido * (-1), fichas[n - 1]->qtd_dias);
		    }
		    else {
			printf("Após %hi dias de tratamento no Spa, o peso de %s, hóspede de número %llu, ficha %llu não se alterou.\n\n",
			       fichas[n - 1]->qtd_dias, fichas[n - 1]->nome, n, fichas[n - 1]->numero_ficha);
		    }
		}
		else {
		    printf("Número de hóspede inválido!\n\n");
		}
	    }
	    while (true) {
		printf("Deseja continuar dando alta para hóspedes[s/n]?: ");
		scanf(" %c", &command);
		printf("\n");
		if (command == 'n' || command == 'N' || command == 's' || command == 'S') {
		    break;
		}
		else {
		    printf("Comando inválido!\n\n");
		}
	    }
	    if (command == 'n' || command == 'N') {
		break;
	    }
	    /* else { */
	    /* 	continue; */
	    /* } */
	}
    }
}

int add_guest(Guests **fichas, int *i, int (*main)(void), int (*discharge)(Guests **, int *)) {
    char command;
    fichas = (Guests **)realloc(fichas, sizeof(Guests*) * (*i + 1));
    fichas[*i] = (Guests *)malloc(sizeof(Guests));
    fichas[*i]->alta = false;
    while (true) {
	if (*i == 20) {
	    printf("Número máximo de hóspedes(%d) atingido.\n", *i);
	    printf("Entre v ou V para voltar ao menu principal\n");
	    printf("Entre a ou A para dar alta à hóspedes.\n");
	    printf("Entre qualquer outro comando u CTRL-C para sair do sistema.\n");
	    scanf(" %c", &command);
	    if (command == 'r' || command == 'R') {
		for (int j = 0; j < *i; ++j) {
		    free(fichas[j]->nome);
		    for (int k = 0; k < *fichas[j]->qtd_dias; ++k) free(fichas[j]->calorias[k]);
		    free(fichas[j]);   
		}
		free(fichas);
		return main();
	    }
	    else if (command == 'v' || command == 'V') {
		break;
	    }
	    else if (command == 'a' || command == 'A') {
		return discharge(fichas, i);
	    }
	    else {
		for (int j = 0; j < *i; ++j) free(fichas[j]);
		free(fichas);
		exit(0);
	    }
	}
	else {
	    printf("Entre o número da ficha do(a) hóspede de número %d: ", *i + 1);
	    scanf(" %llu", &fichas[*i]->numero_ficha);
	    printf("\nEntre o nome do hóspede de número %d, ficha %llu: ", *i + 1, fichas[*i]->numero_ficha);
	    fgets(fichas[*i]->nome, MAX_LENGTH, stdin);
	    // Remove trailing newline , if there
	    if ((strlen(fichas[*i]->nome) > 0) && (fichas[*i]->nome[strlen(fichas[*i]->nome) - 1] == '\n'))
		fichas[*i]->nome[strlen(fichas[*i]->nome) - 1] = '\0';
	    printf("\nEntre o peso ao entrar (g) de %s, hóspede de número %d, ficha %llu: ",
		   fichas[0]->nome, *i + 1, fichas[*i]->numero_ficha);
	    scanf(" %Lf", &fichas[*i]->peso_inicial);
	    while (true) {
		printf("\nEntre a quantidade de dias de tratamento de %s, hóspede de número %d, ficha %llu: ",
		       fichas[*i]->nome, *i + 1, fichas[0]->numero_ficha);
		scanf(" %hi", &fichas[*i]->qtd_dias);
		if (*fichas[*i]->qtd_dias <= 30)
		    break;
		/* else */
		/*     continue; */
	    }
	    fichas[*i]->calorias = malloc(sizeof(ld) * *fichas[*i]->qtd_dias);
	    for (int j = 0; j < *fichas[*i]->qtd_dias; ++j) {
		printf("\nEntre a quantidade de calorias que %s, hóspede de número %d, ficha %llu pode ",
		       fichas[*i]->nome, *i + 1, fichas[*i]->numero_ficha);
		printf("ingerir no %d dia de tratamento: ", j + 1);
		scanf(" %Lf", &fichas[*i]->calorias[j]);
	    }
	}
	if (*i == 19)
	    break;
	else {
	    while (true) {
		printf("\nDeseja continuar adicionando hóspedes? [s/n]: ");
		scanf(" %c", &command);
		printf("\n");
		if (command == 's' || command == 'S' || command == 'n' || command == 'N') {
		    ++*i;
		    break;
		}
		/* else */
		/*     continue; */
	    }
	}
    }
}

int main(void) {
    char command;
    // Create pointer to main
    int (*mainPtr)(void);
    mainPtr = &main;
    // Create pointe to discharge
    int (*dischargePtr)(Guests **, int *);
    dischargePtr = &discharge;
    int index = 0;
    Guests **fichas = create_fichas();
    while (true) {
	printf("Sistema de cadastros e altas do Spa Rei Momo\n");
	printf("Entre C para cadastrar hóspedes, A para dar alta, R para reiniciar o sistema, Q ou CTRL-C para sair do sistema.\n");
	scanf(" %c", &command);
	if (command == 'C' || command == 'c')
	    add_guest(fichas, &index, mainPtr, dischargePtr);
	else if (command == 'A' || command == 'a') {
	    if (!*fichas) {
		printf("Alerta!\nNenhuma ficha de hóspede foi preenchida ainda, portanto é imposspível dar alta ");
		printf("para algum paciente.\n\n");
	    }
	    else
		discharge(fichas, &index);
     	}
	else if (command == 'R' || command == 'r') {
	    if (fichas) {
		if (*fichas) {
		    for (int i = 0; i < index; ++i) {
			free(fichas[i]->nome);
			for (int j = 0; j < *fichas[i]->qtd_dias; ++j) free(fichas[i]->calorias[j]);
			free(fichas[i]);
		    }
		}
		free(fichas);
	    }
	    return main();
	}
	else if (command == 'Q' || command == 'q')
	    break;
	else
	    printf("Comando inválido.\n");
    }
       
    if (fichas) {
	if (*fichas) {
	    for (int i = 0; i < index; ++i) {
		free(fichas[i]->nome);
		for (int j = 0; j < *fichas[i]->qtd_dias; ++j) free(fichas[i]->calorias[j]);
		free(fichas[i]);
	    }
	}
	free(fichas);
    }
    return 0;
}
