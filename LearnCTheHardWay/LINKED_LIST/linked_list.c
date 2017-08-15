#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node_t* list_create(int data, node_t *next)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL)
        printf("Error create new node");

    new_node->data = data;
    new_node->next = next;
}
node_t* list_prepend(node_t *head, int data)
{
    node_t *new_node = list_create(data, head);
    head = new_node;
    return head;
}
node_t* list_append(node_t *head, int data)
{
    /*goto the last node*/
    node_t *cursor = head;
    while (cursor->next != NULL)
        cursor = cursor->next;

    /*create a new node*/
    node_t *new_node = list_create(data, NULL);
    cursor->next = new_node;
    return head;
}
node_t* list_insert_after(node_t *head, int data, node_t *prev)
{
    /* find prev node, start fron first node*/
    node_t *cursor = head;
    while (cursor != prev && cursor != NULL)
        cursor = cursor->next;
    if (cursor != NULL)
    {
        node_t *new_node = list_create(data, cursor->next);
        cursor->next = new_node;
        return head;
    }
    else
        return NULL;
}
node_t* list_insert_before(node_t *head, int data, node_t *nxt)
{
    if(head != NULL || nxt != NULL)
        return NULL;
    if(head == nxt)
    {
        head = list_prepend(head, data);
        return head;
    }
    /* find nxt mode, start from first node */
    node_t *cursor = head;
    while(cursor != NULL)
    {
        if(cursor->next == nxt)
        {
            node_t *new_node = list_create(data, nxt);
            cursor->next = new_node;
            return head;
        }
        cursor = cursor->next;
    }
    return NULL;

}
node_t* list_search(node_t *head, int data)
{
    node_t *cursor = head;
    while (cursor != NULL)
    {
        if (cursor->data == data)

            return cursor;
        cursor = cursor->next;
    }
    return NULL;
}
node_t* list_reverse(node_t *head)
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int count(node_t *head)
{
    node_t *cursor = head;
    int c = 0;
    while (cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}
node_t* list_remove_front(node_t *head)
{
    if (head == NULL)
        return NULL;
    node_t *front = head;
    head = head->next;
    front->next = NULL;
    free(front);

    return head;
}
node_t* list_remove_back(node_t *head)
{
    if (head == NULL)
        return NULL;
    node_t *back;
    node_t *cursor = head;
    while (cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
    if (back != NULL)
        back->next = NULL;

    if (cursor == head)
        head = NULL;

    free(cursor);
    return head;
}
node_t* list_remove_any(node_t *head, node_t *nd)
{
    if (nd == head)
    {
        head = list_remove_front(head);
        return head;
    }
    if (nd->next == NULL)
    {
        head = list_remove_back(head);
        return head;
    }
    node_t *cursor = head;
    while (cursor->next != NULL)
    {
        if (cursor->next = nd)
        {
            cursor->next = nd->next;
            nd->next = NULL;

            free(nd);
        }
        cursor = cursor->next;
    }
    return head;
}
node_t* list_dispose(node_t *head)
{
    node_t *next;
    node_t *cursor = head;

    while (cursor != NULL)
    {
        next = cursor->next;
        cursor->next = NULL;
        free(cursor);
        cursor = next;
    }
    head = NULL;
}
