#include <stdio.h>

float max(float v[100],int n)
{
    int i;
    float maxx;
    maxx = v[0];
    for(i = 1;i < n;i++)
    {
        if(v[i]>maxx)
            maxx = v[i];
    }
    return maxx;
}

int main()
{
    int N,i;
    float a[100];
    printf("Introduceti numarul N: ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        printf("a[%d] = ",i);
        scanf("%f",&a[i]);
    }
    float maxim = max(a,N);
    printf("Numarul maxim din vector este %.3f.",maxim);
    return 0;
}
