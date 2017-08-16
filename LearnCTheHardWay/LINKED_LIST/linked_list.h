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
typedef struct Node
{
    int data;
    struct Node *next;
} node_t;
typedef void (*callback)(node_t *data);

/* Exported functions --------------------------------------------------------*/
/**
 * @brief list_create
 * Add a node at the beginning of the linked list
 * @param data - data field
 * @param next - next pointer
 * @return pointer to head list
 */
node_t *list_create(int data, node_t *next);

/**
 * @brief list_create
 * Add a new node to the head pointer 
 * @param head - the head pointer
 * @param data - data field
 * @return pointer to head list
 */
node_t *list_prepend(node_t *head, int data);

/**
 * @brief list_create
 * Add a new node at the end of the linked list
 * @param head - the head pointer
 * @param data - data field
 * @return pointer to head list
 */
node_t *list_append(node_t *head, int data);

/**
 * @brief list_create
 * Add a new node after a particular node of the linked list
 * @param head - the head pointer
 * @param data - data field
 * @param prev - the preveous pointer
 * @return pointer to head list
 */
node_t *list_insert_after(node_t *head, int data, node_t *prev);

/**
 * @brief list_create
 * Add a new node before a particular node of the linked list
 * @param head - the head pointer
 * @param data - data field
 * @param nxt  - the next pointer
 * @return pointer to head list
 */
node_t *list_insert_before(node_t *head, int data, node_t *nxt);

/**
 * @brief list_create
 * Search for a node and return immediately when found
 * @param head - the head pointer
 * @param data - data field
 * @return pointer to head list
 */
node_t *list_search(node_t *head, int data);

/**
 * @brief list_create
 * Reverse linked list
 * @param head - the head pointer
 * @return pointer to head list
 */
node_t *list_reverse(node_t *head);

/**
 * @brief list_create
 * Count the elements of the linked list
 * @param head - the head pointer
 * @return the number of elements in a linked list
 */
int count(node_t *head);

/**
 * @brief list_create
 * Delete a node from the front of the linked list
 * @param head - the head pointer
 * @return pointer to head list
 */
node_t *list_remove_front(node_t *head);

/**
 * @brief list_create
 * Delete a node from the back of the linked list
 * @param head - the head pointer
 * @return pointer to head list
 */
node_t *list_remove_back(node_t *head);

/**
 * @brief list_create
 * Remove a node in the middle of the linked list
 * @param head - the head pointer
 * @param nd - the middle pointer
 * @return pointer to head list
 */
node_t *list_remove_any(node_t *head, node_t *nd);

/**
 * @brief list_create
 * Delete the whole linked list
 * @param data - data field
 * @param next - next pointer
 * @return pointer to head list
 */
node_t *list_dispose(node_t *head);

#endif