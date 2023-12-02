// Determinar o valor da conta de restaurante dividida por 2, considerando taxa de serviço e imposto.

#include <stdio.h>
#include <locale.h>

// Protótipos
void receberValores(float *valorConta, float *taxaServico, float *imposto);
void calcularConta(float valorConta, float taxaServico, float imposto, float *valorTotalConta, float *valorContaDividida);
void exibirValorConta(float valorTotalConta, float valorContaDividida);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    float valorConta;
    float taxaServico;
    float imposto;
    float valorTotalConta;
    float valorContaDividida;

    receberValores(&valorConta, &taxaServico, &imposto);
    calcularConta(valorConta, taxaServico, imposto, &valorTotalConta, &valorContaDividida);
    exibirValorConta(valorTotalConta, valorContaDividida);
}

// Receber o valor da conta, taxa de serviço e imposto
void receberValores(float *valorConta, float *taxaServico, float *imposto)
{
    printf("\nPor favor, informe: \n\n1 - valor da conta em R$ (Exemplo: 000,00): ");
    scanf("%f", &*valorConta);
    printf("\n2 - taxa de serviço em %c (Exemplo: 0,0): ", 37);
    scanf("%f", &*taxaServico);
    printf("\n3 - imposto em %c (Exemplo: 0,0): ", 37);
    scanf("%f", &*imposto);
}

// Calcular o valor da conta com taxa de serviço e imposto
void calcularConta(float valorConta, float taxaServico, float imposto, float *valorTotalConta, float *valorContaDividida)
{
    float porcentagem = taxaServico + imposto;
    float valorPorcentagem = valorConta * (porcentagem / 100);
    *valorTotalConta = valorConta + valorPorcentagem;
    *valorContaDividida = *valorTotalConta / 2;
}

// Exibir no terminal valor total da conta e valor dividido por 2 pessoas
void exibirValorConta(float valorTotalConta, float valorContaDividida)
{
    printf("\nValor total da conta com taxa e imposto: R$%.2f \n", valorTotalConta);
    printf("\nValor divido por 2: R$%.2f para cada!", valorContaDividida);
}