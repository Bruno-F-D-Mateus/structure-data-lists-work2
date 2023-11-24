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
    newRoutes->rt.code = 0;
    newRoutes->prev = NULL;
    newRoutes->prox = NULL;

    return newRoutes;
}

// Código é criado de forma automática
routes *createRoute(routes *myRoutes)
{

    int cont = countRts(myRoutes);

    routes *newRoute = (routes *)malloc(sizeof(routes));

    newRoute->rt.code = 1 + cont;
    newRoute->rt.sts = NULL;
    newRoute->prev = myRoutes;
    newRoute->prox = NULL;

    return myRoutes;
}

void printRoutes(routes *myRoutes)
{
    routes *aux = myRoutes;

    printf("-----\n");

    while (aux)
    {
        printf("rota: %d\n", aux->rt.code);

        aux = aux->prox;
    }

    printf("--by---\n");
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
    int cont = 0;
    routes *aux = rts;

    while (aux->rt.code)
    {

        cont++;
        printf("%d", cont);
        aux = aux->prox;
    }

    return cont;
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