<h4 align="center"> 
	💻 CS50: “Introduction to Computer Science” - Módulo 1: Linguagem de programação C 💻
</h4>

<p align="center">
 <a href="#sobre">Sobre</a> •
 <a href="#tecnologia">Tecnologia</a> • 
 <a href="#executar">Como executar</a> • 
 <a href="#exemplos">Exemplos</a> • 
 <a href="#autora">Autora</a> • 
 <a href="#termos">Termos de uso</a>
</p>

## <a name ="sobre"></a>📋 Sobre

📚 Este repositório contém os exercícios do módulo 1 do curso "Introduction to Computer Science" de Harvard, oferecido pela [Fundação Estudar](https://perfil.napratica.org.br/e).

🎯 O propósito destes exercícios é desenvolver habilidades em lógica de programação utilizando a linguagem C. Cada exercício aborda conceitos específicos para aplicação prática do conteúdo aprendido.

📌 **Exercício 1: Divisão de Conta de Restaurante**

Calcular o valor total de uma conta de restaurante e dividir igualmente entre duas pessoas, levando em consideração a taxa de serviço e o imposto ao realizar o cálculo.

📌 **Exercício 2: Identificação de Números Primos**

Encontrar e listar todos os números primos compreendidos entre dois números naturais fornecidos como entrada.

📌 **Exercício 3: Crescimento Populacional de Lhamas**

Calcular o tempo necessário para atingir um tamanho populacional desejado para um grupo de lhamas, considerando as taxas de nascimento e morte para realizar o cálculo.

📌 **Exercício/Desafio 4: Construção de Padrões de Pirâmide**

Construir três tipos diferentes de padrões de pirâmide com alturas variando de 1 a 8, utilizando cerquilha (#).

📌 **Exercício 5: Cálculo de Troco em Moedas**

Calcular quantas moedas de 25, 10, 5 e 1 centavo são necessárias para fornecer um troco mínimo, a partir do valor em reais fornecido como entrada.

📌 **Desafio 6: Verificação de Cartão de Crédito**

Implementar o algoritmo de Luhn para determinar se um número de cartão de crédito é sintaticamente válido, considerando padrões aplicados para MasterCard, American Express e Visa.

##  <a name="tecnologia"></a>🛠 Tecnologia

A seguinte ferramenta foi usada para a realização dos exercícios e desafios:
-   **[Linguagem de programação C](https://devdocs.io/c/)**
  
---

## 🚀 <a name="executar"></a>Como executar

**Para todos os arquivos com os exercícios:**

1. **Compile o programa usando um compilador C, por exemplo, GCC:**
    ```bash
    gcc nome_arquivo.c -o nome_executavel
    ```

    Certifique-se de substituir `nome_arquivo.c` pelo nome do seu arquivo-fonte e `nome_executavel` pelo nome que você deseja para o executável.

2. **Execute o programa:**
    ```bash
    ./nome_executavel
    ```
    Substitua `nome_executavel` pelo nome que você escolheu na etapa de compilação.

    Se você estiver usando o exemplo do "Exercício 1 - Conta restaurante", pode ser algo como:
    ```bash
    ./exercicio1_conta_restaurante
    ```

## 🧪 <a name="exemplos"></a>Exemplos

### 📑 Exercício 1 - Conta restaurante

**Entrada:**
```plaintext
1 - valor da conta em R$ (Exemplo: 000,00): 300,00
2 - taxa de serviço em % (Exemplo: 0,0): 5,5  
3 - imposto em % (Exemplo: 0,0): 4,5
```

**Saída Esperada:**
```plaintext
Valor total da conta com taxa e imposto: R$330,00 
Valor divido por 2: R$165,00 para cada!
```
### 📑 Exercício 2 - Números primos

**Entrada:**
```plaintext
Vamos analisar os números primos disponíveis entre 2 números naturais (inteiros positivos maiores que zero)!      
Por favor, informe um número natural para o valor mínimo: 1
Por favor, informe um número natural para o valor máximo (igual ou maior que o valor mínimo): 10
```

**Saída Esperada:**
```plaintext
Número primo: 2
Número primo: 3
Número primo: 5
Número primo: 7
```
### 📑 Exercício 3 - Tamanho populacional

**Entrada:**
```plaintext
Tamanho inicial da população de lhamas (igual ou maior que 9): 20
Tamanho desejado para a população de lhamas (igual ou maior que o tamanho inicial): 30
```

**Saída Esperada:**
```plaintext
São necessários 5 anos para atingir o tamanho populacional de 30 lhamas!
```

### 📑 Exercícios/Desafio 4 - Pirâmides

**Entrada:**
```plaintext
Por favor, informe uma altura de 1 a 8 para construir a pirâmide: 4
```

**Saída Esperada pirâmide 1:**
```plaintext
#
##
###
####
```
**Saída Esperada pirâmide 2:**
```plaintext
   #
  ##
 ###
####
```
**Saída Esperada pirâmide 3 - Desafio:**
```plaintext
   # #
  ## ##
 ### ###
#### ####
```

### 📑 Exercício 5 - Troco em moedas

**Entrada:**
```plaintext
Vamos calcular quantas moedas de 25, 10, 5 e 1 centavo são necessárias para um troco!
Por favor, informe o valor necessário para o troco em R$ (Exemplo: 0,99): 1,93
```

**Saída Esperada:**
```plaintext
Troco para R$1,93:

7 moedas de 25 centavos
1 moeda de 10 centavos
1 moeda de 5 centavos
3 moedas de 1 centavo
```
### 📑 Exercício 6 - Cartão de crédito

**Entrada:**
```plaintext
Por favor, informe apenas os números do cartão para verificação: 4003600000000014
```

**Saída Esperada:**
```plaintext
VISA
```

## <a name="autora"></a>👩‍💻 Autora

Feito com ❤️ por Joyce Heinze 👋🏽 [Entre em contato!](mailto:joyceheinze@ufrrj.br)

## <a name="termos"></a>📋 Termos de Uso

Este projeto é destinado apenas para fins de demonstração e aprendizado.



