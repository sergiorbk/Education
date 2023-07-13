#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 30

int main(){
    while(1!=0){
    float array[MAXLEN];
    printf("Potribno zapovnity masiv diysnimi chislami...\n");
    printf("Vvedit 'q', schob zavershity vvid...\n");
    int stp_trg=0;
    int arr_len=0;
    for(int i=0; stp_trg!=1 ; i++){
        printf("array[%d]= ", i);
        char input[MAXLEN];
        fflush(stdin);
        scanf("%s", &input);
        if(input[0]=='q'){
          stp_trg=1;
        }else{
            array[i]=atof(input);
        }
        //printf("chk: %f\n", array[i]);
        arr_len++;
    }
    printf("\nVvid elementiv zakincheno...\n************************************\n");
    arr_len-=2;
    printf("\nDovzhyna masivu= %d\n", arr_len);
    float main_array[arr_len];
    for(int i=0; i<=arr_len; i++){
        main_array[i]=array[i];
    }

        float sort_type=0;
        do{
          printf("\nOberit tip sortuvannya: 1 - u por. zrostannya abo 2 - u por. spadannya: ");
          scanf("%f", &sort_type);
        }while(sort_type!=1&&sort_type!=2);

        if(sort_type==1){
            printf("Sortuvannya u por zrostannya...\n\n");
            int isSorted=0;
            int buf;
        while(isSorted==0) {
            isSorted = 1;
            for (int i = 0; i < arr_len; i++) {
                if(main_array[i] > main_array[i+1]){
                    isSorted = 0;

                    buf = main_array[i];
                    main_array[i] = main_array[i+1];
                    main_array[i+1] = buf;
                }
            }
        }
        }else{
            printf("Sortuvannya u por spadannya...\n\n");
            int isSorted=0;
            int buf;
            while(isSorted==0) {
            isSorted = 1;
            for (int i = 0; i < arr_len; i++) {
                if(main_array[i] < main_array[i+1]){
                    isSorted = 0;

                    buf = main_array[i];
                    main_array[i] = main_array[i+1];
                    main_array[i+1] = buf;
                }
            }
         }

        }

    for(int i=0; i<=arr_len; i++){ //вивід відсортованого масиву
        printf("array[%d]= %g\n", i, main_array[i]);
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
