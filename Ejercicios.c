#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

void cargarLista(char *lista, char tam);
void mostrarLista(char *lista, char tam);
void cargarRandom(char *lista, char tam);
void devolverDato(char *lista, char tam); 
void modificarDato( char *lista, char tam);
void intercambioDato(char *lista, char tam);
void mostrarPosicion( char *lista, char tam); 
int sumarLista(char *lista, char tam);
int buscarValor(char *lista, char tam);
float promedioDatos(char *lista, char tam);
void borrarDato(char *lista, char tam);
void reorganizarDatos(char *lista, char tam);
void invertirDatos(char *lista, char tam);
void ordenarDatos(char *lista, char tam);

char i=0,valor=0,posicion=0,contador=0;
int main()
{
    //escribir funciones
    return 0; 
}

void cargarLista(char *lista, char tam)
{
    printf("Ingrese %d valores numéricos\n", SIZE);
    for( i=0 ; i<tam ; i++ )
    {
        printf("Ingrese un valor:");
        scanf(" %hhd",&valor);         
        lista[i]=valor;             
    } 
}

void mostrarLista(char *lista, char tam)
{
    printf("Mostrando Lista\n");
    for( i=0 ; i<tam ; i++ )
    {
        printf("[%d] valor: %d\n",(i+1), lista[i]); //Para un usuario normal, la lista va del 1 al 10
    }
}

void cargarRandom(char *lista, char tam)
{
    srand(time(NULL));
    int num=0;
    for( i=0 ; i<tam ; i++ )
    {
        num=rand()%100;
        lista[i]=num;
    }
}

void devolverDato(char *lista, char tam)
{
    printf("A que posicion de dato desea acceder?\nposicion:");
    scanf(" %hhd",&posicion); 
    if(posicion<=0 || posicion>tam)   //si la posicion ingresada es negativa o supera al tamaño, se toma la posicion 1.
    {
        posicion=1;
    }
    printf("Dato de la posicion N%d:%d",posicion,lista[posicion-1]);
}

void modificarDato( char *lista, char tam)
{
    printf("A que posicion de dato desea acceder?\nposicion:");
    scanf(" %hhd",&posicion); 
    if(posicion<=0 || posicion>tam)   //si la posicion ingresada es negativa o supera al tamaño, se toma la posicion 1.
    {
        posicion=1;
    }
    printf("Nuevo valor:");
    scanf(" %hhd",&valor);      
    printf("Valor nuevo de la posicion[%d]: ",(posicion));
    posicion-=1;
    lista[posicion]=valor;   
    printf("%d\n",lista[posicion]);
}

void intercambioDato(char *lista, char tam)
{
    char posicion2=0;
    printf("Intercambiando Datos.\n Posicion:");
    scanf(" %hhd",&posicion);
    printf(" a posicion:");
    scanf(" %hhd",&posicion2);
    if(posicion<=0 || posicion2<=0) //si ingresan una posicion negativa de la lista 
    {
        posicion=1;
        posicion2=1;
    }
    if(posicion>tam || posicion2>tam) //si ingresan una posicion mayor al tamaño de la lista 
    {
        posicion=1;
        posicion2=1;
    }
    valor=lista[posicion-1];
    lista[posicion-1]=lista[posicion2-1];
    lista[posicion2-1]=valor;
}

void mostrarPosicion( char *lista, char tam) 
{
    bool coincidencia=false;
    printf("Consultar valor?\n");
    printf("Valor:");
    scanf(" %hhd",&valor);
    for( i=0 ; i<tam ; i++ )
    {
        if(lista[i]==valor)
        {
            coincidencia=true;
            posicion=i;
        }
    }
    if(coincidencia==true)
    {
        printf("Se encontro el valor %d en la posicion[%d]",valor,(posicion+1));
    }
    else
    {
        printf("0");
    }
}
int sumarLista(char *lista, char tam)
{
    int suma=0;
    for( i=0 ; i<tam ; i++)
    {
        suma=suma+lista[i];
    }
    printf("La suma de todos los valores es: %d",suma);
    //return suma; //Si el resultado se quiere utilizar
}

int buscarValor(char *lista, char tam)
{
    char valorMax=0;
    for( i=0 ; i<tam ; i++ )
    {
        if(i!=0) //para comparar se necesita un valor anterior, como el 0 no tiene un valor anterior se omite.
        {
            if(lista[i]>valorMax) //Si el valor actual es mayor al valor máximo guardado
            {
                valorMax=lista[i]; //Guarda el valor actual
            }
        }
        else
        {
            valorMax=lista[i]; //toma el primer valor de la lista como máximo
        }
    }
    printf("El valor máximo de la lista es:%d",valorMax);
    //return valorMax; //Si el resultado se quiere utilizar 
}

float promedioDatos(char *lista, char tam)
{
    float promedio=0;
    for(i=0;i<tam;i++)
    {
        promedio=promedio+lista[i];
    }
    promedio=promedio/tam;
    printf("El promedio es %.2f",promedio); // %.2f me permite redondear 2 dígitos después de la coma
    //return promedio; //Si el resultado se quiere utilizar
}

void borrarDato(char *lista, char tam)
{
    char valorBuscar=0; 
    for(i=0;i<tam;i++) //empieza a recorrer la lista
    {
        valorBuscar=lista[i];  //toma el primer valor de la lista
        if(valorBuscar!=0)  //si el valor es 0 (0=Borrado) salta el paso de busqueda
        {
            for(contador=0;contador<tam;contador++) //recorre toda la lista para buscar coincidencias
            {
                if(contador!=i) //si la posición de la lista es la misma de la que tomo el valor de referencia, no lo cambia.
                {
                    if(valorBuscar==lista[contador]) //Si el valor a buscar es igual al valor actual
                    {
                        lista[contador]=0; //Borra la posición del valor actual
                    }
                }
            }
        }
    }
}

void reorganizarDatos(char *lista, char tam)
{
    bool espacioVacio=false;
    for(i=0;i<tam;i++) 
    {
        if(lista[i]==0) //si el valor actual es 0 (valor borrado)
        {
            espacioVacio=true;
            for(contador=i;contador<tam;contador++) // contador toma la posición del valor vacío y empieza a recorrer la lista desde esa posición
            {
                if(espacioVacio==true) 
                {
                    if(lista[contador]!=0) //si encuentra un valor que no fue borrado
                    {
                        lista[i]=lista[contador]; //toma la posición vacía (i) y lo reemplaza por la actual (contador)
                        lista[contador]=0; //borra la posición actual
                        espacioVacio=false; //sale del bucle (evita seguir buscando valores)
                    }
                }
            }
        }
    }
}
void invertirDatos(char *lista, char tam)
{
    for(i=1;i<=(tam/2);i++)
    {
        posicion=lista[i-1]; //tomo el valor de la primera posición
        lista[i-1]=lista[tam-i]; //reemplazo el primero con el ultimo
        lista[tam-i]=posicion;  //reemplazo el ultimo con el primero
    }
}
void ordenarDatos(char *lista, char tam)
{
    char guardar=0;
    for( i=0; i<(tam-1); i++)
    {
        guardar=lista[i];
        posicion=i;
        for( contador=(i+1); contador<tam; contador++)
        {
            if( lista[contador]<guardar )
            {
                guardar=lista[contador];
                posicion=contador;
            }
        }
        lista[posicion]=lista[i];
        lista[i]=guardar;
    }
}