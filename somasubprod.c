#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

/*------------------------------------------------------------------------------
                        Soma, subtração e produto. 
------------------------------------------------------------------------------*/

polinomio soma_polinomio(polinomio p, polinomio q)
/*
    Soma de dois polinomios
*/
{
    // Checa se os polinômios p e q não são null
    if(!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        int i, grau_maior, grau_menor;
        if(q.n>p.n) 
        // Checa qual o polinômio de maior grau e o de menor grau
        {
            grau_maior = q.n;
            grau_menor = p.n;
        }
        else
        {
            grau_maior = p.n;
            grau_menor = q.n;
        }
        // Criação do polinomio resultante
        polinomio soma_res = new_polinomio(grau_maior);
        if(polinomio_is_null(soma_res)) 
        {
            printf("Memória insuficiente para o resultado \n");
            return new_polinomio(0);
        }
        for(i=0; i<(grau_menor+1); i++)
        // Soma dos coeficientes com mesmo grau
        {
            soma_res.coef[i] = p.coef[i] + q.coef[i];
        }
        // Casos de quando os polinomios tem graus diferentes
        if(q.n>p.n)
        {
            for(; i<(q.n+1); i++)
            {
                soma_res.coef[i] = q.coef[i];
            }
        }
        if(p.n>q.n)
        {
            for(; i<(p.n+1); i++)
            {
                soma_res.coef[i] = p.coef[i];
            }
        }
        return soma_res;
    }
    printf("Polinomio de entrada é null \n");
    return new_polinomio(0);
}

polinomio sub_polinomio(polinomio p, polinomio q)
/*
    Subtração de dois polinomios
*/
{
    // Checa se os polinômios p e q não são null
    if(!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        int i, grau_maior, grau_menor;
        if(q.n>p.n) 
        // Checa qual o polinômio de maior grau e o de menor
        {
            grau_maior = q.n;
            grau_menor = p.n;
        }
        else
        {
            grau_maior = p.n;
            grau_menor = q.n;
        }
        // Criação do polinomio resultante
        polinomio sub_res = new_polinomio(grau_maior);
        if(polinomio_is_null(sub_res))
        {
            printf("Memória insuficiente para o resultado \n");
            return new_polinomio(0);
        }
        for(i=0; i<(grau_menor+1); i++)
        // Subtração dos coeficientes com mesmo grau
        {
            sub_res.coef[i] = p.coef[i] - q.coef[i];
        }
        // Casos de quando os polinômios têm graus diferentes
        if(q.n>p.n)
        {
            for(; i<(q.n+1); i++)
            {
                sub_res.coef[i] = (-1)*q.coef[i];
            }
        }
        if(p.n>q.n)
        {
            for(; i<(p.n+1); i++)
            {
                sub_res.coef[i] = p.coef[i];
            }
        }
        return sub_res;
    }
    printf("Polinomio de entrada é null \n");
    return new_polinomio(0);
}

polinomio prod_polinomio(polinomio p, polinomio q)
/*
    Produto de dois polinômios
*/
{
    // Checa se os polinômios p e q não são null
    if(!polinomio_is_null(p) && !polinomio_is_null(q))
    {
        // O grau do novo polinômio é a soma do grau de p e q
        // Criação do polinômio resultante
        polinomio prod_res = new_polinomio(p.n+q.n);
        if(polinomio_is_null(prod_res))
        {
            printf("Memória insuficiente para o resultado \n");
            return new_polinomio(0);
        }
        // Cálculo do produto dos polinomios
        for(int i=0; i<(p.n+1); i++)
        {
            for(int j=0; j<(q.n+1); j++)
            {
                prod_res.coef[i+j] += p.coef[i] * q.coef[j];
            }
        }
        return prod_res;
    }
    printf("Polinomio de entrada é null \n");
    return new_polinomio(0);
}