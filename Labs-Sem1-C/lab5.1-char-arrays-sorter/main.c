#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int random(int range_min, int range_max ){return (range_min+rand()%(range_max-range_min+1));}

int main(){
while(1!=0){
 int a,b, ch,nums=2,numc=5;
 long ltime=time (NULL);
 int stime=(unsigned int) ltime/2;
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);

 printf("\n¬вед≥ть к≥льк≥сть р€дк≥в: "); scanf("%d", &nums);
 printf("¬вед≥ть к≥льк≥сть символ≥в в р€дку: "); scanf("%d", &numc);
 srand(stime);

 char str[nums][numc+1];
 for(a=0;a<nums;a++){
     b=0; // генерац≥€ символ≥в р€дку 65-90 ----- A..Z та 97-122 ----- a..z
     do{
         ch=random(65,122);
         if ((ch>64 && ch<91) || (ch>96 && ch<123) ){
           str[a][b]= ch;
           b++;
         }
      }while (b<numc);
      str[a][b]= '\0'; // вставка символу к≥нц€ р€дку
  }

  printf("\nBefore sorting\n");
  for (a=0;a<nums;a++){
     printf("%d-> %s\n",a+1,str[a]);
  }
 int i,j;
 for(i=0;i<nums-1;i++){
    for(j=i+1;j<nums;j++){
        if (strcmp(str[i],str[j]) >0 ){
            char tmp[1][numc];
            strcpy(tmp[0],str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],tmp[0]);
        }
     }
  }
   printf("\nAfter sorting\n");
   for (a=0;a<nums;a++){
      printf("%d-> %s\n",a+1,str[a]);
   }
   printf("\nEnter something to continue or '0' to exit..");
    fflush(stdin);
    if(getchar()=='0'){
        return 0;
    }else{
        system("cls");
    }
  }
}
