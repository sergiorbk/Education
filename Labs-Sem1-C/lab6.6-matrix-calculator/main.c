#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do{
      system("cls");
      printf("**********************************************\n");
      printf("***Обчислення СЛАР методом простих ітерацій***\n");
      printf("**********************************************\n");
      int i, j;
      //Ввід розмірності СЛАР
      int n=0;
      do{
        printf("Введіть кількість рівнянь СЛАР (>0): ");
        fflush(stdin);
        scanf("%d", &n);
      }while(n<=0);
      double tochnist=0;
      do{
        printf("Введіть точність обчислення (!=0): ");
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
     printf("\n***Obroblena tochnist: %lf\n", tochnist);
    }

      //Вивід макету СЛАР
      for(i=0; i<=n-1; i++){
            printf("\n");
        for(j=0; j<=n-1; j++){
            if(j<n-1){
                printf("a%d%d*x%d + ", i+1, j+1, j+1);
            }else{
                printf("a%d%d*x%d = b%d", i+1, j+1, j+1, i+1);
            }
         }
       }
       printf("\n");
       //кінець виводу макету СЛАР

       //Заповнення матриці ливих і правих частин рівнянь
       double **a = (double**)malloc(n * sizeof(double*));//матриця лівих частин рівнянь
       double *b = (double*)malloc(n * sizeof(double));//вектор правих частин рівнянь
       for(i=0; i<n; i++){
         a[i]=(double*)malloc(n*sizeof(double));
         printf("\n");
        for(j=0; j<=n; j++){
            if(j<n){
                printf("Введіть a%d%d: ", i+1, j+1);
                fflush(stdin);
                scanf("%lf*", &a[i][j]);
            }else{
                printf("Введіть b%d: ", i+1);
                fflush(stdin);
                scanf("%lf*", &b[i]);
            }
        }
    }//кінець заповнення

    //початок обчислень
    double* xp = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++){
		xp[i] = b[i] / a[i][i];
	}

	double* x = (double*)malloc(n * sizeof(double));
	int err_trig=0;
    do {
		for (i = 0; i < n; i++) {
            double check_summ=0;
			x[i] = b[i] / a[i][i];

			for (j = 0; j < n; j++) {
				if (i == j){
                    continue;
				}
				else {
				    check_summ+=a[i][j];
				    //printf("%lf\n", check_summ);
					x[i] -= a[i][j] / a[i][i] * xp[j];
				}

				if(a[i][i]==fabs(check_summ)){//перевірка СЛААР на мож. обч. методом ітерацій
                err_trig=1;
                }
			}//кінець for j

		}//кінець for i

		if(err_trig==1){
            printf("\nПомилка! Цю СЛАР неможливо розв'язати методом простих ітерацій.\n");
            break;
            //getch();
            //return 0;
		}

		bool stp_trg = true;
		for (i = 0; i < n - 1; i++) {
			if (fabs(x[i] - xp[i]) > tochnist) {
				stp_trg = false;
				break;
			}
		}

		for (i = 0; i < n; i++) {
			xp[i] = x[i];
		}

		if (stp_trg==true){
         break;
		}

	} while(1);
	printf("\n");

	if(err_trig==0){
        		//вивід вектору коренів рівняння
      printf("***Ввдповіді***\n");
	  for (int i = 0; i < n; i++){
		printf("x%d= %f\n", i+1, x[i]);
	  }
	}

	//звільнення пам*яті, що займають масиви
          free(a);
          free(b);
          free(x);
          free(xp);

          fflush(stdin);
          printf("\nВведіть будь-що, щоб продовжити, або 'q', щоб вийти: ");
        }while(getchar()!='q');
        return 0;
    }
