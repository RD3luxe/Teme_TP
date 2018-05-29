#include <stdio.h>
#define BIT_NUM 32

int pozitie(int nr)
{
    int i = 0,k;
    for(i = 0;i < BIT_NUM;i++)
    {
        if(((nr>>i)&1) == 1)
        {
            k = i;
        }
    }
    return k;
}
int main()
{
    int n;
    printf("Introduceti numarul n : ");
    scanf("%d",&n);
    int poz = pozitie(n);
    printf("Pentru nr %d cel mai din stanga unu este pe pozitia : %d\n",n,poz);
    return 0;
}
