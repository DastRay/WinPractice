#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "matrix.h"
#include "kramer.h"

int main()
{
   setlocale(LC_ALL, "RUS");

   ////////////////////////// Задание №1, нахождение обратной матрицы //////////////////////////////////////

   int rows;
   int cols;
   printf("Введите количество строк и столбцов через пробел\nУчитывайте, что для неквадратной матрицы найти обратную невозможно: ");
   scanf_s("%d %d", &rows, &cols);
   if (rows != cols)
   {
      printf("Для неквадратной матрицы найти обратную невозможно!\n");
      return -1;
   }

   double** matrix = malloc(rows * sizeof(double*)); // выделение памяти под каждый столбец
   if (!matrix)
      return 1;

   for (int i = 0; i < rows; i++)
   {
      matrix[i] = malloc(cols * sizeof(double));
      if (!matrix[i])
         return 1;
   }
   readMatrix(matrix, rows, cols);
   double** res = reverseMatrix(matrix, rows, cols); // нахождение обратной матрицы
   printf("Обратная матрица:\n");
   printMatrix(res, rows, cols);

   ////////////////////////// Задание №2, решение слау методом Крамера //////////////////////////////////////

   //int unk;
   //printf("Введите количество неизвестных: ");
   //scanf_s("%d", &unk);

   //double** A = malloc(unk * sizeof(double*)); // массив для хранения матрицы коэффициентов
   //if (!A)
   //   return 1;

   //for (int i = 0; i < unk; i++)
   //{
   //   A[i] = malloc(unk * sizeof(double));
   //   if (!A[i])
   //      return 1;
   //}

   //double* B = malloc(unk * sizeof(double)); // массив для хранения столбца свободных членов

   //readSLAYmatrix(A, B, unk); // считывание матрицы

   //CramerMethod(A, B, unk); // решение слау методом Крамера

   return 0;
}