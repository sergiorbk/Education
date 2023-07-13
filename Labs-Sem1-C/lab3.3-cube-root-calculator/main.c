#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359f
float a,b,c,x1,x2,x3,y_one,y2,y3,p,q,d,u,v=0;
int main(){
    while(1!=0){
    printf("x^3+ax^2+bx+c=0\n");
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    p=b-(powf(a,2)/3);
    q=(2*powf(a,3)/27)-(a*b/3)+c;
    d=powf(p,3)/27+powf(q,2)/4;
    printf("\np= %g\nq= %g\nD= %g\n", p, q, d);

    if(d>0){
        float y=-q / 2 + sqrt(d);
        float u=0;
        if(y>=0){
            u=cbrtf(y);
        }else{
            u=cbrtf(fabs(y))*-1;
        }
        float v=0;
        if(u!=0){
            v=-p/(3*u);
        }else{
            v=0;
        }
        printf("\nu= %f; v= %f\n", u, v);

        y_one=u+v;
        float prt1=-((u+v)/2)-a/3;
        float prt2=sqrt(3)*(u-v)/2;

        x1=y_one-a/3;
        printf("\nx1= %f\n", x1);
        printf("x2= %g+i*%g\n", prt1, prt2);
        printf("x3= %g-i*%g\n", prt1, prt2);

    }else if(d==0){
        y_one=3*q/p;
        y2=y3=-3*q/(2*p);
        x1=y_one-a/3;
        x2=y2-a/3;
        x3=y3-a/3;
        printf("\nx1= %f\nx2= %f\nx3= %f\n",x1,x2,x3);
    }else if(d<0){
        float r=sqrt(-pow(p,3)/27);
        float fi=acos(-q/(2*r));
        printf("\nr= %f\nfi= %f\n", r, fi);
        float prt=0;
        if(r>0){
            prt=cbrt(r);
        }
        prt = 2 * fabs(prt);

        y_one=prt*cos(fi/3);
        y2=prt*cos((fi+2*PI)/3);
        y3=prt*cos((fi+4*PI)/3);
        x1=y_one-a/3;
        x2=y2-a/3;
        x3=y3-a/3;
        printf("\nx1= %f\nx2= %f\nx3= %f\n",x1,x2,x3);
    }
    printf("\nEnter anything to continue or '0' to exit...");
    fflush(stdin);
    if(getchar()=='0'){
        return 0;
    }else{
        system("cls");
    }
  }
}
