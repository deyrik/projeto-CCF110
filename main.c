  #include "lol.h"




  int main(){

  //qtd = quantidade
  
  int qtd_players;
  qtd_players = quantidade_jogadores();

  Estrutura_Jogador Dados_players[qtd_players]; 
  int matriz_jogadorx_jogador[qtd_players][qtd_players];


  Guardar_Derrotas_eVitorias(qtd_players,Dados_players);

  mostra_dados(qtd_players,Dados_players);

  preenche_matrix_possibilidade_jogar_juntos(qtd_players,matriz_jogadorx_jogador,Dados_players);

  imprime_possiveis_jogadores(qtd_players,matriz_jogadorx_jogador);


  return 0;
}





