#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

double pol_dil(double a, double b, int num);
double newt_dot(double b, int num);
double mpd1(double x, int num);
double y,tochnist, prep_tochnist;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do{
        system("cls");
        printf("***���������� ������ �������� ������ �� �������� �������***\n");
        printf("1. cos(y/x)-2*sin(1/x)+1/x=0, xc[a1;a2]\n");
        printf("2. sin(ln(x))-cos(ln(x))+y*ln(x)=0, xc[a1;a2]\n\n");
        double a,b,e;

        do{
            printf("������ ������� xc[a1;a2] (a1<a2)\n");
            printf("������ a: ");
            scanf("%lf", &a);
            printf("������ b: ");
            scanf("%lf", &b);
            printf("������ y: ");
            scanf("%lf", &y);
            printf("\n");

            do{
              printf("������ ������� ���������� (!=0): ");
              fflush(stdin);
              scanf("%lf", &tochnist);
            }while(tochnist==0);
             if(tochnist>0){
              float prep_tochn=1;
              while(tochnist>0){
              prep_tochn=prep_tochn/10;
              tochnist-=1;
           }
           tochnist=prep_tochn;
             }

        }while(a>=b);
        if(b<0){
            printf("\n!!!������� a2<0, �� ��������� ������ ������ 2 �������!!!\n\n");
        }
        bool err_trg1=false;
            while(err_trg1==false){
                printf("������ ����� ����������: 1 -  ����� ����������� ������; 2 - ������� �������� (�������)\n");
                fflush(stdin);
                switch(getchar()){
                   case '1':{
                        err_trg1=true;
                        pol_dil(a, b, 1);
                        if(b<0){
                           printf("!!!��������� ��������� ���������� ����� 2 ������� (b<0)\n");
                        }else{
                           pol_dil(a, b, 2);
                        }
                        break;
                       }
                   case '2':
                       {
                        err_trg1=true;
                        newt_dot(b, 1);
                        if(b<0){
                           printf("!!!��������� ��������� ���������� ����� 2 ������� (b<0)\n");
                        }else{
                           newt_dot(b, 2);
                        }
                        break;
                       }
                   default:{
                           printf("��� ������������. ��������� �� ���...\n");
                           break;
                       }
                }
            }
        printf("\n\n������ ����-���� ������ ��� �����������, ��� 'q' - ��� ����������..\n");
        fflush(stdin);
    }while(getchar()!='q');
    return 0;
}

double pol_dil(double a, double b, int num){
    printf("\n***���������� ������� ����������� ������***\n\n");
    double c=0;
    do{
        c=(a+b)/2;
        if (mpd1(a,num)*mpd1(c,num)>0){
         a=c;
        }
        else{
         b=c;
        }
    }while(fabs(b-a)>tochnist);
    printf("³������ �� %d �������: x=%g\n",num, c);
}

double newt_dot(double b, int num){
    printf("\n***���������� ������� �������� (�������)***\n\n");
    double x=b;
    double delta, dx;
    double fxi;
    do{
        fxi=mpd1(x,num);
        dx=(mpd1((x+tochnist),num)-fxi)/tochnist;
        delta=fxi/dx;
        x=x-delta;
    }while(fabs(delta)>tochnist);
        printf("³������ �� %d �������: x=%lf\n",num, x);
    return x;
}

double mpd1(double x, int num){
    if(num==1){
        return (cos(y/x)-2*sin(1.0/x)+1.0/x);
    }else{
        return sin(log(x))-cos(log(x))+y*log(x);
    }
}
