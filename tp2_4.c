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
        j = rand() % (5 + 1);
        pcs[i].tipo_cpu = &tipos[j][10];
    }    

    //Invoco la funcion para listar las PCs
    listarPCs(pcs,5);


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