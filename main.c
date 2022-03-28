  #include "lol.h"




  int main(){

  //qtd = qunatidade
  
  int qtd_players;
  qtd_players = qtd_jogadores();

  //variavel entra e define  tamanho de vetor e matrix:
  Estrutura_Jogador Dados_players[qtd_players]; 
  int matriz_jogadorx_jogador[qtd_players][qtd_players];


  ler_jogadores_aquivo (qtd_players,Dados_players);

  Guardar_mmr(qtd_players,Dados_players);

  mostra_dados(qtd_players,Dados_players);

  arquivar_mmr(qtd_players, Dados_players);

  preenche_matrix_possibilidade_jogar_juntos(qtd_players,matriz_jogadorx_jogador,Dados_players);

  imprime_possiveis_jogadores(qtd_players,matriz_jogadorx_jogador,Dados_players);

  arquivar_jogadores_podem_jogar(qtd_players,matriz_jogadorx_jogador,Dados_players);


  return 0;
}





