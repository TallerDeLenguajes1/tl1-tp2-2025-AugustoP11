#include<stdio.h>
#include<time.h>
#define N 20
#include<stdlib.h>

int main() {
int i;
double vt[N];
double *puntero;
srand(time(NULL));

puntero = vt;

for(i = 0;i<N; i++) {
    *(puntero+i)=1+rand()%100;
    printf("%f, ", *(puntero+i));
}

getchar();
getchar();
return 0;
}