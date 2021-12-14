#include <stdio.h>
#include <stdlib.h>

int main()
{
 //variaveis 

  int vitoriasjogador;
  int derrotasjogador;
  int quantidadejogadores;
  int contador = 1;
  float mmr;

  printf("quantos jogadores terao o mmr analisados?\n");
  scanf("%d",&quantidadejogadores);

//repetidor - repetira o codigo para saber o mrr de jogador por jogador

for (contador; contador < (quantidadejogadores + 1); contador++)
{
  printf("quantas partidas o jogador %d teve de vitorias ?\n",contador);
  scanf("%d",&vitoriasjogador);

  printf("quantas partidas o jogador %d teve de derrotas ?\n",contador);
  scanf("%d",&derrotasjogador);

/*  calculo mmr
    vitorias valem:10 pontos
    derrotas valem:-10 pontos */

  mmr = (vitoriasjogador * 10) + (derrotasjogador * -10);
  
  printf("o calculo de mmr seu apresentado eh de: %.1f\n",mmr);
 
  printf("\n************************\n");


//condional para jogadores jogarem juntos 

//Perguntar o fabricio pq esta apresentando apenas as condiçoes 1ª e ultima (nao consegui entender onde pode estar errado)

/* quardarei  as informaçoes nos vetores  para comparalas 

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
 } */ 






}

  return 0;
}


