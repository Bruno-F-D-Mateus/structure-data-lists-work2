#include <stdio.h>
#include "doubly_linked_list.c"

int main()
{

    stations *sts = initStations();
    routes *rts = initRoutes();

    station *st = createStation(rts->route.sts, "Teste", 23);
}
