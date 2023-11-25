#include <stdio.h>
#include <locale.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{
  setlocale(LC_ALL, "pt-br");
  routes *myRoutes = initRoutes();

  myRoutes = createRouteBegin(myRoutes);
  myRoutes = createRouteBegin(myRoutes);
  myRoutes = createRouteBegin(myRoutes);

  printRoutes(myRoutes);

  createStationEnd(1, "TESTE", 56, myRoutes);
  createStationEnd(1, "TESTE", 57, myRoutes);
  createStationEnd(1, "TESTE 3", 27, myRoutes);
  createStationEnd(3, "TESTE", 27, myRoutes);
  createStationEnd(2, "TESTE", 27, myRoutes);
  createStationEnd(4, "TESTE", 27, myRoutes);

  printf("============\n");

  printStation(getRouteByCode(3, myRoutes));

  return 0;
}
