// Singly linked list using strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[50];
    struct node *next;
};
struct node *head = NULL;

int isEmpty() { return head == NULL; }
int isFull()
{
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL)
        return 1;
    free(t);
    return 0;
}
void insertBegin(char x[])
{
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Memory full\n");
        return;
    }
    strcpy(t->data, x);
    t->next = head;
    head = t;
}
void insertEnd(char x[])
{
    struct node *t = malloc(sizeof(struct node)), *p;
    if (t == NULL)
    {
        printf("Memory full\n");
        return;
    }
    strcpy(t->data, x);
    t->next = NULL;
    if (head == NULL)
        head = t;
    else
    {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = t;
    }
}
void insertPos(char x[], int pos)
{
    int i;
    struct node *p = head, *t;
    if (pos == 1)
    {
        insertBegin(x);
        return;
    }
    for (i = 1; p != NULL && i < pos - 1; i++)
        p = p->next;
    if (p == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    t = malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Memory full\n");
        return;
    }
    strcpy(t->data, x);
    t->next = p->next;
    p->next = t;
}
void deleteBegin()
{
    struct node *t;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    t = head;
    head = head->next;
    free(t);
}
void deleteEnd()
{
    struct node *p;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    p = head;
    while (p->next->next != NULL)
        p = p->next;
    free(p->next);
    p->next = NULL;
}
void deletePos(int pos)
{
    int i;
    struct node *p = head, *t;
    if (pos == 1)
    {
        deleteBegin();
        return;
    }
    for (i = 1; p != NULL && i < pos - 1; i++)
        p = p->next;
    if (p == NULL || p->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    t = p->next;
    p->next = t->next;
    free(t);
}
void display()
{
    struct node *p = head;
    if (p == NULL)
        printf("List is empty\n");
    while (p != NULL)
    {
        printf("%s ", p->data);
        p = p->next;
    }
    printf("\n");
}
void search(char x[])
{
    struct node *p = head;
    int pos = 1;
    while (p != NULL)
    {
        if (strcmp(p->data, x) == 0)
        {
            printf("Found at position %d\n", pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("Not found\n");
}
int main()
{
    int ch, pos;
    char x[50];
    do
    {
        printf("\n1.Insert Begin 2.Insert Position 3.Insert End");
        printf("\n4.Delete Begin 5.Delete End 6.Delete Position");
        printf("\n7.IsEmpty 8.IsFull 9.Display 10.Search 0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter word: ");
            scanf("%49s", x);
            insertBegin(x);
            break;
        case 2:
            printf("Enter word and position: ");
            scanf("%49s%d", x, &pos);
            insertPos(x, pos);
            break;
        case 3:
            printf("Enter word: ");
            scanf("%49s", x);
            insertEnd(x);
            break;
        case 4:
            deleteBegin();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
            break;
        case 7:
            printf(isEmpty() ? "List is empty\n" : "List is not empty\n");
            break;
        case 8:
            printf(isFull() ? "Memory full\n" : "Memory available\n");
            break;
        case 9:
            display();
            break;
        case 10:
            printf("Enter word: ");
            scanf("%49s", x);
            search(x);
            break;
        }
    } while (ch != 0);
    return 0;
}
