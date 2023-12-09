#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Protótipo
long long receberNumeroCartao(int *quantidadeDigitos);
int verificarCartao(int quantidadeDigitos, long long numeroCartao);
void exibirValidacaoCartao(int quantidadeDigitos, long long numeracaoCartao, int resultadoValidacao);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int quantidadeDigitos;
    long long numeracaoCartao = receberNumeroCartao(&quantidadeDigitos);
    int resultadoValidacao = verificarCartao(quantidadeDigitos, numeracaoCartao);
    exibirValidacaoCartao(quantidadeDigitos, numeracaoCartao, resultadoValidacao);
}

// Receber o número do cartão para validação
long long receberNumeroCartao(int *quantidadeDigitos)
{
    long long numeroCartao;
    bool ehValido = false;

    do
    {
        *quantidadeDigitos = 0;

        printf("\nPor favor, informe apenas os números do cartão para verificação: ");
        if (scanf("%lld", &numeroCartao) == 1)
        {
            long long digitosCartao = numeroCartao;

            while (digitosCartao != 0)
            {
                digitosCartao /= 10;
                (*quantidadeDigitos)++;
            }

            if (*quantidadeDigitos == 13 || *quantidadeDigitos == 15 || *quantidadeDigitos == 16)
            {
                ehValido = true;
            }
            else
            {
                ehValido = false;
                printf("\nNúmero do cartão inválido\n");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            ehValido = false;
            printf("\nEntrada inválida.\n");
            while (getchar() != '\n')
                ;
        }
    } while (!ehValido || ((*quantidadeDigitos != 13 && *quantidadeDigitos != 15 && *quantidadeDigitos != 16)));

    return numeroCartao;
}

// Validar o número do cartão
int verificarCartao(int quantidadeDigitos, long long numeroCartao)
{
    char numerosNoCartao[quantidadeDigitos + 1];
    sprintf(numerosNoCartao, "%lld", numeroCartao);

    int numerosAposMultiplicacao[(quantidadeDigitos / 2) + 1];
    int resultadoSoma = 0;

    int contador = 0;

    // Algoritmo de Luhn:
    //  1° Multiplicar cada segundo dígito por 2 (começando pelo penúltimo):
    for (int i = quantidadeDigitos - 1; i > 0; i -= 2)
    {
        char numeroAtual = numerosNoCartao[i - 1];
        int numeroAtualMultiplicadoPorDois = (numeroAtual - '0') * 2;
        numerosAposMultiplicacao[contador] = numeroAtualMultiplicadoPorDois;
        contador++;
    }

    // 1.2 Adicionar os dígitos dos produtos da multiplicação (ou seja, não os próprios produtos):
    for (int i = 0; i < contador; i++)
    {
        int numeroAtual = numerosAposMultiplicacao[i];
        resultadoSoma += (numeroAtual / 10) + (numeroAtual % 10);
    }
  
    // 2. Adicionar a soma os dígitos qeu não foram multiplicados por 2 (começando do final):
    for (int i = quantidadeDigitos - 1; i >= 0; i -=2) {
        char numeroAtual = numerosNoCartao[i];
        int numeroParaSomar = numeroAtual - '0';
        resultadoSoma += numeroParaSomar;
    }

    return resultadoSoma;
}

// Exibir o resultado da validação (bandeira do cartão)
void exibirValidacaoCartao(int quantidadeDigitos, long long numeracaoCartao, int resultadoValidacao) {
    char numerosNoCartao[quantidadeDigitos + 1];
    sprintf(numerosNoCartao, "%lld", numeracaoCartao);

    // Verifica o tipo de cartão com base no comprimento e nos primeiros dígitos
    bool visa = (quantidadeDigitos == 13 || quantidadeDigitos == 16) && numerosNoCartao[0] == '4';
    bool masterCard = quantidadeDigitos == 16 && numerosNoCartao[0] == '5' && numerosNoCartao[1] >= '1' && numerosNoCartao[1] <= '5';
    bool amex = quantidadeDigitos == 15 && numerosNoCartao[0] == '3' && (numerosNoCartao[1] == '4' || numerosNoCartao[1] == '7');

    char validacao[sizeof(resultadoValidacao) + 1];
    sprintf(validacao, "%d", resultadoValidacao);
    
    bool ehZero = validacao[strlen(validacao) - 1] == '0';
    
    if (visa && ehZero) {
        printf("\nVISA\n\n");
    } else if (masterCard && ehZero) {
        printf("\nMASTERCARD\n\n");
    } else if (amex && ehZero) {
        printf("\nAMEX\n\n");
    } else {
        printf("\nINVÁLIDO\n\n");
    }
}

