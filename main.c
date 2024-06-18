#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "polinomio.h"

int main()
{
    /*-------------------------------------------------------------------
                            Arquivo 1
    -------------------------------------------------------------------*/
    char arquivo1[100];
    char arquivo2[100];
    printf("Entre com arquivo do primeiro polinômio: "); 
    scanf("%99s", arquivo1);
    polinomio p = polinomio_from_file(arquivo1);
    printf("Primeiro polinômio: \n");
    print_polinomio(p);

    printf("\nDerivada do primeiro polinômio: \n");
    polinomio deriv_1 = deriva_polinomio(p);
    print_polinomio(deriv_1);
    free_polinomio(&deriv_1);

    /*-------------------------------------------------------------------
                            Arquivo 2
    -------------------------------------------------------------------*/

    printf("\nEntre com arquivo do segundo polinômio: ");
    scanf("%99s",arquivo2);
    polinomio q = polinomio_from_file(arquivo2);
    printf("Segundo polinômio: \n");
    print_polinomio(q);
    
    printf("\nDerivada do segundo polinômio: \n");
    polinomio deriv_2 = deriva_polinomio(q);
    print_polinomio(deriv_2); 
    free_polinomio(&deriv_2); 

    /*-------------------------------------------------------------------
                Soma, subtração e produto dos polinômios
    -------------------------------------------------------------------*/

    printf("\nSoma dos polinômios: \n");
    polinomio soma = soma_polinomio(p, q);
    print_polinomio(soma);
    free_polinomio(&soma);

    printf("\nSubtração dos polinômios: \n");
    polinomio sub = sub_polinomio(p, q);
    print_polinomio(sub);
    free_polinomio(&sub);

    printf("\nProduto dos polinômios: \n");
    polinomio prod = prod_polinomio(p, q);
    print_polinomio(prod);
    free_polinomio(&prod);

    /*-------------------------------------------------------------------
                    Integral definida dos polinômios
    -------------------------------------------------------------------*/

    float a, b; //superior tem que ser maior que o inferior
    printf("\nDigite os limites inferior e superior de integração: ");
    scanf("%f %f",&a,&b);
    while(a>b) // Checa se o limite inferior é menor ou igual ao superior
    {
        printf("O limite superior precisa ser maior ou igual que o inferior! \n");
        printf("Digite novamente os limites inferior e superior: ");
        scanf("%f %f",&a,&b);
    }
    
    float Idef1 = integraldef_polinomio(p, a, b);
    printf("Valor da integral definida do primeiro polinômio: %f \n", Idef1);

    float Idef2 = integraldef_polinomio(q, a, b);
    printf("Valor da integral definida do segundo polinômio: %f \n", Idef2);

    /*-------------------------------------------------------------------
                        Método de Newton-Raphson
    -------------------------------------------------------------------*/
   
    printf("Digite agora os parâmetros para o método de Newton-Raphson\n");
    float x_0;
    printf("Valor inicial de x: ");
    scanf("%f",&x_0);

    float epsilon;
    printf("Valor de precisão numérica de epsilon: ");
    scanf("%f",&epsilon);
    while(epsilon<=0)
    {
        printf("Número inválido. Epsilon deve ser maior que zero\n");
        printf("Digite novamente o valor de epsilon: ");
        scanf("%f",&epsilon);
    }

    int t_max;
    printf("Número máximo de iterações: ");
    scanf("%d",&t_max);
    while(t_max<0)
    {
        printf("Número inválido. \n Digite um número inteiro positivo: ");
        scanf("%d",&t_max);        
    }
    float raiz_p = newton_raphson(p, x_0, epsilon, t_max);
    float raiz_q = newton_raphson(q, x_0, epsilon, t_max);
    printf("Uma raiz do primeiro polinômio é (aproximadamente) %f \n",raiz_p);
    printf("Uma raiz do segundo polinômio é (aproximadamente) %f \n",raiz_q);
    
    free_polinomio(&p);
    free_polinomio(&q);
    
}