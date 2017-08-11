#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct s_guests
{
    int num;
} Guests;
void add(int *i) {
    for (int j = 0; j < 5; ++j) {
	++*i;
    }

}

bool check(char *option) {
    if (*option == 'C') {
	return true;
    }
    else {
	return false;
    }
}
int main(void) {
    int index = 0;
    Guests guest;
    guest.num = 4;
    printf("%d\n", guest.num);
    add(&index);
    printf("%d\n", index);
    char *fichas = malloc(sizeof(char *));
    fichas[0] = 'C';
    if(fichas) {
	printf("Null\n");
    }
    char command = 'C';
    if (check(&command)) {
	printf("Yay\n");
    }
    
    return 0;

}
