#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char terro[] = "terorist";
    char done[] = "gata";
    char s[60];
    char *ptr;
    int stop = 0;
    do
    {
        fgets(s,60,stdin);
        s[strlen(s)-1] = '\0';
        ptr = strstr(s,done);
        if(ptr != NULL)
        {
            stop = 1;
        }
        if(stop == 1) break;
        ptr = strstr(s,terro);
        if(ptr != NULL)
        {
            printf("Text suspect\n");
        }else{
             printf("Nimic suspect\n");
        }
    }while(stop != 1);
    return 0;
}
