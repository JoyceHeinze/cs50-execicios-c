// Determinar quais são os números primos existentes entre dois números naturais (mínimo e máximo);

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Protótipo
int solicitarNumeros(void);
int verificaNumerosPrimos(int numeroMinimo, int numeroMaximo);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    solicitarNumeros();
}

// Solicitar números para verificação
int solicitarNumeros(void)
{
    int numeroMinimo;
    int numeroMaximo;

    printf("\nVamos analisar os números primos disponíveis entre 2 números naturais!\n");

    do
    {
        printf("\nPor favor, informe 1 número para o valor mínimo:");
        scanf("%d", &numeroMinimo);
    } while (numeroMinimo < 0);

    do
    {
        printf("\nPor favor, informe 1 número para o valor máximo (igual ou maior que o valor mínimo):");
        scanf("%d", &numeroMaximo);
    } while (numeroMaximo < numeroMinimo);

    verificaNumerosPrimos(numeroMinimo, numeroMaximo);
}

// Verificar e exibir números primos
int verificaNumerosPrimos(int numeroMinimo, int numeroMaximo)
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
            printf("Número primo: %d \n", i);
        }
    }
}
