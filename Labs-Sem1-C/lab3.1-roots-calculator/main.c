#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 50
double x, k, e;

int count();

int main(){
    while(1!=0){
        while(count()==-1){
         printf("Enter something to continue...");
         char str[2];
         scanf("%s", &str);
         system("cls");
       }
       printf("Enter something to continue or '0' to exit...");
       fflush(stdin);
       char des;
       scanf("%c", &des);
       if(des=='0'){
            return 0;
       }else{
           system("cls");
       }
    }
}

int count(){
 //Entering a number
    printf("Enter a number: ");
    fflush(stdin);
    scanf("%lf", &x);
    //Entering a power
    do{
     printf("Enter a power: ");
     fflush(stdin);
     scanf("%lf", &k);
    }while(isKCorrect(k)==-1);
    //Entering an accuracy
    do{
    printf("Enter an accuracy(ne 0): ");
    scanf("%lf", &e);
    }while(e==0);
    //трансформація цілих зн. точночті в дробові. (3 в 0.001)
    double prepE=1;
     while(e>0){
        prepE=prepE/10;
        e=e-1;
     }
     e=prepE;
     //printf("Transformed accuracy: %f\n", e);

    double y=1, delta=1, el1=1/k;

    while(fabs(delta)>e){
        double el2=pow(y, k-1);
        delta=el1*(x/el2-y);
        y+=delta;
    }
    printf("Answer is: %lf\n", y);
    return 0;
}

int isKCorrect(double k){
    if(k!=0){
        if(k>0 && fmod(k,2)==0 && x<0){
            printf("!ERROR: A number can't be less then 0 while power of root is double and more then 0.\n");
            return -1;
        }else if(k<0 && fmod(k,2)==0 && x<0){
            printf("!ERROR: A number can't be less then 0 while power of root is double and less then 0.\n");
            return -1;
        }else if(k<0 && fmod(k,2)!=0 && x==0){
            printf("!ERROR: A number can't be 0 while power of root isn't double and less then 0.\n");
            return -1;
        }
    }else{
        printf("!ERROR: Power can't be 0.\n");
        return -1;
        }
}
