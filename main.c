#include <stdio.h>
#include "circular_list.h"

int main(){
    circular_list *list = init();
    list = insertNodeBegin(list, 'a');   
    list = insertNodeBegin(list, 'b');   
    list = insertNodeBegin(list, 'c');   
    list = insertNodeBegin(list, 'd');    
    /*
    */
    printList(list);
    printf("------------------\n");
    list = removeNode(list,'d');
    list = removeNode(list,'a');

 
    printList(list);

    removeList(list);
    return 0;
}
