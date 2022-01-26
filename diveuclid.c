#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef float vect[100];

// PROTOTYPES
void Horner(int deg, vect Pn, float *b, float al) ;
void Save(vect x, vect P, vect dP, int n) ;

//----FONCTION----
void Horner(int deg, vect Pn, float *b, float al)
{
  int i;

  b[0] = Pn[0] ;
  for( i=0 ; i<=deg ; i++)
  {
    b[i] = Pn[i] + al * b[i-1] ;
  }

}

//---SAVE----
void Save(vect x, vect P, vect dP, int n)
{
  int i;
  FILE *fichier ;

  fichier = fopen("EXO9.txt","w") ;

for(i=0 ; i<n ; i++)
{
fprintf(fichier,"%f;%f;%f\n",x[i],P[i],dP[i]) ;
}

fclose (fichier) ;

}

int main(void)
{
int i, deg = 5, n = 9;
float h=1 ;
vect Pn = {1,-3,0,2,0,-13}, x, b, c , dP, P ;



x[0] = -4 ;
for( i=1 ; i<n ; i++)
{
x[i] = x[i-1] + h ;
}

for( i=0 ; i<n ; i++)
{
Horner(deg, Pn, &b[0], x[i]) ;
P[i] = b[deg];

printf("P(%f) = %f\n",x[i], P[i]) ;
Horner(deg-1, b, &c[0], x[i]) ;
dP[i] = c[deg -1];
printf("P'(%f) = %f\n",x[i], dP[i]) ;
}

Save(x, P, dP, n) ;

return 0;
} 
