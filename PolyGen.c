#include <stdio.h>
#define TAILLE 100
#include <stdlib.h>
#include <time.h>

typedef double vect[100];

int main(){
  int deg,i;
  double a,x;
  vect P;

  scanf("%d",&deg);
  printf("%d ",deg);

  scanf("%lf",&x);

  srand(time(0));

  for (i=0; i<=deg; i++){
    a = ((double)rand()/RAND_MAX) * (double)(100.0);
    P[i] = a;
    printf("%lf ",P[i]);}

  printf("%lf",x);

}
