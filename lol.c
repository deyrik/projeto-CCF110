  #include <stdio.h>
  #include <stdlib.h>

  int main(){

  int vitoriasjogador, derrotasjogador, quantidadejogadores;
  int contador = 0;
  int i,j;
  float mmr;


  printf("quantos jogadores terao o mmr analisados?\n");
  scanf("%d",&quantidadejogadores);
  printf("No total precisam ser analisadas 20 partidas de cada jogador\n");

  int vetormmrs[quantidadejogadores];//guarda os mmrs 


  for (contador; contador < quantidadejogadores ; contador++){

    printf("quantas partidas o jogador %d teve de vitorias ?\n",contador+1);
    scanf("%d",&vitoriasjogador);

    printf("quantas partidas o jogador %d teve de derrotas ?\n",contador+1);
    scanf("%d",&derrotasjogador);

    /*  calculo mmr
    vitorias valem:10 pontos
    derrotas valem:-10 pontos */
    mmr = (vitoriasjogador * 10) + (derrotasjogador * -10);
    vetormmrs[contador]=mmr;
  
    printf("o calculo de seu mmr apresentado eh de: %.1f\n",mmr);
    printf("\n************************\n");
  }


  float matriz_jogadorx_jogador[quantidadejogadores][quantidadejogadores];

  for ( i = 0; i < quantidadejogadores ; i++){ 
    for ( j = 0; j < quantidadejogadores ; j++) {
    
      if ((i!=j)){
    
        if (vetormmrs[i]==vetormmrs[j] )
        {
          matriz_jogadorx_jogador[i][j]=1;
        }
        if ((vetormmrs[j]-50)<vetormmrs[i] && vetormmrs[i]<(vetormmrs[j]+50) ) //49 pontos pra baixo ou pra cima podem 
        {
          matriz_jogadorx_jogador[i][j]=1;
        }
        if (vetormmrs[i]>(vetormmrs[j]+50) || vetormmrs[i]<(vetormmrs[j]-50) ) //50 a mais ou a menos nao podem 
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

  printf("podem jogar juntos os players:\n");

  for ( i = 0; i < quantidadejogadores; i++){
    for ( j = 0; j < quantidadejogadores; j++){

      if (i!=j && i<j && matriz_jogadorx_jogador[i][j]==1)
      {
        printf("player %d e %d\n",i,j);
      }
    
    }
  }



  printf("\n");


  return 0;
}

//rodou como esperado. 
