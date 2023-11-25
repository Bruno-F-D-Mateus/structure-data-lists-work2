typedef struct Circular_List circular_list;
//Inicializa a lista circular
circular_list *init();
//Insere um novo nó, no Início
circular_list *insertNodeBegin(circular_list *head, char character);
//Remove um Nó pelo seu caracter
circular_list *removeNode(circular_list *head, char character);
//apresenta todos os elementos da Lista Circular
void printList(circular_list *head);
//pesquisa um determinado elemento pelo seu caracter
void searchNode(circular_list *head, char character);
//divide a lista circular em duas - uma de vogais e outra de consoantes
circular_list *divideList(circular_list *head);

circular_list* removeList(circular_list *head);

