#include <stdio.h>
#include <stdlib.h>
#include "info.h"

//prototipul functiilor
void print();
void readCommand(char*,char*,char*);
void readConfigFile(char*);
void execEventFile(char*);
void writeOutput(char*);
void lucky_command(char*,char*,unsigned int);
void unlucky_command(char*,char*,unsigned int);
void turn(char*);
void complete_turn(char*);
void clasament(char*);
void close(char*);
//SALA(Lista) -> Mese(lista) -> Jucatori(Lista)
//1) citeste lista de jucatori -> normala
//2) citeste lista de mese -> circulara
//3) adaugam lista de mese cu toate datele la lista cu sali -> normala

void addElement(ALista head_ref, void *new_data, size_t data_size)
{
    int i = 0;
    // Allocate memory for node
    TLista new_node = (TLista)malloc(sizeof(Celula));

    new_node->info  = malloc(data_size);
    new_node->urm = (*head_ref);

    //alocate using 1 byte for x size
    for (i = 0; i < data_size; i++)
    {
        *(char *)(new_node->info + i) = *(char *)(new_data + i);
    }
    // Change head pointer as new node is added at the beginning
    (*head_ref) = new_node;
}
/*
TLista createList(void* data,size_t data_size,int n)
{
    printf("1) Test %s-%d\n",((Jucator)(data+1))->nume,((Jucator)(data+1))->nrMaini);
    TLista lst_playeri = NULL;
    int i ;
    for(i = n;i >= 0;i--)
    {
        //addElement(&lst_playeri,(data+i),data_size);
    }
    return lst_playeri;
}
*/
void printListaPlayeri(void* m)
{
    int maini = *(int *)(((Jucator)m)->nrMaini);
    printf("Player name : %s | Numar maini : %d \n",((Jucator)m)->nume,maini);
}
void printList(TLista node, void (*fptr)(void*))
{
    while (node != NULL)
    {
        (*fptr)(node->info);
        node = node->urm;
    }
}
void readCommand(char* configFile,char* eventFile,char* outputFile)
{
    //start all commands
      readConfigFile(configFile);
    //execEventFile(eventFile);
  //  writeOutput(outputFile);
}
void readConfigFile(char* configFile)
{
    FILE *file = fopen(configFile,"wt");
    if(file == NULL)
    {
        printf("Sala este inchisa !\n");
        exit(EXIT_FAILURE);
    }else{
        unsigned int nr_mese = 0;
        char *nume_masa;
        fscanf(file,"%d",&nr_mese);
        if(nr_mese <= 0)
        {
            printf("Sala este inchisa !\n");
            exit(EXIT_FAILURE);
        }else{
            while(feof(file))
            {
                //un for pt a itera prin toate mesele
                fscanf(file,"%s",nume_masa);
                //dim si nr de jucatori
                //citim restu de date si le adaugam
                //un for pt toate datele despre jucatori
            }
        }
    }
}
int main(int args,char* argc[])
{
     int i = 0,n = 2;
     //testing
     Jucator players = malloc(sizeof(Jucator) * n);
    (players+0)->nume = "John";
    (players+0)->nrMaini = 5;
    (players+1)->nume = "Bianca";
    (players+1)->nrMaini = 25;
    (players+2)->nume = "Iulian";
    (players+2)->nrMaini = 30;
    TLista lst_playeri = NULL;
   // TLista lst_p = createList(players,sizeof(players),n);
    for(i = n;i >= 0;i--)
    {
        addElement(&lst_playeri,(players+i),sizeof(players));
    }
    printList(lst_playeri,printListaPlayeri);

    /*
    //here the program starts...\
    if(args != 4)
    {
        printf("Comanda invalida | tema1 <list1> <lista2> <output>");
        exit(EXIT_FAILURE);
    }else{
        //read data
        readCommand(argc[1],argc[2],argc[3]);
    }
    */
    return 0;
}
