#include <stdio.h>

int verifica_cifra(int nr,int c)
{
    while(nr != 0)
    {
        if((nr%10) == c)
            return 1;
        else
            nr /= 10;
    }
    return 0;
}
int main()
{
    int numar,cif,i;
    printf("Introdu numarul : ");
    scanf("%d",&numar);
    CIFRA:
    printf("Introdu cifra cautata : ");
    scanf("%d",&cif);
    if(cif < 0 || cif > 9)
    {
        printf("Trebuie sa introduci o cifra nu un numar !!!\n");
        goto CIFRA;
    }
    printf("Numarul %d %s %d.\n",numar,verifica_cifra(numar,cif) == 1? "contine cifra":"nu contine cifra",cif);
    //pt un n
    int n;
    printf("Introdu numarul pana la care cauta : ");
    scanf("%d",&n);
    for(i = 1;i <= n;i++)
    {
         printf("Numarul %d %s %d.\n",i,verifica_cifra(i,cif) == 1? "contine cifra":"nu contine cifra",cif);
    }
    return 0;
}
