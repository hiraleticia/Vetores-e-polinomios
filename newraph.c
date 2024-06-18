#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "polinomio.h"

/*------------------------------------------------------------------------------
                        Método de Newton-Raphson. 
------------------------------------------------------------------------------*/

float newton_raphson(polinomio p, float x_0, float epsilon, int t_max)
{
/*
    Método de Newton-Raphson
*/
    if(!polinomio_is_null(p)) // Checa se polinômio recebido não é NULL
    {
        polinomio deriv_poli = deriva_polinomio(p); // Polinômio da derivada
        int t = 0;
        float modulo = 0;
        float aux;
        if(!polinomio_is_null(deriv_poli)) // Checa se o polinômio da derivada é null
        {
            do{ 
                if(valor_polinomio(deriv_poli, x_0) == 0)
                // Checa quando a derivada resulta em 0
                {
                    printf("Não é possível dividir por zero \n");
                    break;
                }
                aux = x_0; // Auxiliar para salvar o valor de x_0 antes do cálculo
                x_0 -= (valor_polinomio(p, x_0)/(valor_polinomio(deriv_poli, x_0)));
                modulo = fabs(x_0-aux);
                t++;
            }while((modulo >= epsilon) && (t < t_max));
            if(t>=t_max) // Aviso para quando atingir o número máximo de iterações
            {
                printf("Número máximo de iterações atingido.");
            }
        }
        else
        {
            printf("A derivada é null\n");
        }
        free_polinomio(&deriv_poli);
        return x_0;
    }
    printf("Polinomio recebido é NULL\n");
    return x_0;
}