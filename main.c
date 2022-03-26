#include <stdio.h>
#include <stdlib.h>
#include <matheval.h>
#include "utils.h"
#include "methods.h"
#include "mathLib.h"
#include "newton.h"

int main(void){
  // function* f = functionConstructor("-log(1-x1-x2)-log(x1)-log(x2)");
  printf("Sistema linear vem ai hein\n\n");
  sl* sis_lin = slConstructor("7*x1-log(x1)");
  double teste[] = {0.1};
  printf("value: %f\n", evaluator_evaluate(sis_lin->f->dfs[0] , sis_lin->f->vars->varAmount, sis_lin->f->vars->variables, teste));  
  showFunction(sis_lin->f);
  showVariables(sis_lin->f);
  showDerivatives(sis_lin->f);
  printf("\n");
  showHessiana(sis_lin->f);
  printf("\n\n");
  
  int n = 3;
  // double A[3][3] = {{2, 3, 4}, {1, 3, 4}, {7, 8, 7}};
  double** A = (double**) mallocMatrix(n, n, sizeof(double));
  A[0][0] = 2;
  A[0][1] = 20;
  A[0][2] = 4;
  A[1][0] = 1;
  A[1][1] = 3;
  A[1][2] = 4;
  A[2][0] = 7;
  A[2][1] = 8;
  A[2][2] = 7;
  double b[] = {5, 5, 6};
  double x[n];

  printf("\n");
  showMatrix(A, b, n);
  elGauss(A, b, n);
  retroSub(A, b, x, n);
  showMatrix(A, b, n);
  printf("\n");
  for(int i = 0; i < n; i++){
    printf("%f\n", x[i]);
  }

  matrixDestructor((void**)A);

  
  slDestructor(sis_lin);
  
  return 0;
}