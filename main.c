#include <stdio.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

int main()
{

  routes *myRoutes = initRoutes();

  if (myRoutes != NULL)
  {
    myRoutes = createRoute(myRoutes);

    printf("foi");
  }
  else
    printf("not");

  printf("dededed");

  return 0;
}
