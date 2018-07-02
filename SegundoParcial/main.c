#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int comparar(void* dato1, void *dato2);

int main()
{
    eEmpleado empleado;
    ArrayList*lista;
    lista=al_newArrayList();
    eEmpleado* p1=NULL;
    eEmpleado* p2=NULL;
    int size;
    int aux;

    int id;
    int idAux[5];
    char nombre[50];
    char direccion[50];
    int cant;

    FILE* f;

    f = fopen("empleados.csv", "r");

    if(f == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }
    while(!feof(f))
    {
        cant = fscanf(f, "%[^,] , %[^,], %[^\n] \n", idAux, nombre, direccion);

        if( cant != 3)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }
        id = atoi(idAux);
        empleado.id = id;
        strcpy(empleado.nombre, nombre);
        strcpy(empleado.direccion, direccion);

        aux = lista->add(lista,empleado);
        if(aux==0){
            printf("Cargado!\n");
        }

        printf("%d %s %s \n",  empleado.id,  empleado.nombre,  empleado.direccion);

    }
        size=al_len(lista);
        printf("Tamanio: %d \n",size);

        printf("Entro");
        system("Pause");

        al_sort(lista,comparar,1);


    return 0;
}


int comparar(void* p1, void *p2)
{
    eEmpleado* datoUno= (eEmpleado*)p1;
    eEmpleado* datoDos=(eEmpleado*) p2;
    int resultado;

    if((strcmpi(datoUno->nombre,datoDos->nombre))==0)
    {
        resultado=0;
    }
    else if((strcmpi(datoUno->nombre,datoDos->nombre))>0)
    {
        resultado=1;
    }
    else
    {
        resultado=-1;
    }

    return resultado;
}
