#include <stdio.h>
#define BIT_NUM 32

int nr_one(int n)
{
    int i = 0,nr = 0;
    for(i = 0;i < BIT_NUM;i++) //pe 32 de biti
    {
        if(((n>>i)&1) == 1)
        {
           nr++;
        }
    }
    return nr;
}
int main()
{
    int n,nr_1 = 0;
    printf("Introduceti numarul n : ");
    scanf("%d",&n);
    nr_1 = nr_one(n);
    printf("Numarul %d contine %d de unu.\n",n,nr_1);
    return 0;
}
