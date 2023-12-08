// Determinar quais são os números primos existentes entre dois números (mínimo e máximo). Sabendo que: 
// Os números forneceidos devem ser naturais (inteiros positivos maiores que zero)

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Protótipos
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

// Solicitar números para verificação
void solicitarNumeros(int *numeroMinimo, int *numeroMaximo)
{

    bool ehNumero = false;

    printf("\nVamos analisar os números primos disponíveis entre 2 números naturais (inteiros positivos maiores que zero)!\n");

    do
    {
        printf("\nPor favor, informe um número natural para o valor mínimo: ");
        if (scanf("%d", &*numeroMinimo) == 1)
        {
            ehNumero = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (*numeroMinimo <= 0 || !ehNumero);

    ehNumero = false;

    do
    {
        printf("\nPor favor, informe um número natural para o valor máximo (igual ou maior que o valor mínimo): ");

        if (scanf("%d", &*numeroMaximo) == 1)
        {
            ehNumero = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (*numeroMaximo < *numeroMinimo || !ehNumero);
}

//  Verificar e exibir números primos (maior do que 1 - divisível apenas por 1 e por ele mesmo)
void verificarNumerosPrimos(int numeroMinimo, int numeroMaximo)
{
    printf("\n");
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
            printf("Número primo: %d \n", i);
        }
    }
    printf("\n");
}