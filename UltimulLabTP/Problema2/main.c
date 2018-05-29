#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 60

int main()
{
    char cuv[MAX];
    int nr_cuvinte = 0;
    char *cuvinte = (char*)malloc(sizeof(char));
    while(scanf("%s",cuv) != EOF)
    {
        nr_cuvinte++;
        cuvinte = (char*)realloc(cuvinte,sizeof(cuv) * nr_cuvinte + nr_cuvinte);
        strcat(cuv," ");
        strcat(cuvinte,cuv);
    }
    printf("%s",cuvinte);
    return 0;
}
