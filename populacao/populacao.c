// Lab 1: Determinar quanto tempo leva para atingir determinado tamanho populacional de lhamas, sabendo que:
// Tamanho populacional = n; A cada ano: nascem n/3 e morrem n/4;

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Protótipos
void receberPopulacao(int *populacaoAtual, int *PopulacaoDesejada);
void calcularTempo(int populacaoAtual, int populacaoDesejada, int *anosNecessarios);
void exibirTempo(int tempo, int populacaoDesejada);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int populacaoAtual;
    int populacaoDesejada;
    int anosNecessarios;

    receberPopulacao(&populacaoAtual, &populacaoDesejada);
    calcularTempo(populacaoAtual, populacaoDesejada, &anosNecessarios);
    exibirTempo(anosNecessarios, populacaoDesejada);
}

// Receber inputs do usuário
void receberPopulacao(int *populacaoAtual, int *populacaoDesejada)
{
    bool ehNumero = false;
    do
    {
        printf("\nTamanho inicial da população de lhamas (igual ou maior que 9): ");
        if (scanf("%d", &*populacaoAtual) == 1)
        {
            ehNumero = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (*populacaoAtual < 9 || !ehNumero);

    ehNumero = false;

    do
    {
        printf("\nTamanho desejado para a população de lhamas (igual ou maior que o tamanho inicial): ");
        if (scanf("%d", &*populacaoDesejada) == 1)
        {
            ehNumero = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (*populacaoDesejada < *populacaoAtual || !ehNumero);
}

// Calcular a quantidade de anos necessário para atingir determinado tamanho populacional
void calcularTempo(int populacaoAtual, int populacaoDesejada, int *anosNecessarios)
{
    int anos;
    for (anos = 0; populacaoAtual < populacaoDesejada; anos++)
    {
        int crescimentoPopulacional = populacaoAtual / 3;
        int deficitDemografico = populacaoAtual / 4;
        populacaoAtual += crescimentoPopulacional - deficitDemografico;
    }
    *anosNecessarios = anos;
}

// Exibir o tempo necessário no terminal
void exibirTempo(int tempo, int populacaoDesejada)
{
    printf("\nSão necessários %d ano(s) para atingir o tamanho populacional de %d lhamas!\n\n", tempo, populacaoDesejada);
}