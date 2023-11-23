#include <stdio.h>
#include "circular_list.h"
#include <ctype.h>

int main(){
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
