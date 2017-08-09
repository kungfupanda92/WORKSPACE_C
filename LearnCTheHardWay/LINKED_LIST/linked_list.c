#include "linked_list.c"


node_t* list_create(int data, node_t* next)
{
    node_t new_node = (node_t *)malloc(sizeof(node_t));
    if(new_node == NULL)
        printf("Error create new node");
    
    new_node->data = data;
    new_node->next = next;
}
node_t* list_prepend(node_t* head, int data)
{
    node_t* new_node = list_create(data, head);
    head = new_node;
    return head;
}
node_t* list_append(node_t* head, int data)
{
    /*goto the last node*/
    node_t *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
    
    /*create a new node*/
    node_t *new_node = create(data,NULL);
    cursor->next = new_node;
    return head;
}
node_t* list_insert_after(node_t *head, int data, node_t *prev)
{
    /* find prev node, start fron first node*/
    node_t *cursor = head;
    while(cursor != prev && cursor != NULL)
        cursor = cursor->next;
    if(cursor != NULL)
    {
        node_t *new_node = list_create(data,cursor->next);
        cursor->next = new_node;
        return head;
    }     
    else
        return NULL;
}
node_t* list_insert_before(node_t *head, int data, node_t *nxt)
{
    /* find nxt mode, start from first node */
    node_t *cursor = head;
    while(cursor->next != prev && cursor != NULL)
        cursor = cursor->next;
    if(cursor != NULL)
    {
        node_t* new_node = create(data, cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
        return NULL;
}
node_t search_