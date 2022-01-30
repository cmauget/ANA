#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <sys/time.h>

typedef float vect[100];

float time_diff2(struct timespec *start, struct timespec *end)
{
  return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec); //On ajoute la différence des secondes avec la différence de n-ieme de secondes
}


void save( float sum, vect P, float x, int deg, float time )
{
  int i;
  FILE *fichier ;

  fichier = fopen("valpolyR.txt","w") ;

  for(i=deg;i>=0;i--)
     {
        fprintf(fichier, "Le coefficient de  X^%d  est %f \n",i, P[i]);
     }

  fprintf(fichier,"La valeur du polynome en %f est = %f \n",x,sum) ;
  fprintf(fichier, "Temps d'éxécution: %0.8f sec\n", time);
  fclose (fichier) ;
}


/*void read_ints ();
  {
    FILE* file = fopen ("valpolyE.txt", "r");
    int i = 0;

    while (!feof (file))
      {
        fscanf (file, "%d", &i);
        printf ("%d ", i);
      }
    fclose (file);
  }*/


int main(void)
{
  int i,deg;
  float sum,x;
  vect P;
  struct timespec start; //Heure de début de l'execution
  struct timespec end; //Heure de fin de l'éxécution

  printf("Entrez le deg du poly =  ");
  scanf("%d",&deg);
//  printf("\n");

  for(i=deg;i>=0;i--)
     {
        printf("Entrez le coefficient de  X^%d  = ",i);
        scanf("%f",&P[i]);
     }

  printf("Entrez la valuer de X =  ");
  scanf("%f",&x);
  /* deg = 5; //Entrez les deg de P
  P  = {1,-3,0,2,0,-13}; // Entrez les alpha du polynome ici
  x= 3; //entrez la valuer ou évaluer le polynôme */
  clock_gettime(CLOCK_REALTIME, &start); //On récupère l'heure de début

  for( i=deg; i>0; i--)
  {
    sum=(sum + P[i])*x ;
  }

  sum=sum+P[0];

  clock_gettime(CLOCK_REALTIME, &end); //On récupère l'heure de fin

  printf("La valuer du polynome est = %f \n",sum);
  printf("Temps d'éxécution: %0.8f sec\n",time_diff2(&start,&end)); //Affichage du temps d'éxécution

  save(sum,P,x,deg,time_diff2(&start,&end));
}
