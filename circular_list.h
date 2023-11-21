typedef struct Circular_List circular_list;

circular_list *init();

circular_list *insertNodeBegin(circular_list *head, char character);

circular_list *removeNode(circular_list *head, char character);

void printList(circular_list *head);

void searchNode(circular_list *head, char character);

void divideList(circular_list *head);

circular_list *removeList(circular_list *head);

