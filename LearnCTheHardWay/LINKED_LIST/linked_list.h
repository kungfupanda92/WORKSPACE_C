#ifndef __LINKED_LIST__
#define __LINKED_LIST__
/*class list node */
    ------------------------------              ------------------------------
    |              |             |            \ |              |             |
    |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
    |              |             |            / |              |             |
    ------------------------------              ------------------------------
typedef struct Node node_t;
struct Node{
    int data;
    node_t *next;
};




#endif