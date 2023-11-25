#include <stdio.h>
#include <locale.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{
  setlocale(LC_ALL, "pt-br");
  routes *myRoutes = initRoutes();

  myRoutes = createRouteBegin(myRoutes); //1 - 3ª
  myRoutes = createRouteBegin(myRoutes); //2 - 2ª
  myRoutes = createRouteBegin(myRoutes); //3 - 1ª

  printRoutes(myRoutes);

  createStationEnd(1, "shibuya", 56, myRoutes);
  createStationEnd(1, "tokyo", 90, myRoutes);
  createStationEnd(1, "hong kong", 27, myRoutes);

  printf("==============\n");

  printStation(getRouteByCode(1, myRoutes));
  //printMaxStation(1,getRouteByCode(1, myRoutes));

  return 0;
}
