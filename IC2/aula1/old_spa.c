#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long double ld;
typedef unsigned long long ull;

typedef struct s_guests {
    bool *alta;
    short *qtd_dias;
    ull *numero_ficha;
    ld *peso_inicial, *peso_final, *peso_perdido, *calorias;
    const char *nome;
} Guests;

Guests* create_ficha(void) {
    Guests *fichas = malloc(sizeof(Guests));
    if (NULL != fichas) {
	
    }

}

bool todos_com_alta(guest *fichas, int *index) {
    bool sem_alta = false;
    for (int i = 0; i < index; ++i) {
	if (fichas[i].alta == false) {
	    sem_alta = true;
	}
    }
    if (sem_alta) {
	return false;
    }
    else {
	return true;
    }
}

bool is_valid(guest *fichas, char *option, int *index, ull *n) {
    bool validation = false;
    if (option == 'n' || option == 'N') {
	if ((n >= 1) && (n <= index + 1))
	    validation = true;
    }
    else {
	for (int i = 0; i < index; ++i) {
	    if (fichas[i].numero_ficha == n) {
		validation = true;
	    }
	}
    }
    return validation;
}

int get_pos(guest *fichas, int *index, ull *n) {
    for (int i = 0; i < index; ++i) {
	if (fichas[i].numero_ficha == n) {
	    return i;
	}
    }
}

void alta(guest *fichas, int *index){
    char *option, command;
    ull *n;
    while (true) {
	if (todos_com_alta(fichas)) {
	    printf("\nTodos os hóspedes já estão com alta.\n");
	    break;
	}
	else {
	    while (true) {
		printf("\nEntre n para entrar com o número da ficha do(a) hóspede que receberá alta ou i para entrar ");
		printf("com a posição dele(a) nas fichas de cadastro(1-20): ");
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
		if (is_valid(fichas, option, index, n)) {
		    fichas[get_pos(fichas, index, n)].alta = true;
		    printf("Entre o peso de saída (g) de %s, hóspede de número %d, ficha %llu: "
			   fichas[get_pos(fichas, index, n)].nome, get_pos(fichas, index, n) + 1, n);
		    scanf(" %Lf", &fichas[get_pos(fichas, index, n)].peso_final);
		    printf("\n");
		    fichas[get_pos(fichas, index, n)].peso_perdido = (fichas[get_pos(fichas, index, n)].peso_inicial - fichas[get_pos(fichas, index, n)].peso_final) / 1000.0;
		    if (fichas[get_pos(fichas, index, n)].peso_perdido > 0) {
			printf("%s, hóspede de número %d, ficha %llu, perdeu %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[get_pos(fichas, index, n)].nome, get_pos(fichas, index, n) + 1, n, fichas[get_pos(fichas, index, n)].peso_perdido, fichas[get_pos(fichas, index, n)].qtd_dias);
		    }
		    else if (fichas[get_pos(fichas, index, n)].peso_perdido < 0) {
			printf("%s, hóspede de número %d, ficha %llu, ganhou %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[get_pos(fichas, index, n)].nome, get_pos(fichas, index, n) + 1, n, fichas[get_pos(fichas, index, n)].peso_perdido * (-1.0), fichas[get_pos(fichas, index, n)].qtd_dias);
		    }
		    else {
			printf("Após %hi dias de tratamento no Spa, o peso de %s, hóspede de número %d, ficha %llu não se alterou.\n\n",
			       fichas[get_pos(fichas, index, n)]qtd_dias, fichas[get_pos(fichas, index, n)].nome, get_pos(fichas, index, n) + 1, n);
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
		if (is_valid(fichas, option, index, n)) {
		    fichas[n - 1].alta = true;
		    printf("Entre o peso de saída (g) de %s, hóspede de número %llu, ficha %llu: ");
		    scanf(" Lf", &fichas[n - 1].peso_final);
		    printf("\n");
		    fichas[n - 1].peso_perdido = (fichas[n - 1].peso_inicial - fichas[n - 1].peso_final) / 1000.0;
		    if (fichas[n - 1].peso_perdido > 0) {
			printf("%s, hóspede de número %llu, ficha %llu, perdeu %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[n - 1].nome, n, fichas[n - 1].numero_ficha, fichas[n - 1].peso_perdido, fichas[n - 1].qtd_dias);
		    }
		    else if (fichas[n - 1].peso_perdido < 0) {
			printf("%s, hóspede de número %llu, ficha %llu, ganhou %Lfkg em %hi dias de tratamento no Spa.\n\n",
			       fichas[n - 1].nome, n, fichas[n - 1].numero_ficha, fichas[n - 1].peso_perdido * (-1), fichas[n - 1].qtd_dias);
		    }
		    else {
			printf("Após %hi dias de tratamento no Spa, o peso de %s, hóspede de número %d, ficha %llu não se alterou.\n\n",
			       fichas[n - 1].qtd_dias, fichas[n - 1].nome, n, fichas[n - 1].numero_ficha);
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
	    else {
		continue;
	    }
	}
    }
}

void cadastro(guest *fichas, int *index) {
    char command;
    while (true) {
	if (index == 20) {
	    printf("Número máximo de hóspedes(%d) atingido.\n", index);
	    printf("Entre r ou R para apagar todos os dados cadastrados e reiniciar o sistema.\n");
	    printf("Entre v ou V para voltar ao menu principal\n");
	    printf("Entre a ou A para dar alta à hóspedes.\n");
	    printf("Entre qualquer outro comando ou CTRL-C para sair do sistema.\n");
	    scanf(" %c", &command);
	    if (command == 'r' || command == 'R') {
		free(fichas);
		return main();
	    }
	    else if (command == 'v' || command == 'V') {
		break;
	    }
	    else if (command == 'a' || command == 'A') {
		return alta(fichas, index);
	    }
	    else {
		free(fichas);
		exit(0);
	    }
	}
	else {
	    printf("Entre o número da ficha do(a) hóspede de número %d\n", index + 1);
	    if (index + 1 == 1) {
		fichas  = (guest *)malloc(sizeof(guest) * index + 1);
	    }
	    else {
		fichas = (guest *)realloc(fichas, sizeof(guest) * index + 1);
	    }
	    scanf(" %llu", &fichas[(int) index].numero_ficha);
	    printf("Entre o nome do hóspede de número %d, ficha %llu:\n", index + 1, fichas[(int) index].numero_ficha);
	    scanf(" %s", &fichas[(int) index].nome);
	    printf("Entre o peso ao entrar (g) de %s, hóspede de número %d, ficha %llu:\n",
		   fichas[(int) index]nome, index + 1, fichas[(int) index].numero_ficha);
	    scanf(" %Lf", &fichas[(int) index].peso_inicial);
	    printf("Entre a quantidade de dias de tratamento de %s, hóspede de número %d, ficha %llu:\n",
		   fichas[(int) index].nome, index + 1, fichas[(int) index].numero_ficha);
	    scanf(" %hi", &fichas[(int) index].qtd_dias);
	    for (int i = 0; i < fichas[(int) index].qtd_dias; ++i) {
		printf("Entre a quantidade de calorias que %s, hóspede de número %d, ficha %llu pode ");
		printf("ingerir no %d° dia de tratamento:\n",
		       fichas[(int) index].nome, index + 1, );
		scanf(" %Lf", &fichas[(int) index].calorias[i]);
	    }
	}
	if (index == 20) {
	    break;
	}
	else {
	    while (true) {
		printf("Deseja continuar adicionando hóspedes? [s/n]: ");
		scanf(" %c", &command);
		printf("\n");
		if (command == 's' || command == 'S' || command == 'n' || command == 'N') {
		    index++;
		    break;
		}
		else {
		    continue;
		}
	    }
	    if (command == 'n' || command == 'N') {
		break;
	    }
	    else {
		continue;
	    }
	}
    }
}

int main(void) {
    Guests *fichas = (Guests *)malloc(sizeof(Guests) * 20);
    int *index = (int *)malloc(sizeof(int));
    char command;
    int *index = 0;
    while (true) {
	 printf("Sistema de cadastros do Spa Rei Momo\n");
	 printf("Entre C para cadastrar hospédes, A para dar alta, R para reiniciar o sistema, Q ou CTRL-C para sair do sistema.\n");
	 scanf(" %c", &command);
	 if (command == 'C') {
	     cadastro(fichas, index);
	 }
	 else if (command == 'A') {
	     if (!fichas) {
		 printf("Alerta!\nNenhuma ficha de hóspede foi preenchida ainda, portanto é impossível dar alta ");
		 printf("para algum paciente.\n\n");
	     }
	     alta(fichas, index);
	 }
	 else if (command == 'R') {
	     printf("\n\n");
	     if (fichas) {
		 free(fichas);
	     }
	     return main();
	 }
	 else if (command == 'Q') {
	     break;
	 }
	 else {
	     printf("Comando inválido.\n");
	 }
    }
    if (fichas) {
        free(fichas);
    }
    return 0;
}
