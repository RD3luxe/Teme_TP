#include<stdio.h>
#include<stdlib.h>

#define NUME_FILE "studenti.txt"
#define WRITE_NAME "prelucrat.txt"
#define MAX 50

typedef struct student
{
    char name[MAX];
    float medie;
}student;

float medie(student *s,int nr)
{
    int i = 0;
    float md = 0;
    for(i = 0;i < nr;i++)
    {
        md += (s+i)->medie;
    }
    printf("%.2f - %d",md,nr-1);
    md = md/(nr-1);
    return md;
}
void readFile(char *f1,char *w1)
{
    student s[100];
    int nr = 0;
    FILE *f = fopen(f1,"rt");
    FILE *g = fopen(w1,"wt");
    int max = 0,save_indx = -1;
    if(f != NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%s",(s+nr)->name);
            fscanf(f,"%f",&(s+nr)->medie);
            if((s+nr)->medie > max)
            {
                max = (s+nr)->medie;
                save_indx = nr;
            }
            nr++;
        }
        fclose(f);
        fprintf(g,"Media : %.2f\n",medie(s,nr));
        fprintf(g,"Cea mai mare nota : %s %.2f\n",(s+save_indx)->name,(s+save_indx)->medie);
    }else{
        printf("Fisierul %s nu a putu fi deschis.\n",NUME_FILE);
        exit(1);
    }
}
int main()
{
    readFile(NUME_FILE,WRITE_NAME);
    return 0;
}
