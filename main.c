#include <stdio.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{

  routes *myRoutes = initRoutes();

  if (myRoutes != NULL)
  {
    createRoute(myRoutes);
    createRoute(myRoutes);


  }
  else
    printf("not");

    printRoutes(myRoutes);


  return 0;
}
