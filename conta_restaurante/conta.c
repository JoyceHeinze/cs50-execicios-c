// Determinar o valor da conta de restaurante dividida por 2, considerando taxa de serviço e imposto.

#include <stdio.h>
#include <locale.h>

// Protótipo
void receberValores(void);
void calcularConta(float valorConta, float taxaServico, float imposto);
void exibirValorConta(float valorTotalConta, float valorContaDividida);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    receberValores();
}

// Valor da conta, taxa de serviço e imposto
void receberValores(void)
{
    float valorConta;
    float taxaServico;
    float imposto;

    printf("\nPor favor, informe: \n\n1 - valor da conta em R$ (Exemplo: 000,00): ");
    scanf("%f", &valorConta);
    printf("\n2 - taxa de serviço em %c (Exemplo: 0,0): ", 37);
    scanf("%f", &taxaServico);
    printf("\n3 - imposto em %c (Exemplo: 0,0): ", 37);
    scanf("%f", &imposto);

    calcularConta(valorConta, taxaServico, imposto);
}

void calcularConta(float valorConta, float taxaServico, float imposto)
{
    float porcentagem = taxaServico + imposto;
    float valorPorcentagem = valorConta * (porcentagem / 100);
    float valorTotalConta = valorConta + valorPorcentagem;
    float valorContaDividida = valorTotalConta / 2;

    exibirValorConta(valorTotalConta, valorContaDividida);
}

// Exibir no terminal valor total da conta e valor dividido por 2 pessoas.
void exibirValorConta(float valorTotalConta, float valorContaDividida)
{
    printf("\nValor total da conta com taxa e imposto: R$%.2f \n", valorTotalConta);
    printf("\nValor divido por 2: R$%.2f para cada!", valorContaDividida);
}
