  #include <stdio.h>
  #include <stdlib.h>


  //abreviações usadas: 
  // qtd = quantidade

  typedef struct tipojogador {

    int vitorias;
    int derrotas;
    float mmr; 

  }Tipo_Jogador;


  int main(){

  int qtd_jogadores;
  int contador = 0;
  int i,j;
  float mmr;


  printf("quantos jogadores terao o mmr analisados?\n");
  scanf("%d",&qtd_jogadores);
  printf("No total precisam ser analisadas 20 partidas de cada jogador\n");

  int vetormmrs[qtd_jogadores];//guarda os mmrs 
  Tipo_Jogador Jogador[qtd_jogadores];


  for(contador; contador < qtd_jogadores ; contador++){

    printf("De 20 partidas, quantas o jogador %d teve de vitorias ?\n",contador+1);
    scanf("%d",&Jogador[contador].vitorias);
    
    Jogador[contador].derrotas = 20 - Jogador[contador].vitorias;

    printf("portanto o jogador %d teve %d  de derrotas !\n",contador+1,Jogador[contador].derrotas);
   

    /*  calculo mmr
    vitorias valem:10 pontos
    derrotas valem:-10 pontos */

    mmr = (Jogador[contador].vitorias * 10) + (Jogador[contador].derrotas * (-10)); //posso apagar essa linha e usar o caluclo direto na debaixo. (-1 variavel)
    Jogador[contador].mmr = mmr;
  
    printf("o calculo de seu mmr apresentado eh de: %.1f\n",mmr);
    printf("\n************************\n");
  }


  float matriz_jogadorx_jogador[qtd_jogadores][qtd_jogadores];

  for ( i = 0; i < qtd_jogadores ; i++){ 
    for ( j = 0; j < qtd_jogadores ; j++){
    
      if ((i!=j)){
    
        if (Jogador[i].mmr==Jogador[j].mmr ){// como estava -> vetormmrs[i]==vetormmrs[j]
          matriz_jogadorx_jogador[i][j]=1;
        }
        if ((Jogador[j].mmr-50)<Jogador[i].mmr && Jogador[i].mmr<(Jogador[j].mmr+50) ){//49 pontos pra baixo ou pra cima podem ...... como estava ->(vetormmrs[j]-50)<vetormmrs[i] && vetormmrs[i]<(vetormmrs[j]+50)
          matriz_jogadorx_jogador[i][j]=1;
        }
        if (Jogador[i].mmr > (Jogador[j].mmr+50) || Jogador[i].mmr < (Jogador[j].mmr-50) ){ //50 a mais ou a menos nao podem     como estava -> vetormmrs[i]>(vetormmrs[j]+50) || vetormmrs[i]<(vetormmrs[j]-50)
          matriz_jogadorx_jogador[i][j]=0;
        }
      }

      if (i==j){
         matriz_jogadorx_jogador[i][j]=1;
      }
    }
  
}

  printf("podem jogar juntos os players:\n");

  for ( i = 0; i < qtd_jogadores; i++){
    for ( j = 0; j < qtd_jogadores; j++){

      if (i!=j && i<j && matriz_jogadorx_jogador[i][j]==1){
        printf("player %d e %d\n",(i+1),(j+1));
      }
    
    }
  }



  printf("\n");


  return 0;
}

//rodou como esperado. 
