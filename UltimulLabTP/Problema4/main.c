#include <stdio.h>
#include <math.h>

typedef float (*fx)(float);

float f(float x)
{
    return pow(x,4) + pow(x,3);
}
float g(float x)
{
    return x - pow(x,2);
}
float h(float x)
{
    return (x+1)/(x-1);
}
float t(float x)
{
    return pow(x,2)/2;
}
void calcFunctii(fx f[4],float x)
{
    int i = 0;
    char c[4] = {'f','g','h','t'};
    for(i = 0;i < 4;i++)
    {
        printf("%c(%.2f) = %.2f\n",c[i],x,f[i](x));
    }
    printf("\n");
}
void tabelare(fx f[4],float A,float B)
{
    for(;A <= B;A++)
    {
        calcFunctii(f,A);
    }
}
int main()
{
    fx functii[4];
    functii[0] = &f;
    functii[1] = &g;
    functii[2] = &h;
    functii[3] = &t;
    float A,B,d;
    int N;
    printf("A : ");
    scanf("%f",&A);
    printf("B : ");
    scanf("%f",&B);
    printf("N : ");
    scanf("%d",&N);
    d = (B-A)+1; //aflu cate nr sunt in total 2 5 = 5-2 + 1 = 4
    N = d/N;//impart intervalul 2
    A = A+N;//2+2 = 4 => 4,5 2 pcte
    tabelare(functii,A,B);
    return 0;
}
