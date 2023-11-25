#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

struct Station
{
    char *name;
    int qty;
};

struct Stations
{
    struct Station st;
    struct Stations *prev;
    struct Stations *next;
};

struct Route
{
    int code;
    struct Stations *sts;
};

struct Routes
{
    struct Route rt;
    struct Routes *prev;
    struct Routes *next;
};

routes *initRoutes()
{
    routes *newRoutes = (routes *)malloc(sizeof(routes));
    newRoutes = NULL;
    return newRoutes;
}

// Código é criado de forma automática
routes *createRouteBegin(routes *head)
{
    routes *newRoute = (routes *)malloc(sizeof(routes));

    if (newRoute)
    {

        newRoute->rt.code = 1 + countRts(head);
        newRoute->rt.sts = NULL;
        newRoute->prev = NULL;

        if (!head)
            newRoute->next = NULL;
        else
        {
            head->prev = newRoute;
            newRoute->next = head;
        }

        return newRoute;
    }
    else
        printf("Erro ao criar Rota\n");

    return NULL;
}

void printStation(routes *myRoute)
{
    stations *auxStation = myRoute->rt.sts;
    if (!auxStation)
        printf("Lista Vazia!\n\n");
    else
    {
        printf("Rota %d\n", myRoute->rt.code);
        while (auxStation->next != NULL){
            printf("Paragem: %s - Qtd: %d\n", auxStation->st.name, auxStation->st.qty);
            auxStation = auxStation->next;
        }
        printf("Paragem: %s - Qtd: %d\n\n", auxStation->st.name, auxStation->st.qty);
    }
}

void printRoutes(routes *head)
{
    routes *aux = head;

    if (!head)
        printf("Lista Vazia!\n\n");
    else
    {
        while (aux->next != NULL)
        {
            printf("rota: %d\n", aux->rt.code);
            aux = aux->next;
        }
        printf("rota: %d\n\n", aux->rt.code);
    }
}

void createStationEnd(int code, char *name, int qty, routes *myRoutes)
{
    routes *auxRoute = getRouteByCode(code, myRoutes);

    if (auxRoute == NULL)
        printf("Rota nao existe!\n\n");
    else
    {

        if (auxRoute->rt.sts && !verifyStation(auxRoute->rt.sts, name))
            printf("Nao pode haver paragens repetidas\n\n");
        else
        {

            stations *newStation = (stations *)malloc(sizeof(stations));

            newStation->st.name = name;
            newStation->st.qty = qty;
            newStation->next = NULL;
            if(!newStation)
                printf("Erro na alocação\n");
            else if (!auxRoute->rt.sts)
            { // primeiro elemento
                newStation->prev = NULL;
                auxRoute->rt.sts = newStation;
            }
            else
            { // outros elementos
                stations *auxStations = auxRoute->rt.sts;

                while (auxStations->next != NULL)
                    auxStations = auxStations->next;
                
                auxStations->next = newStation;
                newStation->prev = auxStations;
            }
        }
    }
}

void printMaxStation(int code, routes *head)
{
    routes *auxRoute = getRouteByCode(code, head);
    if(!auxRoute)
        printf("Rota nao Existe!\n\n");
    else{
        stations *auxStation = auxRoute->rt.sts;
        stations *maxStation = (stations*)malloc(sizeof(stations));

        if(!auxStation)
            printf("Nao existem paragens nessa Rota!\n\n");
        else{
            //pegando os primeiros elementos
            char *name = auxStation->st.name;
            int qty = auxStation->st.qty;

            
            while (auxStation->next !=NULL){
                if(qty < auxStation->st.qty){
                    name = auxStation->st.name;
                    qty = auxStation->st.qty; 
                }
                auxStation = auxStation->next;
            }
            if(qty < auxStation->st.qty){
                name = auxStation->st.name;
                qty = auxStation->st.qty; 
            }
            printf("Rota %d\nParagem mais Lucrativa %s com %d passageiros\n\n", auxRoute->rt.code,name,qty);
        }
    }
}

routes *getRouteByCode(int code, routes *head)
{
    routes *aux = head;

    if (aux == NULL)
        return NULL;

    if (aux->rt.code == code)
        return aux;

    return getRouteByCode(code, aux->next);
}

int countRts(routes *rts)
{
    int cont = 0;
    routes *aux = rts;

    return aux == NULL ? 0 : 1 + countRts(aux->next);
}

int verifyStation(stations *head, char *name)
{
    stations *auxStation = head;
    while (auxStation->next != NULL){
        if (strcmp(auxStation->st.name, name) == 0)
            return 0;
        auxStation = auxStation->next;
    }

    return strcmp(head->st.name, name);
}
