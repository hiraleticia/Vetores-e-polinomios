typedef struct
{
    float *coef; //ponteiro para alocação dos coeficientes
    int n; //grau do polinômio
} polinomio;

/*------------------------------------------------------------------------------
    Funções básicas do struct. Implementado em polinomio.c
------------------------------------------------------------------------------*/
polinomio new_polinomio(int n);
polinomio polinomio_from_file(char *filename);
void free_polinomio(polinomio *p);
bool polinomio_is_null(polinomio p);
float valor_polinomio(polinomio p, float x);
void print_polinomio(polinomio p);

/*------------------------------------------------------------------------------
    Soma, subtração e produto. Implementado em somasubprod.c
------------------------------------------------------------------------------*/
polinomio soma_polinomio(polinomio p, polinomio q);
polinomio sub_polinomio(polinomio p, polinomio q);
polinomio prod_polinomio(polinomio p, polinomio q);

/*------------------------------------------------------------------------------
    Derivada e integral. Implementado em drv_int.c
------------------------------------------------------------------------------*/
polinomio deriva_polinomio(polinomio p);
polinomio integra_polinomio(polinomio p, float C);
float integraldef_polinomio(polinomio p, float a, float b);

/*------------------------------------------------------------------------------
    Método de Newton-Raphson. Implementado em newraph.c
------------------------------------------------------------------------------*/
float newton_raphson(polinomio p, float x_0, float epsilon, int t_max);