#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 15;
int isInpOK(char input_date[8]);
int isYearVisokosniy();
int ask_exit();

int day, month, year=0;
char date_str[8];

int main(){
    while(1!=0){
        do{
            char input_date[8];
            printf("Enter date (DD.MM.YYYY): ");
            fflush(stdin);
            scanf("%s", &date_str);
        }while(isInpOK(date_str)==-1);

    printf("!day: %d ! month: %d ! year: %d\n", day, month, year);

    //Перевірча чи рік високосний
    int is_year_visokosniy=isYearVisokosniy();

    //Обчислення поправки
    int n;
    if(month>2){
        n=0;
    }else if(is_year_visokosniy==1&&month<=2){
        n=1;
    }else if(is_year_visokosniy==0&&month<=2){
        n=2;
    }

    double d1, d2=0;
    modf(365.25*year, &d1);
    modf(30.56*month, &d2);
    int day_number=((int)d1+(int)d2+day+n)%7;
    //printf("Number of day is: %d\n", day_number);
    char day_name[11];
    switch(day_number){
        case 0: printf("Day name is: %s\n", "Monday");
        break;
        case 1: printf("Day name is: %s\n", "Tuesday");
        break;
        case 2: printf("Day name is: %s\n","Wednesday");
        break;
        case 3: printf("Day name is: %s\n", "Thursday");
        break;
        case 4: printf("Day name is: %s\n", "Friday");
        break;
        case 5: printf("Day name is: %s\n", "Saturday");
        break;
        case 6: printf("Day name is: %s\n", "Sunday");
        break;
    }
    if(ask_exit()==0){
        return 0;
    }
  }
}

int isInpOK(char input_date[8]){
    char s_day[3];
    s_day[0]=input_date[0];
    s_day[1]=input_date[1];
    if(atoi(s_day)<=0||atoi(s_day)>31){
        return -1;
    }else{
        day=atof(s_day);
    }
    fflush(stdin);
    char s_month[3];
    s_month[0]=input_date[3];
    s_month[1]=input_date[4];
    //printf("*%c*\n", s_month[0]);
    if(atoi(s_month)<=0||atoi(s_month)>12){
        printf("Error: enter correct value for month...\n");
        return -1;
    }else{
        month=atof(s_month);
    }
    fflush(stdin);

    char s_year[5];
    s_year[0]=input_date[6];
    s_year[1]=input_date[7];
    s_year[2]=input_date[8];
    s_year[3]=input_date[9];
    if(atoi(s_year)<=0){
        printf("Error: enter correct value for year...\n");
        return -1;
    }
    if(isYearVisokosniy()==0&&month==2&&day>28){
        printf("Error: u 2 misyatsi yzkscho rik ne visokosniy mozhe buty 28 dniv...\n");
        return -1;
    }else if(isYearVisokosniy()==1&&month==2&&day>29){
        printf("Error: u 2 misyatsi yzkscho rik visokosniy mozhe buty 29 dniv...\n");
        return -1;
    }

    if(month==4&&day>30||month==6&&day>30||month==9&&day>30||month==11&&day>30){
        printf("Error: u tsomu misyatsi mozhe buty 30 dniv...\n");
        return -1;
    }
        year=atof(s_year);
        return 0;
}

int isYearVisokosniy(){
    if(year%100==0&&year%400==0){
        //printf("Rik visokosniy\n");
        return 1;
    }else if(year%4==0){
        //printf("Rik visokosniy\n");
        return 1;
    }else{
        //printf("Rik ne visokosniy\n");
        return 0;
    }
}

int ask_exit(){
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
