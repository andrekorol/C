#include <stdio.h>
int main(void)
{
    float altura_degrau, altura_desejada, degraus, int_part, dec_part;
    printf("Entre a altura de cada degrau(em metros): \n");
    scanf("%f", &altura_degrau);
    printf("Entre, em metros, a altura que você deseja alcançar: \n");
    scanf("%f", &altura_desejada);
    degraus = altura_desejada / altura_degrau;
    int_part = (int)altura_desejada;
    dec_part = altura_desejada - int_part;

    if (dec_part > 0)
	printf("Para alcançar a altura de %f metros você precisará subir %.0f degraus da escada\n", altura_desejada, int_part + 1);
    
    else
	printf("Para alcançar a altura de %.0f metros você precisará subir %.0f degraus da escada\n", altura_desejada, degraus);
	
    return 0;
}
