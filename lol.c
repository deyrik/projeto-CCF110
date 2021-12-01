#include <stdio.h>
#include <stdlib.h>

int main()
{
 //1° modo de declarar variavel, linha a linha

  int vjogador1;
  int vjogador2;
  int vjogador3;

//2º modo de declarar variavel,na mesma linha

  int djogador1; int djogador2; int djogador3;
  
  printf("quantas partidas o jogador 1 teve de vitorias ?\n");
  scanf("%d",&vjogador1);
  printf("quantas partidas o jogador 1 teve de derrotas ?\n");
  scanf("%d",&djogador1);
  printf("************************\n");

  printf("quantas partidas o jogador 2 teve de vitorias ?\n");
  scanf("%d",&vjogador2);
  printf("quantas partidas o jogador 2 teve de derrotas ?\n");
  scanf("%d",&djogador2);
  printf("************************\n");

  printf("quantas partidas o jogador 3 teve de vitorias ?\n");
  scanf("%d",&vjogador3);
  printf("quantas partidas o jogador 3 teve de derrotas ?\n");
  scanf("%d",&djogador3);
  printf("************************\n");

/* calculo mmr
    vitorias valem:10 pontos
    derrotas valem:-10 pontos 
    ....
    */

//teste:
printf("%d",vjogador1);
printf("%d",djogador1);

printf("%d",vjogador2);
printf("%d",djogador2);


  
  
  





















  return 0;
}

