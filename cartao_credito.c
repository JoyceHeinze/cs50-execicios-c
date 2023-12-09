#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Prot�tipo
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

// Receber o n�mero do cart�o para valida��o
long long receberNumeroCartao(int *quantidadeDigitos)
{
    long long numeroCartao;
    bool ehValido = false;

    do
    {
        *quantidadeDigitos = 0;

        printf("\nPor favor, informe apenas os n�meros do cart�o para verifica��o: ");
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
                printf("\nN�mero do cart�o inv�lido\n");
                while (getchar() != '\n')
                    ;
            }
        }
        else
        {
            ehValido = false;
            printf("\nEntrada inv�lida.\n");
            while (getchar() != '\n')
                ;
        }
    } while (!ehValido || ((*quantidadeDigitos != 13 && *quantidadeDigitos != 15 && *quantidadeDigitos != 16)));

    return numeroCartao;
}

// Validar o n�mero do cart�o
int verificarCartao(int quantidadeDigitos, long long numeroCartao)
{
    char numerosNoCartao[quantidadeDigitos + 1];
    sprintf(numerosNoCartao, "%lld", numeroCartao);

    int numerosAposMultiplicacao[(quantidadeDigitos / 2) + 1];
    int resultadoSoma = 0;

    int contador = 0;

    // Algoritmo de Luhn:
    //  1� Multiplicar cada segundo d�gito por 2 (come�ando pelo pen�ltimo):
    for (int i = quantidadeDigitos - 1; i > 0; i -= 2)
    {
        char numeroAtual = numerosNoCartao[i - 1];
        int numeroAtualMultiplicadoPorDois = (numeroAtual - '0') * 2;
        numerosAposMultiplicacao[contador] = numeroAtualMultiplicadoPorDois;
        contador++;
    }

    // 1.2 Adicionar os d�gitos dos produtos da multiplica��o (ou seja, n�o os pr�prios produtos):
    for (int i = 0; i < contador; i++)
    {
        int numeroAtual = numerosAposMultiplicacao[i];
        resultadoSoma += (numeroAtual / 10) + (numeroAtual % 10);
    }
  
    // 2. Adicionar a soma os d�gitos qeu n�o foram multiplicados por 2 (come�ando do final):
    for (int i = quantidadeDigitos - 1; i >= 0; i -=2) {
        char numeroAtual = numerosNoCartao[i];
        int numeroParaSomar = numeroAtual - '0';
        resultadoSoma += numeroParaSomar;
    }

    return resultadoSoma;
}

// Exibir o resultado da valida��o (bandeira do cart�o)
void exibirValidacaoCartao(int quantidadeDigitos, long long numeracaoCartao, int resultadoValidacao) {
    char numerosNoCartao[quantidadeDigitos + 1];
    sprintf(numerosNoCartao, "%lld", numeracaoCartao);

    // Verifica o tipo de cart�o com base no comprimento e nos primeiros d�gitos
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
        printf("\nINV�LIDO\n\n");
    }
}

