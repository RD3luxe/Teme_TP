#include <stdio.h>
#include <stdlib.h>

//metoda cu returnare de variabila
int *create_vector(int siz)
{
    int *a = (int*)malloc(sizeof(int) * siz);
    return a;
}
//metoda cu referinta
void create_vector2(int **a,int siz)
{
    *a = (int*)malloc(sizeof(int) * siz);
}
void show_vector(int *a,int siz)
{
    int i = 0;
    static int count = 1;
    printf("Vectorul %d este : ",count);
    for(i = 0;i < siz;i++)
    {
        printf("%d ",*(a+i));
    }
    printf("\n");
    count++;
}
int main()
{
    int *imp,*par;
    int n,i = 0,p = 0,k = 0;
    printf("Introduceti n : ");
    scanf("%d",&n);
    create_vector2(&imp,n/2);
    par = create_vector(n/2);
    for(i = 0;i < n;i++)
    {
        if(i%2 == 0)
        {
            *(par+p) = i;
            p++;
        }else{
            *(imp+k) = i;
            k++;
        }
    }
    show_vector(imp,k);
    show_vector(par,p);
    free(imp);
    free(par);
    return 0;
}
