#include <stdio.h>
#include <stdlib.h>
#define MAX 33

typedef struct Info
{
    char nume_strada[MAX];
    int nr_locuinte;
    char zona; //c,b or m
}Info;

Info *create_vector(int siz)
{
    Info *a = (Info*)malloc(sizeof(Info) * siz);
    return a;
}
void show_info(Info *i,int index)
{
    printf("Nume strada : %s | Nr locuinte : %d | Zona : %c |\n",(i+index)->nume_strada,
           (i+index)->nr_locuinte,(i+index)->zona);
}
void show_vector(Info *a,Info *din,int siz_n)
{
    int i = 0,k = 0;
    for(i = 0;i < siz_n;i++)
    {
        if((a+i)->zona == 'C')
        {
            *(din+k) = *(a+i);
            show_info(din,k);
            k++;
        }
    }
}
void add_info(Info *i,int *nr,int *s_b)
{
    if((*nr) >= 10) //numaram de la 0 si astfel ajungem la fix 10 input-uri fix
    {
        printf("Numarul maxim de informatii a fost atins.\n");
    }else{
        printf("Nume strada : ");
        scanf("%s",(i+(*nr))->nume_strada);
        printf("Nr de locuinte : ");
        scanf("%d",&((i+(*nr))->nr_locuinte));
        printf("Zona : ");
        scanf(" %c",&((i+(*nr))->zona));
        if((i+(*nr))->zona == 'C')
            (*s_b)++;
        (*nr)++;
    }
}
void show_allinfo(Info *a,int dim)
{
    int i = 0;
    for(i = 0;i < dim;i++)
    {
        show_info(a,i);
    }
}
int main()
{
    Info info[50];
    Info *info_din;
    int nr = 0,choose,dim_info = 0;
    do
    {
        printf("\n1)Adauga informatie\n");
        printf("2)Afiseaza toate informatiile\n");
        printf("3)Creare vector dinamic cu case\n");
        printf("4)Iesire\n");
        printf("Introdu decizia ta : ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1 :
                add_info(info,&nr,&dim_info);
                break;
            case 2 :
                show_allinfo(info,nr);
                break;
            case 3 :
                if(dim_info <= 0)
                {
                    printf("Nu puteam crea dinamic vectorul, prea putine entry-uri.\n");
                }else{
                    info_din = create_vector(dim_info);
                    show_vector(info,info_din,nr);
                    free(info_din);
                }
                break;
            case 4 :
                //goto default
            default:
                choose = 0;
                break;
        }
    }while(choose != 0);
    return 0;
}
