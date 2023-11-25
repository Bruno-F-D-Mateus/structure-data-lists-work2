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

stations *initStations()
{
    stations *newStation = (stations *)malloc(sizeof(stations));
    newStation = NULL;
    return newStation;
}

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
        printf("Erro ao criar Rota");

    return NULL;
}

void printStation(routes *myRoute)
{
    stations *auxStation = myRoute->rt.sts;
    if (!auxStation)
        printf("Lista Vazia!\n");
    else
    {
        printf("Rota %d\n", myRoute->rt.code);

        while (auxStation->next != NULL)
        {
            printf("Paragem: %s - Qtd: %d\n", auxStation->st.name, auxStation->st.qty);
            auxStation = auxStation->next;
        }
        printf("Paragem: %s - Qtd: %d\n", auxStation->st.name, auxStation->st.qty);
    }
}

void printRoutes(routes *head)
{
    routes *aux = head;

    if (!head)
        printf("Lista Vazia!\n");
    else
    {
        while (aux->next != NULL)
        {
            printf("rota: %d\n", aux->rt.code);
            aux = aux->next;
        }
        printf("rota: %d\n", aux->rt.code);
    }
}

void createStationEnd(int code, char *name, int qty, routes *myRoutes)
{

    routes *auxRoute = getRouteByCode(code, myRoutes);

    if (auxRoute == NULL)
        printf("Rota nao existe!\n");
    else{
        if (auxRoute->rt.sts && !verifyStation(auxRoute->rt.sts, name))
            printf("Nao pode haver paragens repetidas\n");
        else{

            stations *newStation = (stations *)malloc(sizeof(stations));

            newStation->st.name = name;
            newStation->st.qty = qty;
            newStation->next = NULL;

            if (!auxRoute->rt.sts)
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

void getMaxQtyStation(int code, routes *myRoutes)
{
    routes *rt = getRouteByCode(code, myRoutes);

    if (rt == NULL)
        printf("Esta rota nao existe!");
    else
    {
        stations *maxStation = getMaxStation(rt->rt.sts);

        printf("Rota com paragem mais cheia: %s com %d passageiros!\n", maxStation->st.name, maxStation->st.qty);
    }
}

stations *getMaxStation(stations *rtStations)
{
    stations *sts = rtStations;
    stations *maxStation;

    int cont = 0;

    while (sts != NULL)
    {
        if (sts->st.qty > cont)
            maxStation = sts;

        sts = sts->next;
    }

    return maxStation;
}

routes *getRouteByCode(int code, routes *myRoutes)
{
    routes *aux = myRoutes;

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
    while (head->next != NULL)
        if (strcmp(head->st.name, name) == 0)
            return 0;
    
    return strcmp(head->st.name, name);
}

// Métodos getter e setter
stations *getStationHead(routes *myRoutes)
{
    return myRoutes->rt.sts;
}
