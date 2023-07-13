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
      printf("***���������� ���� ������� ������� ��������***\n");
      printf("**********************************************\n");
      int i, j;
      //��� ��������� ����
      int n=0;
      do{
        printf("������ ������� ������ ���� (>0): ");
        fflush(stdin);
        scanf("%d", &n);
      }while(n<=0);
      double tochnist=0;
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
     printf("\n***Obroblena tochnist: %lf\n", tochnist);
    }

      //���� ������ ����
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
       //����� ������ ������ ����

       //���������� ������� ����� � ������ ������ ������
       double **a = (double**)malloc(n * sizeof(double*));//������� ���� ������ ������
       double *b = (double*)malloc(n * sizeof(double));//������ ������ ������ ������
       for(i=0; i<n; i++){
         a[i]=(double*)malloc(n*sizeof(double));
         printf("\n");
        for(j=0; j<=n; j++){
            if(j<n){
                printf("������ a%d%d: ", i+1, j+1);
                fflush(stdin);
                scanf("%lf*", &a[i][j]);
            }else{
                printf("������ b%d: ", i+1);
                fflush(stdin);
                scanf("%lf*", &b[i]);
            }
        }
    }//����� ����������

    //������� ���������
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

				if(a[i][i]==fabs(check_summ)){//�������� ����� �� ���. ���. ������� ��������
                err_trig=1;
                }
			}//����� for j

		}//����� for i

		if(err_trig==1){
            printf("\n�������! �� ���� ��������� ����'����� ������� ������� ��������.\n");
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
        		//���� ������� ������ �������
      printf("***�������***\n");
	  for (int i = 0; i < n; i++){
		printf("x%d= %f\n", i+1, x[i]);
	  }
	}

	//��������� ���*��, �� �������� ������
          free(a);
          free(b);
          free(x);
          free(xp);

          fflush(stdin);
          printf("\n������ ����-��, ��� ����������, ��� 'q', ��� �����: ");
        }while(getchar()!='q');
        return 0;
    }
