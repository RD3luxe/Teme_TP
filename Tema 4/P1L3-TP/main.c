#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int starts_with(char *s1,char *s2)
{
    int ok = 1;
    char *ss = NULL;
    if(strlen(s2) > strlen(s1))
        ok = 0;
    else
    {
        strcpy(ss,s1);
        ss[strlen(s2)] = '\0';
        if(strcmp(s1,ss) != 0)
        {
            printf("%s - %s",s1,ss);
            ok = 0;
        }
    }
    return ok;
}
int ends_with(char *s1,char *s2)
{
    int ok = 1;
    if(strlen(s2) > strlen(s1))
        ok = 0;
    else
    {
        char *ss;
        while((ss = strstr(ss,s2)) != NULL)
        {
            if((strlen(s1) - strlen(s2) + strlen(ss)) == 0)
                ok  = 1;
            else
                ok  = 0;
            printf("%d - %d + %d\n",strlen(s1) , strlen(s2),strlen(ss));
            ss = strstr(ss,s2);
        }
    }
    return ok;
}
int main()
{
    char s1[50],s2[50];
    printf("Introdu primul sir : ");
    scanf("%s",s1);
    printf("Introdu sirul 2 : ");
    scanf("%s",s2);
    if(starts_with(s1,s2))
    {
        printf("Sirul s1 incepe cu sirul s2.\n");
    }
    else if(ends_with(s1,s2))
    {
       printf("Sirul s1 se termina cu sirul s2.\n");
    }else
        printf("Nici una dintre variante.\n");
    return 0;
}
