
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jogador.h"

#ifndef LOL_H
#define LOL_H




int qtd_jogadores();

void Guardar_mmr(int n, Estrutura_Jogador vetor_jogadores[]);

//nova:
void ler_jogadores_aquivo(int n, Estrutura_Jogador v[]);

//nova:
Estrutura_Jogador ler_linha_jogador(char linha[]);

int calcula_mmr(int Vit,int Der);

void mostra_dados(int quantia_jogadores,Estrutura_Jogador jogadores[]);

void arquivar_mmr(int n, Estrutura_Jogador J[]);

void preenche_matrix_possibilidade_jogar_juntos (int z, int M[z][z],Estrutura_Jogador acesso_a_dados[]);

void imprime_possiveis_jogadores(int n,int M[n][n],Estrutura_Jogador v[]);

void arquivar_jogadores_podem_jogar(int n,int M[n][n],Estrutura_Jogador v[]);






#endif /* LOL_H */
