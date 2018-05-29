#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MFILE "Materii.txt"

#define MAX 60
typedef struct info
{
    char nume_mat[MAX];
    float nota;
    int medie_facuta;
}info;
typedef struct lista
{
    info materie;
    struct lista *next;
}List;

void printFile(List* head)
{
    if (head == NULL)
       return;

    printFile(head->next);
    printf("%s %.2f\n",head->materie.nume_mat,head->materie.nota);
}
float medieMaterie(List *l,char *nume)
{
    List *curen = l;
    int sum = 0,nr = 0;
    float media = 0;
    for(curen = l; curen != NULL; curen = curen->next)
    {
        if(strcmp(curen->materie.nume_mat,nume) == 0)
        {
            sum += curen->materie.nota;
            curen->materie.medie_facuta = 1;
            nr++;
        }
    }
    media = (float)sum/nr;
    return media;
}
void afisareMedie(List *l)
{
    List *curen = l;
    float medie = 0;
    for(curen = l; curen != NULL; curen = curen->next)
    {
        if(curen->materie.medie_facuta == 0)
        {
           printf("%s ",curen->materie.nume_mat);
           medie = medieMaterie(curen,curen->materie.nume_mat);
           printf("%.2f\n",medie);
        }
    }
}
void DoMedia(List *l,float *media)
{
    List *curen = l;
    int sum = 0,nr = 0;
    for(curen = l; curen != NULL; curen = curen->next)
    {
        sum += curen->materie.nota;
        nr++;
    }
    *media = (float)sum/nr;
}
int main()
{
    List *materii = NULL;
    FILE *f = fopen(MFILE,"rt");
    if(f == NULL)
    {
        printf("Fisierul nu exista.\n");
        exit(1);
    }else{
        float media_notelor = 0;
        float nota;
        char nume[MAX];
        while(fscanf(f,"%s %f",nume,&nota) == 2)
        {
            List *nod = (List*)malloc(sizeof(List));
            strcpy(nod->materie.nume_mat,nume);
            nod->materie.nota = nota;
            nod->materie.medie_facuta = 0;
            nod->next = materii;
            materii = nod;
        }
        List *temp_list = materii;
        printFile(temp_list);
        printf("\nMedia pt fiecare materie : \n");
        afisareMedie(materii);
        fclose(f);
        DoMedia(materii,&media_notelor);
        FILE *g = fopen("Materii.out","wb");
        fwrite(&media_notelor,sizeof(media_notelor),1,g);
        fclose(g);
        media_notelor = 0;
        g = fopen("Materii.out","rb");
        fread(&media_notelor,sizeof(media_notelor),1,g);
        fclose(g);
        printf("\n%.2f",media_notelor);
        free(materii);
    }
    return 0;
}
