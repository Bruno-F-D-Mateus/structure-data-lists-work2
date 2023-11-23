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
    struct Stations *prox;
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
    struct Routes *prox;
};

stations *initStations()
{
    stations *newStation = (stations *)malloc(sizeof(stations));

    return newStation;
}

routes *initRoutes()
{
    routes *newRoutes = (routes *)malloc(sizeof(routes));

    return newRoutes;
}

// Código é criado de forma automática
void *createRoute(routes *myRoutes)
{

    routes *newRoute = (routes*)malloc(sizeof(routes));

    if (newRoute != NULL)
    {
        newRoute->rt.code = 1 + countRts(myRoutes);
        newRoute->rt.sts = NULL;

        myRoutes->prox = newRoute;
    }
    else
        printf("Erro ao criar");

}

void printRoutes(routes *myRoutes)
{
    routes *aux = myRoutes;

    printf("-----");

    /* while (aux)
    {
        printf("rota: %d\n", aux->rt.code);

        aux = aux->prox;
    } */
}

stations *createStation(stations *myStations, char *name, int qty)
{
    stations *newStation = malloc(sizeof(stations));

    if (verifyStation(myStations, newStation) <= 0)
    {
        printf("Erro, verifique se a paragem já existe.");

        return myStations;
    }

    newStation->st.name = name;
    newStation->st.qty = qty;

    myStations->prox = newStation;

    return myStations;
}

void getMaxQtyStation(int code, routes *myRoutes)
{
    routes *rt = getRouteByCode(code, myRoutes);

    if (rt == NULL)
        printf("Esta rota não existe!");
    else
    {
        stations *maxStation = getMaxStation(rt->rt.sts);

        printf("Rota com paragem mais cheia é: %s com %d passageiros!\n", maxStation->st.name, maxStation->st.qty);
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

        sts = sts->prox;
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

    return getRouteByCode(code, aux->prox);
}

int countRts(routes *rts)
{
    routes *aux = rts;

    return aux == NULL ? 0 : 1 + countRts(aux->prox);
}

int verifyStation(stations *myStations, stations *newStation)
{
    stations *aux = myStations;

    if (aux == NULL && newStation != NULL)
        return 1;

    if (newStation == NULL)
        return 0;

    if (strcmp(strupr(aux->st.name), strupr(newStation->st.name)) == 0)
        return -1;

    return verifyStation(aux->prox, newStation);
}