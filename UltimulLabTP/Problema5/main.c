#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 60

typedef struct automobil
{
    char marca[MAX],culoare[MAX];
    unsigned int nr_locuri : 6;
    unsigned int putere : 9;
    unsigned int an_fabricatie : 11;
}automobil;

void meniu()
{
    printf("\n1.Adauga automobil\n");
    printf("2.Afiseaza automobile cu mai mult de 5 locuri\n");
    printf("3.Ordoneaza automobile crescator dupa putere\n");
    printf("4.Afiseaza automobile fabricate in un anumit an\n");
    printf("Optiunea ta : ");
}

void addAuto(automobil **a,int *nr)
{
    unsigned int locuri,putere,an_fab;
    printf("Marca : ");
    scanf("%s",(*a+*nr)->marca);
    printf("Culoare : ");
    scanf("%s",(*a+*nr)->culoare);
    printf("Nr. locuri : ");
    scanf("%d",&locuri);
    printf("Putere : ");
    scanf("%d",&putere);
    printf("An fabricare : ");
    scanf("%d",&an_fab);
    (*a+*nr)->nr_locuri = locuri;
    (*a+*nr)->putere = putere;
    (*a+*nr)->an_fabricatie = an_fab;
    (*nr)++;
}

void afisare_masina(automobil *a,int index)
{
    printf("| Marca : %s | Culoare : %s | Nr. locuri : %d | Putere : %d | An fabricare : %d |\n",a[index].marca,a[index].culoare,
           a[index].nr_locuri,a[index].putere,a[index].an_fabricatie);
}

void afisare_auto(automobil *a,int nr)
{
    int i = 0;
    for(i = 0;i < nr;i++)
    {
        if(a[i].nr_locuri >= 5)
        {
            afisare_masina(a,i);
        }
    }
}

void swap(automobil *a1,automobil *a2)
{
    automobil temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void qs(automobil *a,int l,int r)
{
    int i = l;
    int j = r;
    automobil x = a[(l+r)/2];//calc mijloc
    do
    {
        while(i < r && a[i].putere < x.putere) i++;
        while(j > l && a[j].putere > x.putere) j--;
        if(i <= j)
        {
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }while(i <= j);
    if(l < j) qs(a,l,j);
    if(i < r) qs(a,i,r);
}

//ordonare -> quick sort cel mai rapid
void ordonare(automobil *a,int nr)
{
    qs(a,0,nr-1);
}

void automFabricateAn(automobil *a,int nr,unsigned int an)
{
    int i = 0;
    for(i = 0;i < nr;i++)
    {
        if(a[i].an_fabricatie == an)
        {
            afisare_masina(a,i);
        }
    }
}

int main()
{
    int n,nr = 0,opt;
    unsigned int an;
    printf("Numarul maxim de automobile : ");
    scanf("%d",&n);
    automobil *a = (automobil*)malloc(sizeof(automobil) * n);//alocare dinamica
    do
    {
        meniu();
        scanf("%d",&opt);
        switch(opt)
        {
            case 1 :
                //adauga automobile
                if(nr >= n)
                {
                    printf("Numarul maxim de automobile din parcul de automobile a fost atins.\n");
                    break;
                }
                addAuto(&a,&nr);
                break;
            case 2 :
                //afisare toate cu > 5 locuri
                afisare_auto(a,nr);
                break;
            case 3 :
                //sortare
                ordonare(a,nr);
                int i = 0;
                for(i = 0;i < nr;i++)
                {
                    afisare_masina(a,i);
                }
                break;
            case 4 :
                printf("An : ");
                scanf("%d",&an);
                automFabricateAn(a,nr,an);
                break;
            default :
                opt = 0;
                exit(1);
                break;
        }
    }while(opt != 0);
    return 0;
}
