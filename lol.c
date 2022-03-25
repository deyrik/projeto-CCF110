  #include <stdio.h>
  #include <stdlib.h>


typedef struct tipojogador {

  int vitorias;
  int derrotas;
  int mmr; 

}Estrutura_Jogador;




//funçao 1 
int quandidade_de_jogadores();

//funcao 2
int calcula_mmr(int Vit,int Der);

//funcao 3 
void Salva_Derrotas_eVitorias(int n_contador, Estrutura_Jogador vetor_jogadores[]);

//funçao 4
void preenche_matrix_possibilidade_jogar_juntos (int z, int M[z][z],Estrutura_Jogador acesso_a_dados[]);

//funcao 5 
void imprime_possiveis_jogadores(int n,int M[n][n]);



  int main(){

  int qtd_jogadores;
  int i,j;
  
  qtd_jogadores = quandidade_de_jogadores();

  Estrutura_Jogador Dados_players[qtd_jogadores];
  int matriz_jogadorx_jogador[qtd_jogadores][qtd_jogadores];

  Salva_Derrotas_eVitorias(qtd_jogadores,Dados_players);

  preenche_matrix_possibilidade_jogar_juntos(qtd_jogadores,matriz_jogadorx_jogador,Dados_players);

  imprime_possiveis_jogadores(qtd_jogadores,matriz_jogadorx_jogador);


  return 0;
}


//rodou como esperado. 

//FUNÇÕES:


//funçao 1 
int quandidade_de_jogadores(){

  int quantidade;
  printf("quantos jogadores terao o mmr analisados?\n");
  scanf("%d",&quantidade);
  printf("No total precisam ser analisadas 20 partidas de cada jogador\n");
  return quantidade;
}

//funcao 2
int calcula_mmr(int Vit,int Der){
  int valor_mmr,vitoria,derrota;
  vitoria = Vit * 10;
  derrota = Der * 10;
  valor_mmr = vitoria - derrota;
  printf("vitorias: %d\n",vitoria);
  printf("derrotas: %d\n",derrota);
  printf("o calculo de seu mmr apresentado eh de: %d\n",valor_mmr);
  printf("\n************************\n");
  return valor_mmr;
}

//funcao 3 
void Salva_Derrotas_eVitorias(int n_contador, Estrutura_Jogador vetor_jogadores[]){
  int k;
  for ( k = 0; k < n_contador; k++) //n_contador vao receber numero e jogadores. 
  {
    printf("De 20 partidas, quantas o jogador %d teve de vitoria(s)?\n",k+1);
    scanf("%d",&vetor_jogadores[k].vitorias);

    vetor_jogadores[k].derrotas = 20 - (vetor_jogadores[k].vitorias);
    printf("portanto o jogador %d teve %d derrota(s)!\n",k+1,vetor_jogadores[k].derrotas);

    vetor_jogadores[k].mmr = calcula_mmr(vetor_jogadores[k].vitorias,vetor_jogadores[k].derrotas);

  }
}

//funçao 4

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

//funcao 5 

void imprime_possiveis_jogadores(int n,int M[n][n]){

  int i,j;//contadores
  printf("podem jogar juntos os players:\n");

  for ( i = 0; i < n ;  i++){
    for ( j = 0; j < n; j++){

      if ((i!=j && i<j) && M[i][j] == 1)
      {
        printf("player %d e %d\n",(i+1),(j+1));
      }
    
    }
  }
  printf("\n");
  return;
}
