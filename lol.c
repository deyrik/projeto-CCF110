#include "lol.h"


//funçao 1 - correta
int qtd_jogadores(){

  //printf("Serao analisadas 20 partidas de cada jogador.\n");
  printf("Quantos jogadores terao seu MMR analisados?(mesmo tanto que existe no arquivo, no caso 6):");
  int qtd;
  scanf("%d",&qtd);
  printf("\n");
  return qtd;
}


//funçao 2 - ler arquivo e chama F() p/ salvar alguns dados nos structs
void ler_jogadores_aquivo(int n, Estrutura_Jogador v[]){

  //n = numero de jogadores;
  //v[] = vetor de Estrutas de jogadores 
  int i;
  FILE *arquivo_jogadores;
  if ((arquivo_jogadores = fopen("dados_jogadores.txt","r"))==NULL)
  {
    printf("erro ao tentar encontrar aquivo");
    return;
  }
  
  char salva_linha[30];
  for ( i = 0; i < n ; i++)
  {
    fflush(stdin);
    fgets(salva_linha,30,arquivo_jogadores);//onde quero armazenar, tamanho max do local de memoria,*arquivo
    fflush(stdin);
    Estrutura_Jogador  retorno_jogador;
    retorno_jogador = ler_linha_jogador(salva_linha);
    v[i] = retorno_jogador;
    //teste
    printf("Jogador: %s\n",retorno_jogador.apelido);
    printf("Vitorias: %d\n",retorno_jogador.vitorias);
    printf("Derrotas: %d\n",retorno_jogador.derrotas);
    printf("\n");
    fflush(stdin);
  }
  
  fclose(arquivo_jogadores);
  return;
}

//funçao 2.1. entrada por arquivo das:  apelido do jogador/vitorias/derrotas
Estrutura_Jogador ler_linha_jogador(char linha[]){
  
  Estrutura_Jogador jogador_ref;
  int i=0; //percorre a linha lida do arquivo
  int cont = 0; //percorre apelido e numeros da estrutura {ESTRUTURA JOGADOR == {NICK,VITORIA,DERROTA }}

  printf("linha = %s\n",linha);

  fflush(stdin);
   while ( linha[i] != ';')
  { 
    jogador_ref.apelido[cont] = linha[i];
    cont++; 
    i++;
  }

  i++; //pula o ';'
  char numero_vitorias[5];
  cont = 0 ;
 fflush(stdin);
    while (linha[i] != ';')
  {
     numero_vitorias[cont] = linha[i];
     cont++;
     i++;
  }

  //converter a string de vitorias em um inteiro de vitorias 
  jogador_ref.vitorias = atoi(numero_vitorias);

  i++; //pula outro ';'
  char numero_derrotas[5];
  cont = 0;
 fflush(stdin);
  while ( linha[i] != ';')
  {

    numero_derrotas[cont]=linha[i];
    i++;
    cont++;
  }

  //converter a string de derrotas em um inteiro de derrotas 
  jogador_ref.derrotas = atoi(numero_derrotas);

  return jogador_ref;
}

//funcao 2.1.1- salva nos structs o mmr 
void Guardar_mmr(int n, Estrutura_Jogador vetor_jogadores[]){
  int i;
  //n = nº de jogadores 

  for ( i = 0; i < n; i++) 
  {
    //printf("De 20 partidas, quantas o jogador %d teve de vitoria(s)?",i+1);
    //scanf("%d",&vetor_jogadores[i].vitorias);

    //vetor_jogadores[i].derrotas = 20 - (vetor_jogadores[i].vitorias);
    //printf("portanto o jogador %d teve %d derrota(s)!\n\n",i+1,vetor_jogadores[i].derrotas);

    vetor_jogadores[i].mmr = calcula_mmr(vetor_jogadores[i].vitorias,vetor_jogadores[i].derrotas);
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
    printf("nickname: %s\n",jogadores[i].apelido);
    printf("Vitorias: %d\n",jogadores[i].vitorias);
    printf("Derrotas: %d\n",jogadores[i].derrotas);
    printf("o calculo do MMR apresentado e de: %d\n\n",jogadores[i].mmr);
  }

  return;
}

//funçao 5
void arquivar_mmr(int n, Estrutura_Jogador J[]){

  // n= numero de jogadores 

  FILE *arquivo_mmrs;
  if ((arquivo_mmrs = fopen("mmrs.txt","w"))==NULL)
  {
    printf("nao possivel abrir o arquivo");
  }

 int i;

  for ( i = 0; i < n ; i++)
  {
    fprintf(arquivo_mmrs,"mmr jogador %s: %d\n",J[i].apelido,J[i].mmr);
  }

  fclose(arquivo_mmrs);
}

//funçao 7
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


//funcao 8 
void imprime_possiveis_jogadores(int n,int M[n][n],Estrutura_Jogador v[]){

  
  int i,j;
  int contador = 0;

  printf("possibilidades para jogar juntos, players:\n");
  for ( i = 0; i < n ;  i++){
      for ( j = 0; j < n; j++)
      {

      if ((i!=j && i<j) && M[i][j] == 1)
      {
        printf("player %d: %s e player %d: %s\n",(i+1),v[i].apelido,(j+1),v[j].apelido);
        contador++;
      }
      continue;

    }
  }

  if (contador==0)
  {
    printf("nenhum player pode jogar junto ");
  }
  

  printf("\n");
  return;
}

void arquivar_jogadores_podem_jogar(int n,int M[n][n],Estrutura_Jogador v[]){

  int i,j;
  int contador=0;

  FILE *arquivo_jogador_on;
  if (( arquivo_jogador_on = fopen("compatibilidade","w")) ==NULL)
  {
    printf("nao possivel foi abrir. ");
  }
  
    for ( i = 0; i < n ;  i++){
      for ( j = 0; j < n; j++)
      {

      if ((i!=j && i<j) && M[i][j] == 1)
      {
        fprintf(arquivo_jogador_on,"player %d: %s e player %d: %s\n",(i+1),v[i].apelido,(j+1),v[j].apelido);
        contador++;
      }
      continue;

    }
  }

  if (contador==0)
  {
    fprintf(arquivo_jogador_on,"nenhum jogador pode jogar junto, mmrs incompativeis");
  }
  

  fclose(arquivo_jogador_on);
  return;

}