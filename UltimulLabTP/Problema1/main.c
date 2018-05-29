#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FSTUD "studenti.txt"

void printVector(double *v,int m)
{
    int i = 0;
    for(i = 0;i < m;i++)
    {
        printf("%.2lf ",v[i]);
    }
    printf("\n");
}

void readFile(char *fName)
{
    FILE *f = fopen(fName,"rt");
    double *v1,*v2;
    int n1 = 0,n2 = 0;
    double nr,integral;
    if(f == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }else{
        v1 = (double*)malloc(sizeof(nr));
        v2 = (double*)malloc(sizeof(nr));
        while(fscanf(f,"%lf",&nr) == 1)
        {
            double fractional = modf(nr,&integral);
            if(fractional < 0.5)
            {
                n1++;
                v1 = (double*)realloc(v1,sizeof(nr) * n1);
                v1[n1-1] = nr;
            }else{
                n2++;
                v2 = (double*)realloc(v2,sizeof(nr) * n2);
                v2[n2-1] = nr;
            }
        }
        fclose(f);
        printVector(v1,n1);
        printVector(v2,n2);
    }
}

int main()
{
    readFile(FSTUD);
    return 0;
}
