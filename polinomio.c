#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "polinomio.h"

/*------------------------------------------------------------------------------
                           Funções básicas do struct. 
------------------------------------------------------------------------------*/

polinomio new_polinomio(int n)
/*
    Criação de um polinômio com valor 0
*/
{
    polinomio new_p;
    new_p.n = n;
    new_p.coef = malloc((n+1)*sizeof(float)); // Alocar para os dados dos coef
    if(new_p.coef!=NULL)
    {
        for (int i=0; i<(new_p.n+1); i++) // Coeficientes incializados por 0
        {
            new_p.coef[i] = 0;
        }
    }
    else
    {
        printf("Falha na alocação de memória.\n");
        new_p.n = 0;
    }
    return new_p;
}

polinomio polinomio_from_file(char *filename) 
/*
    Leitura do polinômio de um arquivo
*/
{
    FILE *fp = fopen(filename, "r");
    if(fp != NULL) // Checa se o ponteiro não é NULL
    {
        float c; // Variável apenas para o uso do fscanf
        int n = -1; // A primeira linha é grau 0
        
        while(!feof(fp)) // Contagem de graus no arquivo
        {
            fscanf(fp,"%f ",&c); 
            n++;
        }
        rewind(fp); // Retorna ponteiro para posição inicial
        polinomio p = new_polinomio(n);
        if(p.coef!=NULL)
        {
            for (int i=0; i<(n+1); i++) // Leitura dos coeficientes
            {
                fscanf(fp,"%f ",&p.coef[i]);
            }
            fclose(fp); // Fecha o arquivo
            return p;
        }
        else
        {
            printf("Falha na alocação de memória.\n");
        }
    }
    else
    {
        printf("Não foi possível abrir o arquivo. \n");
        printf("Retornando polinômio de valor 0. \n");
    }
    fclose(fp); // Fecha o arquivo
    return new_polinomio(0);
}

void free_polinomio(polinomio *p)
/*
    Libera memória de polinomio
*/
{
    if (p->coef!=NULL)
    {
        free(p->coef); 
        p->coef = NULL;
    }
}

bool polinomio_is_null(polinomio p)
/*
    Checa se alguma das alocações de polinomio falhou
*/
{
    if (p.coef==NULL)
    {
        return true;
    }
    return false;    
}

float valor_polinomio(polinomio p, float x)
/*
    Valor do polinômio com valor de x
*/
{
    // Checa se os polinômios recebido não é null
    if(!polinomio_is_null(p))
    {
        float valor_pol = 0;
        for(int i=0; i<(p.n+1); i++)
        {
            valor_pol += p.coef[i] * (pow(x, i));
        }
        return valor_pol;
    }
    printf("Polinomio de entrada é null \n");
    return 0;
}

void print_polinomio(polinomio p)
/*
    Imprime o polinomio
*/
{
    // Checa se os polinômios recebido é null
    if(polinomio_is_null(p))
    {
        printf("O polinomio é null \n");
        return;
    }
    printf("p(x)=");
    for(int i=0; i<(p.n+1); i++)
    {
        if(i == 0) // Quando o grau é 0, não precisa mostrar o x
        {
            printf("(%f)", p.coef[i]);
        }
        else
            printf("(%f)x^%d", p.coef[i], i);
        if(i != p.n) // No último elemento, o '+' não é mostrado
            printf("+");
        
    }
}