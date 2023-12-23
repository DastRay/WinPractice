#include <stdio.h>
#include <stdlib.h>

#include "kramer.h"
#include "matrix.h"

void readSLAYmatrix(double** A_, double* B_, int n_)
{
   printf("Введите коэффиценты СЛАУ (A) и столбец свободных членов (B):\n");
   for (int i = 0; i < n_; i++)
   {
      for (int j = 0; j < n_; j++)
      {
         printf("A[%d][%d]: ", i + 1, j + 1);
         scanf_s("%lf", &A_[i][j]);
      }
      printf("B[%d]: ", i + 1);
      scanf_s("%lf", &B_[i]);
   }
}

void printSLAYmatrix(double** A_, double* B_, int n_)
{
   for (int i = 0; i < n_; i++)
   {
      for (int j = 0; j < n_; j++)
      {
         printf("%8.3lf  ", A_[i][j]);
      }
      printf("| %8.3lf\n", B_[i]);
   }
   printf("\n");
}

void replaceColumn(double** matrix_, int rows_, int newCols_, double* newColumn_)
{

   for (int i = 0; i < rows_; i++) 
   {
      matrix_[i][newCols_] = newColumn_[i];
   }
}

void CramerMethod(double** A_, double* B_, int n_)
{  
   printf("\n");
   printf("Расширенная матрица AB:\n");
   printSLAYmatrix(A_, B_, n_);
   printf("Решение СЛАУ методом Крамера:\n");

   double** copy_A = copyMatrix(A_, n_, n_);
   double det = determinant(copy_A, n_);

   if (det == 0)
   {
      printf("Определитель равен нулю, СЛАУ имеет бесконечное количество решений или не имеет решений.\nВоспользуйтесь другим способом для решения.\n");
      return -1;
   }
   printf("Определитель матрицы А равен: %.4lf\n", det);

   double* res = malloc(n_ * sizeof(double));

   
   for (int k = 0; k < n_; k++)
   {
      double** copy = copyMatrix(A_, n_, n_);
      replaceColumn(copy, n_, k, B_);
      printf("Дельта %d: \n", k + 1);
      printMatrix(copy, n_, n_);

      double determ = determinant(copy, n_);
      printf("Определитель дельты %d = %.3lf\n", k + 1, determ);
      res[k] = determ / det;
   }

   printf("\n");
   printf("Решение системы:\n");
   for (int i = 0; i < n_; i++)
   {
      printf("x[%d] = %5.3lf\n", i + 1, res[i]);
   }
}