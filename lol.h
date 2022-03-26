
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogador.h"

#ifndef LOL_H
#define LOL_H




int quantidade_jogadores();

void Guardar_Derrotas_eVitorias(int n_contador, Estrutura_Jogador vetor_jogadores[]);

int calcula_mmr(int Vit,int Der);

void mostra_dados(int quantia_jogadores,Estrutura_Jogador jogadores[]);

void preenche_matrix_possibilidade_jogar_juntos (int z, int M[z][z],Estrutura_Jogador acesso_a_dados[]);

void imprime_possiveis_jogadores(int n,int M[n][n]);


#endif /* LOL_H */
