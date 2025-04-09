#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Estructuras
struct compu{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
};

//Declaracion de funciones
void listarPCs(struct compu pcs[], int cantidad);

void mostrarMasVieja(struct compu pcs[], int cantidad);

//Funcion principal
int main() {
    //Declaracion de variables
    char tipos[6][10]={"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    struct compu pcs[5];
    int i=0;
    int j;

    //Seteo funcion random
    srand(time(NULL));

    //Genero aleatoriamente características de 5 PCs
    for(i = 0 ; i < 5 ; i++)
    {
        //Velocidad aleatoria entre 1 y 3
        pcs[i].velocidad = 1 + rand() % (3 - 1 + 1);

        //Anio aleatorio entre 2015 y 2024
        pcs[i].anio = 2015 + rand() % (2024 - 2015 + 1);

        //Cantidad de nucleos aleatorios entre 1 y 8
        pcs[i].cantidad_nucleos = 1 + rand() % (8 - 1 + 1);

        //Hago que el campo tipo_cpu apunte a un string aleatorio del arreglo tipos
        j = rand() % (6);
        pcs[i].tipo_cpu = tipos[j];
    }    

    //Invoco la funcion para listar las PCs
    listarPCs(pcs,5);

    //Invoco la funcion para mostrar las caracteristicas de la PC o PCs mas viejas
    mostrarMasVieja(pcs,5);

    getchar();
    return 0;
}


//Definicion de funciones
void listarPCs(struct compu pcs[], int cantidad){
    int i;
    for (i = 0 ; i < cantidad ; i++)
    {
        printf("\nCARACTERISTICAS DE PC %d\n",(i+1));
        printf("Velocidad: %dGHz\n", pcs[i].velocidad);
        printf("Anio: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int i = 0, anioMasAntiguo = 2024;

    printf("\n\n------------------------------------\nCARACTERISTICAS DE LAS PC MAS ANTIGUAS:\n");

    //Averiguo cual es el anio mas antiguo de las 5 PCs
    for (i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < anioMasAntiguo)
        {
            anioMasAntiguo = pcs[i].anio;
        }
    }

    //Muestro las caracteristicas de las PCs que tengan el anio mas antiguo
    for (i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio == anioMasAntiguo)
        {
            printf("\nCARACTERISTICAS DE PC %d\n",(i+1));
            printf("Velocidad: %dGHz\n", pcs[i].velocidad);
            printf("Anio: %d\n", pcs[i].anio);
            printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
            printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        }
    }
}