#ifndef __LINKED_LIST__
#define __LINKED_LIST__
/*class list node */
/*
    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------
*/
typedef struct Node{
    int data;
    struct Node *next;
} node_t;

node_t* list_create(int data, node_t *next);
node_t* list_prepend(node_t *head, int data);
node_t* list_append(node_t *head, int data);
node_t* list_insert_after(node_t *head, int data, node_t *prev);
node_t* list_insert_before(node_t *head, int data, node_t *nxt);
node_t* list_search(node_t *head, int data);
node_t* list_reverse(node_t *head);
int count(node_t *head);
node_t* list_remove_front(node_t *head);
node_t* list_remove_back(node_t *head);
node_t* list_remove_any(node_t *head, node_t *nd);
node_t* list_dispose(node_t *head);


#endif