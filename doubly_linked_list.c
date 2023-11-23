#include "doubly_linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Station
{
    char *name;
    int qty;
};

struct Stations
{
    struct Station *st;
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
    struct Route rot;
    struct Routes *prev;
    struct Routes *prox;
};

routes *initRoutes()
{
    routes *rts = malloc(sizeof(routes));

    if (rts == NULL)
        printf("Erro ao criar");

    return rts;
}

stations *initStations()
{
    stations *sts = malloc(sizeof(stations));

    if (sts == NULL)
        printf("Erro ao criar");

    return sts;
}

routes *createRoute(routes *rts)
{
    route *rt = malloc(sizeof(route));

    if (rt != NULL)
    {
        rt->code = 1 + countRts(rts);
        rt->sts = NULL;

        rts->prox = rt;
    }

    return rts;
}

stations *createStation(stations *sts, char *name, int qty)
{
    station *newSt = malloc(sizeof(station));

    if (verifyStation(sts, newSt) <= 0)
    {
        printf("Erro, verifique se a paragem já existe.");

        return sts;
    }

    newSt->name = name;
    newSt->qty = qty;

    sts->prox = newSt;

    return sts;
}

int getMaxQtySation(int code, routes *rts)
{
    route *rt = getRouteByCode(code, rts);

    if (rt == NULL)
    {
        printf("Esta rota não existe!");
        return 0;
    }

    station *st = getMaxStation(rt->sts);

    return 0;
}

station *getMaxStation(stations *comingSts)
{
    stations *sts = comingSts;
    station *st;

    int cont = 0;

    while (sts)
    {
        if (sts->st.qty > cont)
            st = sts;

        sts = sts->prox;
    }

    return st;
}

route *getRouteByCode(int code, routes *rts)
{
    routes *aux = rts;

    if (aux == NULL)
        return NULL;

    if (aux->route.code == code)
        return aux;

    return getRouteByCode(code, aux->prox);
}

int countRts(routes *rts)
{
    routes *aux = rts;

    return aux == NULL ? 0 : 1 + countRts(aux->prox);
}

int verifyStation(stations *sts, station *st)
{
    stations *aux = sts;

    if (aux == NULL && st != NULL)
        return 1;

    if (st == NULL)
        return 0;

    if (strcmp(strupr(aux->st.name), strupr(st->name)) == 0)
        return -1;

    return verifyStation(aux->prox, st);
}