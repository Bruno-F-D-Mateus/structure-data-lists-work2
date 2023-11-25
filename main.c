#include <stdio.h>
#include <locale.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{
  
  setlocale(LC_ALL, "pt-br");
  routes *myRoutes = initRoutes();

  myRoutes = createRouteBegin(myRoutes); // 1 - 3ª

  createStationEnd(1, "hong", 0, myRoutes);
  createStationEnd(1, "tokyo", 20, myRoutes);
  createStationEnd(1, "shibuya", 56, myRoutes);

  printStation(getRouteByCode(1, myRoutes));

  printMaxStation(1, myRoutes);

  return 0;
}
