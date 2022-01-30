#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef float vect[100];



void save( float sum, vect P, float x, int deg )
{
  int i;
  FILE *fichier ;

  fichier = fopen("valpolyR.txt","w") ;

  for(i=deg;i>=0;i--)
     {
        fprintf(fichier, "Le coefficient de  X^%d  est %f \n",i, P[i]);
     }

  fprintf(fichier,"La valeur du polynome en %f est = %f",x,sum) ;
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

  for( i=deg; i>0; i--)
  {
    sum=(sum + P[i])*x ;
  }

  sum=sum+P[0];
  printf("La valuer du polynome est = %f \n",sum);
  save(sum,P,x,deg);
}
