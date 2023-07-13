#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#define PI 3.14159265359
double R1,R2, L, C, fmin, fmax, w, df, a, b, c, d, re, lm;
char close;
int kontur;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
do{
     system("cls");
    do{
      printf("������ ����� ������� (1-4): ");
      fflush(stdin);
      scanf("%d",&kontur);
    }while(kontur!=1&&kontur!=2&&kontur!=3&&kontur!=4);
    if(kontur==3||kontur==4){
        printf("������ R1: ");
        scanf("%lf",&R1);
        printf("������ R2: ");
        scanf("%lf",&R2);
    }else{
        printf("������ R1: ");
        scanf("%lf",&R1);
    }

    printf("������ L: ");
    scanf("%lf",&L);
    printf("������ C: ");
    scanf("%lf",&C);
do{
    printf("������ f ���: ");
    scanf("%lf",&fmin);
    printf("������ f ������ (>f ���): ");
    scanf("%lf",&fmax);
}while(fmin>=fmax);
    printf("\n");

do{
    printf("������ ���� f (>0): ");
    scanf("%lf",&df);
}while(df<=0);

    if(kontur==1||kontur==2){
        a=L/C;
        c=R1;
    }else{
        a=R1*R2;
        c=R1+R2;
    }
    double f0=1/(2*PI*sqrt(L*C));
    printf("L0 = %lf\n\n", f0);
    for(double f=fmin; f<=fmax; f+=df){
        w=2*PI*f;
        d=(w*L)-(1/(w*C));
        printf("D=%lf\n", d);
        switch(kontur){
            case 1:{
                b=(-R1)/(w*C);
                printf("B(1)=%lf\n", b);
                break;
            }
            case 2:{
                b=R1/(w*C);
                printf("B(2)=%lf\n", b);
                break;
            }
            case 3:{
                b=R1*((w*L)-(1/(w*C)));
                break;
            }
            case 4:{
                b=w*L*R1-R2/(w*C);
                break;
            }
      }
      re=(a*c+b*d)/(c*c+d*d);
      lm=(b*c-a*d)/(c*c+d*d);
      printf("f= %g   z=%g+i*%g\n", f, re, lm);
    }
    printf("\n������ ����, ��� ����������, ��� 'q', ��� �����..");
    fflush(stdin);
    scanf("%c", &close);
}while(close!='q');
    return 0;
}
