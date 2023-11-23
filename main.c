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
    list = insertNodeBegin(list, 'b');
    list = insertNodeBegin(list, 'c');
    list = insertNodeBegin(list, 'd');
    list = insertNodeBegin(list, 'a');

    /*

    */
    printList(list);
    printf("------------------\n");
    divideList(list);

    removeList(list);
    return 0;
}
