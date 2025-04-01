#include<stdio.h>   //Agrego biblioteca
#define N 5
#define M 7
#include<stdlib.h>
#include<time.h>

int main() {

    int i,j;
    int mt[N][M];
    int *puntero; //Declaro el puntero
    puntero = mt; //Hago que el puntero apunte a la matriz

    srand(time(NULL));

    for(i = 0;i<N; i++)
    {
    for(j = 0;j<M; j++)
    {
    //Recordamos que MiMatriz[i][j]=*(MiMatriz+(i*numeroDeColumnas+j))
    *(puntero+(i*M+j))=1+rand()%100; //Siendo M el numero de columnas
    printf("%d ", *(puntero+(i*M+j)));
    }
    printf("\n");
    }

    getchar();
    getchar();
    return 0;
}