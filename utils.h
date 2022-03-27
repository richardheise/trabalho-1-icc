/**
 *  Arquivo com os cabeçalhos das funções de utils.c
 *  Gabriel Lüders (GRR20190172)
 *  Richard Fernando Heise Ferreira (GRR20191053) 
 **/

#ifndef UTILS_H
#define UTILS_H

#include<time.h>
#include <stdio.h>

/**
 * Recebe int size
 * Recebe char* error 
 * Função para conferir se uma matriz foi alocada
 * Retorna um ponteiro para uma região alocada
 */
void* mallocCheck(int size, char* error);

/**
 * Recebe int lin
 * Recebe int col
 * Função para alocar uma matriz na memória
 * Retorna uma matriz alocada dinamicamente
 */
void** mallocMatrix(int lin, int col, unsigned int varSize);

/**
 * Recebe double** mat
 * Função para destruir uma matriz
 */
void matrixDestructor(void** mat);

/**
 * Retorna o tempo atual
 */
double timestamp(void);

void parseArgs(int argc, char** argv, const char *args, FILE** valueO);

double norm(double* vector, unsigned int n);

#endif