#include <stdint.h>
#include <stdio.h>

#include "linked_list.h"

/*
    display a node
*/
void display(node_t *n)
{
    if (n != NULL)
        printf("%d ", n->data);
}
/*
    display the menu
*/
void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.search for an element\n");
    printf("4.insert after an element\n");
    printf("5.insert before an element\n");
    printf("6.remove front node\n");
    printf("7.remove back node\n");
    printf("8.remove any node\n");
    printf("9.sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");
}
int main(int argc, char *argv[])
{
    int command;
    int data;
    int i;

    node_t *head = NULL;
    node_t *tmp = NULL;
    callback disp = display;
    menu();
    while (1)
    {
        printf("\nEnter a command (0-10), -1 to quit: ");
        scanf("%d", &command);

        if (command == -1)
            break;
        switch (command)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("Please enter a number to prepend:");
            scanf("%d", &data);
            head = list_prepend(head, data);
            list_traverse(head, disp);
            break;
        case 2:
            printf("Please enter a number to append:");
            scanf("%d", &data);
            head = list_append(head, data);
            list_traverse(head, disp);
            break;
        case 3:
            printf("Please enter a number to search:");
            scanf("%d", &data);
            tmp = list_search(head, data);
            if (tmp != NULL)
                printf("Element with value %d found.", data);
            else
                printf("Element with value %d not found.", data);
            break;
        case 4:
            printf("Enter the element value where you want to insert after:");
            scanf("%d", &data);
            tmp = list_search(head, data);
            if (tmp != NULL)
            {
                printf("Enter the element value to insert after:");
                scanf("%d", &data);
                head = list_insert_after(head, data, tmp);
                if (head != NULL)
                    list_traverse(head, disp);
            }
            else
                printf("Element with the value %d not found.", data);
            break;
        case 5:
            printf("Enter the element value where you want to insert before:");
            scanf("%d", &data);
            head = list_insert_before(head, data, tmp);
            if (head != NULL)
            {
                printf("Enter the element value to insert before:");
                scanf("%d", &data);
                head = list_insert_before(head, data, tmp);

                if (head != NULL)
                    list_traverse(head, disp);
            }
            else
                printf("Element with value %d not found.", data);

            break;
        case 6:
            head = list_remove_front(head);
            if (head != NULL)
                list_traverse(head, disp);
            break;
        case 7:
            head = list_remove_back(head);
            if (head != NULL)
                list_traverse(head, disp);
            break;
        case 8:
            printf("Enter the element value to remove:");
            scanf("%d", &data);
            tmp = list_search(head, data);
            if (tmp != NULL)
            {
                list_remove_any(head, tmp);
                if (head != NULL)
                    list_traverse(head, disp);
            }
            else
                printf("Element with value %d not found.", data);
            break;
        case 9:
            /*sortting*/
            break;
        case 10:
            head = list_reverse(head);
            if (head != NULL)
                list_traverse(head, disp);
            break;
        case 11:
            /*create a test list*/
            for(i = 0; i<10; ++i)
            {
                list_prepend(head, i);
            }
            list_traverse(head, disp);
            break;
        }
    }
    list_dispose(head);
    return 0;
}