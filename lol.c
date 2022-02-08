#include <stdio.h>
#include <stdlib.h>

int main()
{
//variaveis 

  int vitoriasjogador;
  int derrotasjogador;
  int quantidadejogadores;
  int contador = 1;
  int i ; //usado para percorrer vetor e comparar mmr
  int j ; //usado para percorrer vetor e comparar mmr
  float mmr;


  printf("quantos jogadores terao o mmr analisados?\n");
  scanf("%d",&quantidadejogadores);


//vetores /arrays
  int vetormmrs[quantidadejogadores];


//repetidor - repetira o codigo para saber o mrr de jogador por jogador

  printf("No total precisam ser analisadas 20 partidas de cada jogador\n");

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

  vetormmrs[contador]=mmr;
  
  printf("o calculo de mmr seu apresentado eh de: %.1f\n",mmr);
 
  printf("\n************************\n");

}


//condional para jogadores jogarem juntos 

/*
mmr igual podem jogar junto !!! OK 

mmr entre: (N-50) ou (N+50) !!! OK

mmr acima de 50 de diferença ou abaixo de 50 de diferença - nao podem !!! OK
*/


/*
for ( i = 1; i < (quantidadejogadores + 1) ; i++){
  for ( j = 1; j < (quantidadejogadores + 1); j++) {
    
    if ((i!=j)){
      
    
    
    if (vetormmrs[i]==vetormmrs[j] )
    {
      printf("jogador %d pode jogar com jogador %d.\n",i,j);
      break;
    }
    if ((vetormmrs[j]-50)<vetormmrs[i] && vetormmrs[i]<(vetormmrs[j]+50) )
    {
      printf("jogador %d pode jogar com jogador %d.\n",i,j);
    }
    if (vetormmrs[i]>(vetormmrs[j]+50) || vetormmrs[i]<(vetormmrs[j]-50) )
    {
      printf("jogador %d nao podem jogar com jogador %d devido a despariedade de habilidade.\n",i,j);
    }
   }
  }
}
*/
//adicionando uma matriz, jogador x jogador, onde o encontro de cada jogador representa a possobilidade de jogarem juntos(1) ou nao jogarem juntos 0.

 float matriz_jogadorx_jogador[quantidadejogadores][quantidadejogadores];

 for ( i = 1; i < (quantidadejogadores + 1) ; i++){
  for ( j = 1; j < (quantidadejogadores + 1); j++) {
    
    if ((i!=j)){
    
    if (vetormmrs[i]==vetormmrs[j] )
    {
      matriz_jogadorx_jogador[i][j]=1;
      break;
    }
    if ((vetormmrs[j]-50)<vetormmrs[i] && vetormmrs[i]<(vetormmrs[j]+50) )
    {
      matriz_jogadorx_jogador[i][j]=1;
    }
    if (vetormmrs[i]>(vetormmrs[j]+50) || vetormmrs[i]<(vetormmrs[j]-50) )
    {
      matriz_jogadorx_jogador[i][j]=0;
    }
   }

  if (i==j)
  {
    matriz_jogadorx_jogador[i][j]=1;
  }
  
  }
  
}




printf("\n");

/*testando se vetor de mmr ta funcionando 100% 

for (contador=1; contador < (quantidadejogadores + 1); contador++)
{
  printf("%d,",vetormmrs[contador]);
}
*/

  return 0;
}



