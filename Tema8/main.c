#include <stdio.h>
#include <math.h>

#define PI 3.14159
typedef float (*fp)(float,float);

float f(float x,float y)
{
    return x*y - y;
}
float g(float x,float y)
{
    return x/y + y/x;
}
float h(float x,float y)
{
    return x-y + x/(2*x);
}
float k(float x,float y)
{
    return cos(PI * x/y);
}
void showVal(fp f[],float x, float y)
{
    int i = 0;
    char fct_name[] = {'f','g','h','k'};
    for(i = 0;i < 4;i++)
    {
        printf("%c(%f,%f) = %f\n",fct_name[i],
               x,y,f[i](x,y));
    }
    printf("\n");
}
void tabelare(fp f[],float x,float y)
{
    int i = 0;
    char fct_name[] = {'f','g','h','k'};
    printf("\n");
    for(;x <= y;x++)
    {
        for(i = 0;i < 4;i++)
        {
            printf("%c(%f,%f) = %f\n",fct_name[i],
                   x,y,f[i](x,y));
        }
        printf("\n\n");
    }
}
int main()
{
    float x,y;
    printf("x = ");
    scanf("%f",&x);
    printf("y = ");
    scanf("%f",&y);
    fp functions[4];
    functions[0] = &f;
    functions[1] = &g;
    functions[2] = &h;
    functions[3] = &k;
    showVal(functions,x,y);
    float a,b;
    printf("Introduceti intervalul pt tabelare\na = ");
    scanf("%f",&a);
    printf("b = ");
    scanf("%f",&b);
    tabelare(functions,a,b);
    return 0;
}
