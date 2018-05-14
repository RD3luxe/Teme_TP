#include <stdio.h>
#include <stdlib.h>

#define FILENAME "date.txt"
#define FILENAME2 "rezultate.txt"

int main()
{
    int nr;
    char cuv[11];
    FILE *f = fopen(FILENAME,"rt");
    FILE *g = fopen(FILENAME2,"wt");
    if(f != NULL)
    {
        fscanf(f,"%s",cuv);
        while(!feof(f))
        {
            fscanf(f,"%d",&nr);
            fprintf(g,"%c ",cuv[nr]);
        }
        fclose(f);
        fclose(g);
    }else{
        printf("Fisierul %s nu a putu fi deschis.\n",FILENAME);
        exit(1);
    }
    return 0;
}
