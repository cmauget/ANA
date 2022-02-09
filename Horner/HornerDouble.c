#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <sys/time.h>

#define useinput

typedef double vect[100];

double time_diff2(struct timespec *start, struct timespec *end)
{
  return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec); //On ajoute la différence des secondes avec la différence de n-ieme de secondes
}

double Horner(vect P, int deg, double x){
  double res;
  int i;
  res =  P[deg];
  for (i= deg-1; i >= 0; i--) {
    res = P[i] + x*res;
  }
  return res;
}

double Classique(vect P, int deg, double x){
  double res = 0;
  int i;
  for(i=0; i<=deg; i++)
  {
    res = res + P[i] * pow(x, (double)i);
  }
  return res;
}

int main(void)
{
  int i,deg;
  double sum,x,res1,res2,err;
  vect P;
  struct timespec start; //Heure de début de l'execution
  struct timespec end; //Heure de fin de l'éxécution
  struct timespec start1; //Heure de début de l'execution
  struct timespec end1; //Heure de fin de l'éxécution

  printf("Entrez le deg du poly =  ");
  scanf("%d",&deg);

  for(i=deg;i>=0;i--)
     {
        printf("Entrez le coefficient de  X^%d  = ",i);
        scanf("%lf",&P[i]);
     }

  printf("Entrez la valeur de X =  ");
  scanf("%lf",&x);

  clock_gettime(CLOCK_REALTIME, &start); //On récupère l'heure de début
  res1=Horner(P,deg,x);
  clock_gettime(CLOCK_REALTIME, &end); //On récupère l'heure de fin

  clock_gettime(CLOCK_REALTIME, &start1); //On récupère l'heure de début
  res2=Classique(P,deg,x);
  clock_gettime(CLOCK_REALTIME, &end1); //On récupère l'heure de fin

  err = res1-res2;

  for(i=deg;i>=0;i--)
     {
        printf("Le coefficient de  X^%d  est %lf \n",i, P[i]);
     }

  printf("La valeur du polynome par Horner en %lf est = %lf \n",x,res1) ;
  printf("Temps d'éxécution: %0.8f sec\n",time_diff2(&start,&end));
  printf("La valeur du polynome par Méthode Classique en %lf est = %lf \n",x,res2) ;
  printf("Temps d'éxécution: %0.8f sec\n",time_diff2(&start1,&end1)); //Affichage du temps d'éxécution
  printf("La différence est de : %lf \n", err);
}
