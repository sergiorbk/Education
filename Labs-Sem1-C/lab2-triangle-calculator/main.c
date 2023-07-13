#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 20

double AB,BC,AC,perimeter,half_perimeter,square,Hab,Hbc,Hac,Mab,Mbc,Mac,Bab,Bbc,Bac=0;
char wait;

float enterSide(char name[2]);
int enterData();
int isNumberStr(char str[]);
void countTriangle();
void printResult();

int main(){
 int exit=0;
 while(exit==0){
    if(enterData()==0){
        countTriangle();
        printResult();

        printf("Enter something to continue or 0 to exit.\n");
        fflush(stdin);
        if(getch()=='0'){
            exit=1;
        }else{
            fflush(stdin);
            system("cls");
        }
  }
 }
 return 0;
}
int enterData(){
    printf("Vvedit storony trykutnyka dlia obchyslennia\n");
    AB=enterSide("AB");
    BC=enterSide("BC");
    AC=enterSide("AC");
    //Захист від введення довжин сторін, що не можуть утворити трикутник
    if(AB+BC<=AC||AB+AC<=BC||AC+BC<=AB){
        printf("Pomylka! Suma dvokh storin maie buty bilshoiu vid tretoi. Sprobuite shche raz.\n");
        printf("***Enter something to continue...***\n");
        scanf("%s", wait);
        system("cls");
        return -1;
    }else{
        printf("*********************************************************\n\n");
        return 0;
    }
}
int isNumberStr(char str[MAXLEN]){
    char charDigits[11]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if(str[0]==','||str[strlen(str)-1]==','||str[0]=='.'||str[strlen(str)-1]=='.'){
        printf("Pomylka: chislo ne mozhe pochinatisya abo zakinchuvatis ',' abo '.'.\n");
        return -1;
    }
    if(strlen(str)>1&&str[0]=='0'&&str[1]!='.'){
       printf("Pomylka: chislo ne mozhe pochinatisya z '0'/Vvedeno ',' zamist '.'.\n");
       return -1;
    }
    if(strlen(str)>1&&str[0]=='-'&&str[1]=='0'&&str[2]!='.'){
       printf("Pomylka: chislo ne mozhe pochinatisya z '0'/Vvedeno ',' zamist '.'.\n");
       return -1;
    }
    if(str[0]=='-'){
        int commaTrigger=0;
        for(int i=1; i<=strlen(str)-1; i++){
            int isDigit=0;
            int isComma=0;

            if(str[i]==','||str[i]=='.'){
                    isComma=1;
                    commaTrigger++;
            }
            for(int digit=0; digit<=9; digit++){
                if(str[i]==charDigits[digit]){
                    isDigit=1;
                }
            }
            if(isDigit==0&&isComma==0){
                printf("Pomylka: chislo mistit nedopustimi simvoly.\n");
                return -1;
            }
        }
        if(commaTrigger>1){
                printf("Pomylka: nedopustima kilkist ',' abo '.' u chisli.\n");
                return -1;
            }
    return 0;
    }else{
        int commaTrigger=0;
        for(int i=0; i<=strlen(str)-1; i++){
            int isDigit=0;
            int isComma=0;

            if(str[i]==','||str[i]=='.'){
                    isComma=1;
                    commaTrigger++;
            }
            for(int digit=0; digit<=9; digit++){
                if(str[i]==charDigits[digit]){
                    isDigit=1;
                }
            }
            if(isDigit==0&&isComma==0){
                printf("Pomylka: chislo mistit nedopustimi simvoly.\n");
                return -1;
            }
        }

        if(commaTrigger>1){
                printf("Pomylka: nedopustima kilkist ',' abo '.' u chisli.\n");
                return -1;
            }
    return 0;
    }
}

float enterSide(char name[2]){
    char input[MAXLEN];
    do{
      printf("Vvedit dovzhynu storony %s: ", name);//введення довжини AB
      scanf("%s", &input);
    }while(isNumberStr(input)==-1);

    while(atof(input)<=0){
      printf("Pomylka! Storona trykutnyka maie buty bilsha za 0.\n");
        do{
          printf("Vvedit dovzhynu storony %s: ", name);//введення довжини AB
          scanf("%s", &input);
        }while(isNumberStr(input)==-1);
    }
    return atof(input);
}
void countTriangle(){
    perimeter=AB+BC+AC;
    half_perimeter=perimeter/2;
    square=sqrt(half_perimeter*(half_perimeter-AB)*(half_perimeter-BC)*(half_perimeter-AC));
    Hab=2*square/AB;
    Hbc=2*square/BC;
    Hac=2*square/AC;
    Mab=0.5*sqrt(2*BC*BC+2*AC*AC-AB*AB);
    Mbc=0.5*sqrt(2*AB*AB+2*AC*AC-BC*BC);
    Mac=0.5*sqrt(2*AB*AB+2*BC*BC-AC*AC);
    Bab=2/(BC+AC)*sqrt(BC*AC*half_perimeter*(half_perimeter-AB));
    Bbc=2/(AB+AC)*sqrt(AB*AC*half_perimeter*(half_perimeter-BC));
    Bac=2/(AB+BC)*sqrt(AB*BC*half_perimeter*(half_perimeter-AC));
}
void printResult(){
    printf("P= %f\n", perimeter);
    printf("S= %f\n", square);
    printf("=========================================================\n");
    printf("Vysota AB: %f\n", Hab);
    printf("Vysota BC: %f\n", Hbc);
    printf("Vysota AC: %f\n", Hac);
    printf("=========================================================\n");
    printf("Mediana, provedena do AB: %f\n", Mab);
    printf("Mediana, provedena do BC: %f\n", Mbc);
    printf("Mediana, provedena do AC: %f\n", Mac);
    printf("=========================================================\n");
    printf("Bisektrysa kuta A, provedena do BC: %f\n", Bbc);
    printf("Bisektrysa kuta B, provedena do AC: %f\n", Bac);
    printf("Bisektrysa kuta C, provedena do AB: %f\n", Bab);
    printf("=========================================================\n");
}
