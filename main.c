#include <stdio.h>
#include "doubly_linked_list.h"
#include "circular_list.h"
/*   stations *sts = initStations();
  routes *rts = initRoutes();

  station *st = createStation(rts->route.sts, "Teste", 23); */

int main()
{
    circular_list *list = init();
    list = insertNodeBegin(list, 'a');   
 
   
    /*
    list = insertNodeBegin(list, 'd'); 
    list = insertNodeBegin(list, 'a');   

    */
    printList(list);
    //divideList(list);
 
    list = removeList(list);
    return 0;
}
