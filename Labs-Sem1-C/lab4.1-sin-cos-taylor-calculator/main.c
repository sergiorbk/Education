#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265359
#define MAXLEN 30

int fact(int num);
double toRad(double angle);
double countSin(double degrees, double accuracy);

float x1=0, x2=0, krok=0, tochnist=0;

int main(){
    int exit=0;
    while(exit==0){
        do{
        printf("Vvedit diapazon obchislennya vid (x1) do (x2). Uvaga: X1 ne mozhe dorivnyvaty X2. \n");
        printf("x1 (vid): "); scanf("%f", &x1); printf("x2 (do) : "); scanf("%f", &x2); /*Ввід діапазону*/
    }while(x1==x2);

    if(x1<x2){
        do{
            printf("Vvedit krok (krok>0): ");
            scanf("%f", &krok);
        }while(krok<=0);
    }else{
        do{
            printf("Vvedit krok (krok<0): ");
            scanf("%f", &krok);
        }while(krok>=0);
    }
    /*Кінець вводу кроку ітераій та його перевірок*/
    do{
        printf("Vvedyt tochnist (ne 0): ");
        scanf("%f", &tochnist);
    }while(tochnist==0);
    if(tochnist>0){
        float prep_tochn=1;
        while(tochnist>0){
        prep_tochn=prep_tochn/10;
        tochnist-=1;
     }
     tochnist=prep_tochn;
     printf("\n***Obroblena tochnist: %lf\n", tochnist);
    }
//******
    if(x1<x2){
      printf("***x***     ***sin(x)***     ***sin(Taylor)***     ***sin(x)-sin(Taylor)***\n");
      for(int x=x1; x<=x2; x+=krok){
           double sin_taylor=countSin(toRad(x), tochnist);
      printf("   %d\t     %f\t        %f\t        %lf\t   \n", x, sin(toRad(x)), sin_taylor, sin(toRad(x))-sin_taylor);
        }
    }else{
        printf("***x***     ***sin(x)***     ***sin(Taylor)***     ***sin(x)-sin(Taylor)***\n");
        for(int x=x1; x>=x2; x+=krok){
           double sin_taylor=countSin(toRad(x), tochnist);
           printf("   %d          %f            %f                 %lf   \n", x, sin(toRad(x)), sin_taylor, sin(toRad(x))-sin_taylor);
        }
    }

    printf("\nEnter something to continue or '0' to exit..");
    fflush(stdin);
    if(getchar()=='0'){
        exit=1;
    }else{
        system("cls");
    }
  }
  return 0;
}

double countSin(double x,double eps){
    double s,an;
    int n;
    n=1;
    an=x;
    s=0;
    while(fabs(an)>eps){
         s+=an;
         n++;
         an*=-x*x/(2.*n-1.0)/(2.0*n-2.0);
    }
    return s;
}

int fact(int number){ /*Обчислення факторіалу*/
    int factorial=1;
    for(int i=2; i<=number; i++){
        factorial*=i;
    }
    return factorial;
}

double toRad(double angle){ /*Переведення кута в радіани*/
    return angle*PI/180;
}
