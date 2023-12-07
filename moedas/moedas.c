// Algoritmo Guloso: Determinar quantas e quais moedas são necessárias para dar um troco com o mínimo de moedas possíveis
// Moedas disponíveis: 25, 10, 5 e 1 centavo

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Protótipos
float solicitarValor(void);
void calcularMoedasTroco(int valorTroco, int *vinteECincoCentavos, int *dezCentavos, int *cincoCentavos, int *umCentavo);
void exibirMoedas(float valorTroco, int vinteECincoCentavos, int dezCentavos, int cincoCentavos, int umCentavo);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int vinteECincoCentavos = 0;
    int dezCentavos = 0;
    int cincoCentavos = 0;
    int umCentavo = 0;

    float valorTroco = solicitarValor();
    float reaisParaCentavos = valorTroco * 100.00;
    int valorTrocoConvertido = reaisParaCentavos;

    calcularMoedasTroco(valorTrocoConvertido, &vinteECincoCentavos, &dezCentavos, &cincoCentavos, &umCentavo);
    exibirMoedas(valorTroco, vinteECincoCentavos, dezCentavos, cincoCentavos, umCentavo);
}

// Solicitar quantos centavos são necessários para o troco
float solicitarValor(void)
{
    bool entradaValida = false;
    float valorTroco;
    printf("\nVamos calcular quantas moedas de 25, 10, 5 e 1 centavo são necessárias para um troco!\n");
    do
    {
        printf("Por favor, informe o valor necessário para o troco em R$ (Exemplo: 0,99): ");
        if (scanf("%f", &valorTroco) == 1)
        {
            entradaValida = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (valorTroco <= 0 || !entradaValida);

    return valorTroco;
}

// Calcular quantas moedas são necessários para o troco informado
void calcularMoedasTroco(int valorTrocoConvertido, int *vinteECincoCentavos, int *dezCentavos, int *cincoCentavos, int *umCentavo)
{
    for (int i = valorTrocoConvertido; i > 0; i--)
    {
        if (valorTrocoConvertido - 25 >= 0)
        {
            (*vinteECincoCentavos)++;
            valorTrocoConvertido -= 25;
        }
        else if (valorTrocoConvertido - 10 >= 0)
        {
            (*dezCentavos)++;
            valorTrocoConvertido -= 10;
        }
        else if (valorTrocoConvertido - 5 >= 0)
        {
            (*cincoCentavos)++;
            valorTrocoConvertido -= 5;
        }
        else if (valorTrocoConvertido - 1 >= 0)
        {
            (*umCentavo)++;
            valorTrocoConvertido -= 1;
        }
    }
}

// Exibir a quantidade de moedas no terminal
void exibirMoedas(float valorTroco, int vinteECincoCentavos, int dezCentavos, int cincoCentavos, int umCentavo)
{
    printf("\nTroco para R$%.2f:\n", valorTroco);

    if (vinteECincoCentavos >= 1)
    {
        (vinteECincoCentavos > 1) ? printf("\n%d moedas de 25 centavos", vinteECincoCentavos) : printf("\n%d moeda de 25 centavos", vinteECincoCentavos);
    }

    if (dezCentavos >= 1)
    {
        (dezCentavos > 1) ? printf("\n%d moedas de 10 centavos", dezCentavos) : printf("\n%d moeda de 10 centavos", dezCentavos);
    }

    if (cincoCentavos >= 1)
    {
        (cincoCentavos > 1) ? printf("\n%d moedas de 5 centavos", cincoCentavos) : printf("\n%d moeda de 5 centavos", cincoCentavos);
    }

    if (umCentavo >= 1)
    {
        (umCentavo > 1) ? printf("\n%d moedas de 1 centavo", umCentavo) : printf("\n%d moeda de 1 centavo", umCentavo);
    }
    printf("\n\n");
}