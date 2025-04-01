// codigo a completar
#include<stdio.h>
#include<time.h>
#define N 20
#include<stdlib.h>

int main() {
int i;
double vt[N];
srand(time(NULL));

for(i = 0;i<N; i++) {
    vt[i]=1+rand()%100;
    printf("%f, ", vt[i]);
}

getchar();
getchar();
return 0;
}