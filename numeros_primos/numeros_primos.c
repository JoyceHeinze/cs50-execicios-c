// Determinar quais s�o os n�meros primos existentes entre dois n�meros naturais (m�nimo e m�ximo);

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Prot�tipos
void solicitarNumeros(int *numeroMinimo, int *numeroMaximo);
void verificarNumerosPrimos(int numeroMinimo, int numeroMaximo);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int numeroMinimo;
    int numeroMaximo;

    solicitarNumeros(&numeroMinimo, &numeroMaximo);
    verificarNumerosPrimos(numeroMinimo, numeroMaximo);
}

// Solicitar n�meros para verifica��o
void solicitarNumeros(int *numeroMinimo, int *numeroMaximo)
{
    printf("\nVamos analisar os n�meros primos dispon�veis entre 2 n�meros naturais!\n");

    do
    {
        printf("\nPor favor, informe 1 n�mero para o valor m�nimo:");
        scanf("%d", &*numeroMinimo);
    } while (*numeroMinimo < 0);

    do
    {
        printf("\nPor favor, informe 1 n�mero para o valor m�ximo (igual ou maior que o valor m�nimo):");
        scanf("%d", &*numeroMaximo);
    } while (*numeroMaximo < *numeroMinimo);
}

//  Verificar e exibir n�meros primos (maior do que 1 - divis�vel apenas por 1 e por ele mesmo)
void verificarNumerosPrimos(int numeroMinimo, int numeroMaximo)
{
    for (int i = numeroMinimo; i <= numeroMaximo; i++)
    {
        bool ehPrimo = true;
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || i == 1 || (i != j && j > 1 && i % j == 0))
            {
                ehPrimo = false;
            }
        }
        if (ehPrimo)
        {
            printf("N�mero primo: %d \n", i);
        }
    }
}