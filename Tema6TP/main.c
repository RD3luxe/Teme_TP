#include <stdio.h>

typedef struct animal
{
    char abreviere[9]; //ultimul e pt \0
    float greutate;
    unsigned short nr_picioare : 10;
    unsigned short periculos : 1;
    unsigned short varsta : 11;

}animal;

int main()
{
    animal anim;
    unsigned short nr_p,pericol,age;
    printf("Nume abreviat : ");
    scanf("%s",anim.abreviere);
    printf("Greutate in kg : ");
    scanf("%f",&anim.greutate);
    printf("Varsta in ani(max 1000) : ");
    scanf("%hu",&age);
    printf("Numar picioare(max 2000): ");
    scanf("%hu",&nr_p);
    printf("Periculos pt om (1/0) : ");
    scanf("%hu",&pericol);
    anim.nr_picioare = nr_p;
    anim.periculos = pericol;
    anim.varsta = age;
    printf("Nume abreviat : %s | Greutate in kg : %.2f | Varsta : %hu | Numar picioare : %hu | Periculos pt om : %hu |\n"
           ,anim.abreviere,anim.greutate,anim.varsta,anim.nr_picioare,anim.periculos);
    printf("Spatiul ocupat de structura este de %d bytes\n",sizeof(anim));
    return 0;
}
