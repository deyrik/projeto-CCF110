#include <stdio.h>
#include <stdlib.h>

int main()
{
 //1° modo de declarar variavel, linha a linha

  int vjogador1;
  int vjogador2;
  int vjogador3;


//2º modo de declarar variavel,na mesma linha
//tipo variavelA,B,C

  int djogador1,djogador2,djogador3;
  
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

   float mmr1;
   float mmr2;
   float mmr3;

  mmr1= vjogador1*10 + djogador1*-10;
  mmr2= vjogador2*10 + djogador2*-10;
  mmr2= vjogador3*10 + djogador3*-10;



//condional para jogadores jogarem juntos 

//Perguntar o fabricio pq esta apresentando apenas as condiçoes 1ª e ultima (nao consegui entender onde pode estar errado)


  if (mmr1==mmr2 && mmr2!= mmr3)
  {
    printf("apenas jogadores 1 e 2 podem jogar juntos\n");
  }

 if (mmr2==mmr3 && mmr2!=mmr1)
 {
    printf("apenas jogadores 2 e 3 podem jogar juntos\n");
 }
  
   if (mmr1==mmr3 && mmr1!=mmr2)
 {
    printf("apenas jogadores 1 e 3 podem jogar juntos\n");
 }

 if (mmr1==mmr2==mmr3)
 {
   printf("partida compativel para todos jogadores\n");
 }
 
 if (mmr1!=mmr2!=mmr3)
 {
   printf("balanceamento nao compativel para o ranking dos jogadores\n");
 }
 
  

//teste:
printf("%d",vjogador1);
printf("%d",djogador1);

printf("%d",vjogador2);
printf("%d",djogador2);

printf("%d",vjogador3);
printf("%d",djogador3);

printf("%f",mmr1);
printf("%f",mmr2);
printf("%f",mmr3);




  
  
  





















  return 0;
}

