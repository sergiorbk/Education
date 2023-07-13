#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
void createFile(char *file_name);
bool main_menu(char choise);

struct record{
    char name[40];
    int square;
    int population;
};
char *root_path="E:/Work/C/9.9-file-manager/appdata/$root.txt";
FILE *root;
FILE *file;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool exit=0;
    do{
        system("cls");
        printf("Simple Data Commander\n");
        printf("����\n\n������ � �������\n");
        printf("1-�������� �����\n2-������ ����\n0-�����\n");
        fflush(stdin);
        exit=main_menu(getch());
    }while(!exit);
    return 0;
}
bool main_menu(char choise){
        switch(choise){
        case '1':
            system("cls");
            printf("Simple Data Commander\n");
            fflush(stdin);
            printf("***��������� ������ ���������� �����***\n");
            printf("\n������ ��'� ������ �����: ");
            char file_name[50];
            fflush(stdin);
            gets(file_name);
            printf("���� �������� ����� ���� %s.txt\n", file_name);
            printf("[y]-���������� [d]-������������ [q-������� ����]\n");
            fflush(stdin);
            switch(getch()){
            case 'y':
                createFile(file_name);
                break;
            case 'd':
                main_menu('1');
                break;
            case 'q':
                main_menu('0');
                break;
            default:
                main_menu('0');
            }
            printf("�������� �� ����-��� ������, ��� ���������� �� ��������� ����.");
            getch();
            break;
        case '2':
            system("cls");
            printf("Simple Data Commander\n");
            fflush(stdin);
            printf("***�����***\n");
            int files=readDirectory();//������� �����
            root = fopen("E:\\Work\\C\\9.9-file-manager\\appdata\\$root.txt", "r");

            char root_str[100][100];
            int root_i=0;
            while(fgets(root_str[root_i], 80, root)!=NULL){
                printf("[%d] -> %s",root_i, root_str[root_i]);
                root_i++;
            }
               fclose(root);
               printf("***\n");

               printf("\n\n\n%s.\n\n\n", root_str[0]);

            int fl_ch=0;
            do{
                printf("������ ���� ��� ������[0-%d]: ", files);
                fflush(stdin);
                scanf("%d", &fl_ch);
            }while(fl_ch>=root_i||fl_ch<0);

            printf("\n Opening %s...\n", root_str[fl_ch]);

            char rtn[100]="E:\\Work\\C\\9.9-file-manager\\appdata\\files\\";

            //printf("ADSASDSADASDASDS: %c\n", root_str[2][5]);
            for(int i=0; i<strlen(root_str[fl_ch]); i++){
                rtn[strlen(rtn)]=root_str[fl_ch][i];
                printf("%s\n", rtn);
            }

            //strcat(rtn, root_str[fl_ch]);
            //strcat(rtn, "lox.txt");
            printf("\nFINAL PATH: %s, LEN=%d\n", rtn, strlen(rtn));
            getch();
            //char *ukaz=rtn;
            fileMenu(rtn);
            break;
    }
}

void fileMenu(char path[100]){
    system("cls");
    printf("Simple Data Commander\n");
    fflush(stdin);
    printf("***ĳ� � ������***\n");
    printf("%s)\n", path);
    printf("[1]->����������� ������\n[2]->�������� ����� �����\n[3]->��������� ������\n");
    printf("[4]->����������� ������\n[5]->������������� ������\n[6]->�������� ����\n\n[q]-������� ����");
    fflush(stdin);

    FILE*temp_file = fopen("E:\\Work\\C\\9.9-file-manager\\appdata\\files\\first.txt", "a");
    switch(getch()){
        case '1':
            system("cls");
            char str[100];
            while(fgets(str, 90, temp_file)!=NULL){
                printf("%s\n", str);
            }
            fclose(temp_file);
            getch();
            break;
        case '2':
            system("cls");
            int recourd_amount=records_amount();
            printf("Amount of records: %d\n", records_amount);
            char area_name[50];
            printf("������ ����� ������: ");
            scanf("%s", &area_name);
            int area_square;
            printf("������ �����: ");
            scanf("%d", &area_square);
            char area_population;
            printf("������ ������� ���������: ");
            scanf("%d", &area_population);
            fprintf(temp_file,"\t%d\t%s\t%d\t%d\t\n", records_amount, area_name, area_square, area_population);
            getch();
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            deleteFile(path);
            break;
        case 'q':
            break;
    }
}

void deleteFile(char path[100]){
    printf("Deleting %s\n", path);
    printf ("�������� �����: ");
     if( remove(path) != 0 )
      perror( "Could not delete" );
   else
      printf( "Deleted \n" );
    getch();
}

void createFile(char *file_name){
    char file_path[100]="appdata\\files\\";
    strcat(file_path, file_name);
    strcat(file_path, ".txt");
    file = fopen(file_path, "a+");
    if(file==NULL){
        printf("Error occured while creating %s.txt\n", file_name);
    }else{
    printf("%s.txt was successfully created.\n", file_name);
    fprintf(file, "\t***NAME***\t***SQUARE***\t***POPULATION***\t\n");
    }
    fclose(file);
}

int readDirectory(){
      DIR *folder=opendir("E:/Work/C/9.9-file-manager/appdata/files");
      struct dirent *entry;
      int files=0;
      if(folder == NULL){
        perror("Unable to read directory.");
        return -1;
      }else{
         root = fopen(root_path, "w");
         for(files=1; entry=readdir(folder); files++){
            if(files!=1&&files!=2){
              char *file_name=file_name=entry->d_name;
             // printf("SIZEOF FILENAME DIRENT=%d\n", strlen(file_name));
              //printf("%s\n", file_name);
              fprintf(root,"%s\n",file_name);
             }
         }
          fclose(root);
        }
    return files-3;
}

int records_amount(){
            system("cls");
            FILE*temp_file = fopen("E:\\Work\\C\\9.9-file-manager\\appdata\\files\\first.txt", "r");
            char str[100];
            int i=-1;
            while(fgets(str, 90, temp_file)!=NULL){
                //printf("%s\n", str);
                i++;
            }
            fclose(temp_file);
            return i;
}
