#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"
/*------------------------------------------------------------------------------
                  Derivada, integral indefinida e definida
------------------------------------------------------------------------------*/

polinomio deriva_polinomio(polinomio p)
/*
    Cálculo da derivada do polinômio
*/
{
    if(!polinomio_is_null(p)) // Checa se o polinômio recebido não é null
    {
        polinomio deriva_res = new_polinomio(p.n-1);
        // O grau da derivada é 1 menor
        if(polinomio_is_null(deriva_res))
        {
            printf("Memória insuficiente para o resultado \n");
            return new_polinomio(0);
        }
        for(int i=0; i<p.n; i++)
        {
        // O primeiro p.coef é uma constante (sua derivada é 0), então é ignorado
            deriva_res.coef[i] = p.coef[i+1] * (i+1);
        }
        return deriva_res;
    }
    printf("Polinomio de entrada é null \n");
    return new_polinomio(0);
}

polinomio integra_polinomio(polinomio p, float C)
/*
    Cálculo da integral indefinida do polinômio
*/
{
    if(!polinomio_is_null(p)) // Checa se o polinômio recebido não é null
    {
        polinomio integral_res = new_polinomio(p.n+1);
        if(polinomio_is_null(integral_res)) // Checa se o polinômio criado não é null
        {
            printf("Memória insuficiente para o resultado \n");
            return new_polinomio(0);
        }
        // Primeiro coeficiente é a constante
        integral_res.coef[0] = C;
        for(int i=0; i<(p.n+1); i++) //p.n+1, pois o primeiro elemento já foi
        {
            // i+1 pois o primeiro coeficiente já foi
            integral_res.coef[i+1] = p.coef[i]/(i+1); 
        }
        return integral_res;
    }
    printf("Polinomio de entrada é null \n");
    return new_polinomio(0);
}

float integraldef_polinomio(polinomio p, float a, float b)
/* 
    Cálculo da integral definida
*/
{
    if(!polinomio_is_null(p)) // Checa se o polinômio recebido não é null
    {
        float integraldef_res = 0;
        polinomio integ_indef = integra_polinomio(p, 0); // Criação do polinomio resultante
        if(!polinomio_is_null(integ_indef))
        //Cálculo da integral definida
        {
            integraldef_res = valor_polinomio(integ_indef, b) - valor_polinomio(integ_indef, a);
        }
        else
        {
            printf("Erro no cálculo da integral indefinida \n");
        }
        free_polinomio(&integ_indef); // Libera memória, não será mais usada integ_indef
        return integraldef_res;
    }
    printf("Polinomio de entrada é null \n");
    return 0;
}