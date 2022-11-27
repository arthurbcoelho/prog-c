#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int a[50];
int count = 0;
bool printSolution = 0;

int isSafe(int pos)
{
    for (int i = 1; i < pos; i++)
    {
        if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
        {
            return 0;
        }
    }
    return 1;
}

void solved(int n)
{
    count++;

    if (printSolution)
    {
        printf("\n\n === Solução %d === \n", count);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i] == j)
                {
                    printf("1\t");
                }
                else
                {
                    printf(".\t");
                }
            }
            printf("\n");

        }
    }
}

void solveNQueensProblem(int n)
{
    int k = 1;
    a[k] = 0;

    while (k != 0)
    {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !isSafe(k))
        {
            a[k]++;
        }
        if (a[k] <= n)
        {
            if (k == n)
            {
                solved(n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
}

void main(int argc, char **argv)
{
    printSolution = atoi(argv[2]);

    int tamanhoTabuleiro = atoi(argv[1]);

    clock_t begin = clock();

    solveNQueensProblem(tamanhoTabuleiro);

    double executionTime = (double)(clock() - begin) / CLOCKS_PER_SEC;
    
    printf("\nTempo de execução: %fs \n", executionTime);
    printf("\nTotal soluções: %d", count);
}