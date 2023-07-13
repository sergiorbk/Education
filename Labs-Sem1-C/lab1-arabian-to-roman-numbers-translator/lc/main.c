#include <stdio.h>; //Підключення бібліотеки stdio.h
int roman(int,int,char); //Ініціалізація методу roman

int main(){
     for(int aka=1; aka<10; aka++){
        printf("%d\n", aka);
    }
    while(1!=0){
    init();//Виклик метода init
    printf("\n");
    printf("\n");
    printf("Enter something to continue or 0 to exit.\n");
    fflush(stdin);
    char input;
    scanf("%c", &input);
    if(input=='0'){
        return 0;
    }else{
    fflush(stdin);
    system("cls");
    }
  }
}
int init(){
int a;
printf("ENTER NUMBER\n");
scanf("%u",&a); //Запис числа, введеного користувачем
a=roman(a,1000,'M');
a=roman(a,500,'D');
a=roman(a,100,'C');
a=roman(a,50,'L');
a=roman(a,10,'X');
a=roman(a,5,'V');
a=roman(a,1,'I');
return 0;
}
int roman(int i,int j,char c){
    while (i>=j){
    putchar(c);
    i-=j;
 }
return(i);
}
