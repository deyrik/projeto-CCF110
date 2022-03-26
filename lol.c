#include "lol.h"




//funçao 1 
int quantidade_jogadores(){

  printf("Serao analisadas 20 partidas de cada jogador.\n");
  printf("Quantos jogadores terao seu MMR analisados?:");
  int qtd;
  scanf("%d",&qtd);
  printf("\n");
  return qtd;
}


//funcao 2
void Guardar_Derrotas_eVitorias(int n_contador, Estrutura_Jogador vetor_jogadores[]){
  int k;
  for ( k = 0; k < n_contador; k++) //n_contador vao receber numero e jogadores. 
  {
    printf("De 20 partidas, quantas o jogador %d teve de vitoria(s)?",k+1);
    scanf("%d",&vetor_jogadores[k].vitorias);

    vetor_jogadores[k].derrotas = 20 - (vetor_jogadores[k].vitorias);
    printf("portanto o jogador %d teve %d derrota(s)!\n\n",k+1,vetor_jogadores[k].derrotas);

    vetor_jogadores[k].mmr = calcula_mmr(vetor_jogadores[k].vitorias,vetor_jogadores[k].derrotas);
  }
}


//funcao 3
int calcula_mmr(int Vit,int Der){
  int valor_mmr;
  Vit = Vit * 10;
  Der = Der * 10;
  valor_mmr = Vit - Der;
  return valor_mmr;
}


//funçao 4 
void mostra_dados(int quantia_jogadores,Estrutura_Jogador jogadores[]){

  printf("Apresentacao dos dados de cada jogador:\n\n");
  int i;
  for ( i = 0; i < quantia_jogadores; i++)
  {
    printf("Jogador %d:\n",(i+1));
    printf("Vitorias: %d\n",jogadores[i].vitorias);
    printf("Derrotas: %d\n",jogadores[i].derrotas);
    printf("o calculo do MMR apresentado e de: %d\n\n",jogadores[i].mmr);
  }
  return;
}


//funçao 5
void preenche_matrix_possibilidade_jogar_juntos (int z, int M[z][z],Estrutura_Jogador acesso_a_dados[]){

  int i,j;
  
  for ( i = 0; i < z ; i++)
  {
    for ( j = 0; j < z ; j++)
    {
      if ((i!=j)){
    
        if (acesso_a_dados[i].mmr == acesso_a_dados[j].mmr )
        {
          M[i][j] = 1;
        }

        if ((acesso_a_dados[j].mmr-40) <= acesso_a_dados[i].mmr && acesso_a_dados[i].mmr <= (acesso_a_dados[j].mmr+40))//40 pontos pra baixo ou pra cima podem 
        {//
          M[i][j] = 1;
        }

        if (acesso_a_dados[i].mmr > (acesso_a_dados[j].mmr+40) || acesso_a_dados[i].mmr < (acesso_a_dados[j].mmr-40))//41 a mais ou a menos nao podem
        { 
          M[i][j] = 0;
        }
      }

      else if (i == j)
      {
        M[i][j] = 1;
      }
    }
  }
}

//funcao 6 
void imprime_possiveis_jogadores(int n,int M[n][n]){

  int i,j;
  int contador = 0;

  printf("podem jogar juntos os players:\n");
  for ( i = 0; i < n ;  i++){
      for ( j = 0; j < n; j++)
      {

      if ((i!=j && i<j) && M[i][j] == 1)
      {
        printf("player %d e %d\n",(i+1),(j+1));
        contador++;
      }
      continue;

    }
  }

  if (contador==0)
  {
    printf("nenhum jogador ");
  }
  

  printf("\n");
  return;
}

