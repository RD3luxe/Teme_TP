#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned int num)
{
   int bit = 0;
   for(bit = 7;bit >=0 ; bit--)
   {
      printf("%d", (num&1<<bit)? 1:0);
   }
   printf("\n");
}
int main()
{
    //1
    unsigned int nr1,nr2,nr3;
    printf("P1)\n");
    printf("Primul numar : ");
    scanf("%d",&nr1);
    printf("Al 2-lea numar : ");
    scanf("%d",&nr2);
    printBits(nr1);
    printBits(nr2);
    nr3 = ~nr1&nr2;
    printBits(nr3);
    /*
    0001 0010
    0000 1010
    0000 1000
    */
    //2
    unsigned int nr4;
    printf("P2)\n");
    printf("Primul numar : ");
    scanf("%d",&nr1);
    printf("Al 2-lea numar : ");
    scanf("%d",&nr2);
    printf("Al 3-lea numar : ");
    scanf("%d",&nr3);
    nr4 = nr1&nr2;
    nr4 &= nr3;
    printBits(nr1);
    printBits(nr2);
    printBits(nr3);
    printBits(nr4);
    /*
    1000 1001
    0100 1001
    0001 1001
    0000 1001
    */
    //3
    printf("P3)\n");
    printf("Numar : ");
    scanf("%d",&nr1);
    printBits(nr1);
    nr1 ^= 0x55;
    printBits(nr1);
    /*
    0100 1010
    0101 0101
    0001 1111
    */
    //4
    int n,i;
    printf("P4)\n");
    printf("Numar : ");
    scanf("%d",&nr1);
    printf("N : ");
    scanf("%d",&n);
    printBits(nr1);
    for(i = 0; i <= n;i++)
    {
        nr1 = nr1 & ~(1 << i);
    }
    printBits(nr1);
    /*
    0100 1001
    4
    0100 0000
    */
    //5
    printf("P5)\n");
    printf("Numar : ");
    scanf("%d",&nr1);
    printBits(nr1);
    nr1 = nr1&(~37);
    printBits(nr1);
    /*
    1010 0011
   ~0010 0101
    1000 0010
    */
    return 0;
}
