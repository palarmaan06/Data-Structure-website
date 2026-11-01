// Singly circular linked list using integers
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

int isEmpty()
{
    return last == NULL;
}

int isFull()
{
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL)
        return 1;
    free(t);
    return 0;
}

void insertBegin(int x)
{
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Memory full\n");
        return;
    }
    t->data = x;
    if (last == NULL)
    {
        last = t;
        t->next = t;
    }
    else
    {
        t->next = last->next;
        last->next = t;
    }
}

void insertEnd(int x)
{
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("Memory full\n");
        return;
    }
    t->data = x;
    if (last == NULL)
    {
        last = t;
        t->next = t;
    }
    else
    {
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void insertPos(int x, int pos)
{
    int i;
    struct node *p, *t;
    if (pos == 1)
    {
        insertBegin(x);
        return;
    }
    if (last == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    p = last->next;
    for (i = 1; i < pos - 1 && p != last; i++)
        p = p->next;
    if (i != pos - 1)
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
    t->data = x;
    t->next = p->next;
    p->next = t;
    if (p == last)
        last = t;
}

void deleteBegin()
{
    struct node *t;
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    t = last->next;
    if (t == last)
        last = NULL;
    else
        last->next = t->next;
    free(t);
}

void deleteEnd()
{
    struct node *p, *t;
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    t = last;
    if (last->next == last)
        last = NULL;
    else
    {
        p = last->next;
        while (p->next != last)
            p = p->next;
        p->next = last->next;
        last = p;
    }
    free(t);
}

void deletePos(int pos)
{
    int i;
    struct node *p, *t;
    if (pos == 1)
    {
        deleteBegin();
        return;
    }
    if (last == NULL || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    p = last->next;
    for (i = 1; i < pos - 1 && p != last; i++)
        p = p->next;
    if (p == last || p->next == last->next)
    {
        printf("Invalid position\n");
        return;
    }
    t = p->next;
    p->next = t->next;
    if (t == last)
        last = p;
    free(t);
}

void display()
{
    struct node *p;
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = last->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

void search(int x)
{
    struct node *p;
    int pos = 1;
    if (last == NULL)
    {
        printf("Not found\n");
        return;
    }
    p = last->next;
    do
    {
        if (p->data == x)
        {
            printf("Found at position %d\n", pos);
            return;
        }
        p = p->next;
        pos++;
    } while (p != last->next);
    printf("Not found\n");
}

int main()
{
    int ch, x, pos;
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
            printf("Enter value: ");
            scanf("%d", &x);
            insertBegin(x);
            break;
        case 2:
            printf("Enter value and position: ");
            scanf("%d%d", &x, &pos);
            insertPos(x, pos);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &x);
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
            printf("Enter value: ");
            scanf("%d", &x);
            search(x);
            break;
        }
    } while (ch != 0);
    return 0;
}
