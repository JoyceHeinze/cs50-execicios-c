// Criar uma pirâmide de altura 1 até 8 utilizando cerquilha (#), no seguinte formato:
/*   #
    ##
   ###
  ####  */

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

// Protótipos
int receberAltura(void);
void criarPiramide(int alturaPiramide);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int alturaPiramide = receberAltura();
    criarPiramide(alturaPiramide);
}

// Receber e validar input do usuário
int receberAltura(void)
{
    bool ehNumero = false;

    int alturaPiramide;
    do
    {
        printf("\nPor favor, informe uma altura de 1 a 8 para construir a pirâmide: ");
        if (scanf("%d", &alturaPiramide) == 1)
        {
            ehNumero = true;
        }
        else
        {
            while (getchar() != '\n');
        }
    } while (alturaPiramide < 1 || alturaPiramide > 8 || !ehNumero);

    return alturaPiramide;
}

// Criar e exibir pirâmide no terminal
void criarPiramide(int alturaPiramide)
{
    for (int i = 1; i <= alturaPiramide; i++)
    {
        for (int j = i; j < alturaPiramide; j++)
        {
            printf(" ");
        }
        for (int k = i; k > 0; k--)
        {
            printf("#");
        }
        printf("\n");
    }
}