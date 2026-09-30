#include <stdio.h>
#define SIZE 5
void ingresarLista(char *lista, char tam);
void mostrarLista(char *lista, char tam);
void invertirLista(char *lista, char tam);
char i=0;
char valor=0;
int main()
{
    char lista[SIZE];
    ingresarLista(lista,SIZE);
    mostrarLista(lista,SIZE);
    invertirLista(lista,SIZE);
    mostrarLista(lista,SIZE);
    return 0;
}

void ingresarLista(char *lista, char tam)
{
    printf("\nIngrese %d valores numéricos\n",tam);
    for(i=0;i<tam;i++)
    {
        printf("Valor:");
        scanf(" %hhd",&valor);
        lista[i]=valor;
    }
}
void mostrarLista(char *lista, char tam)
{
    printf("LISTA\n");
    for(i=0;i<tam;i++)
    {
        printf("POSICION[%d]:%d\n",(i+1),lista[i]);
    }
}
void invertirLista(char *lista, char tam)
{
    char guardar=0;
    for(i=1;i<=(tam/2);i++)
    {
        guardar=lista[i-1];
        lista[i-1]=lista[tam-i];
        lista[tam-i]=guardar;
    }
}