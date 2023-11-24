#include <stdio.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{

  routes *myRoutes = initRoutes();

  myRoutes = createRouteBegin(myRoutes);
  myRoutes = createRouteBegin(myRoutes);
  myRoutes = createRouteBegin(myRoutes);


  printRoutes(myRoutes);
  
  return 0;
}
