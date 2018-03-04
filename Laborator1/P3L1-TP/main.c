#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N_MAX 4

int citeste_numere(int a[], int n)
{
    char c[40];
    int i = 0,j = 0;
    while(i < n && scanf("%s",c) != 0 && c != "\n")
    {
        for(j = 0; j < strlen(c);j++)
        {
            if(c[j] == ' ' || (c[j] >= 'a' && c[j] <= 'z') || (c[j] >= 'A' && c[j] <= 'Z'))
                continue;

            if(c[j] == EOF)
                return -1;
        }
        a[i] = atoi(c);
        i++;
     }
     return i;
}
int main(void)
{
	int a[N_MAX];
	int i, k;
	while ((k = citeste_numere(a, N_MAX)) != -1) {
		printf("Am citit %d numere:", k);
		for (i = 0; i < k; i++)
			printf(" %d", a[i]);
		printf("\n");
    }
	return 0;
}
