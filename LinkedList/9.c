// Addition of two polynomials using linked lists
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, power;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *last = NULL, *t;
    int n, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        t = malloc(sizeof(struct node));
        if (t == NULL)
            return head;
        printf("Enter coefficient and power: ");
        scanf("%d%d", &t->coeff, &t->power);
        t->next = NULL;
        if (head == NULL)
            head = t;
        else
            last->next = t;
        last = t;
    }
    return head;
}

void display(struct node *p)
{
    if (p == NULL)
    {
        printf("0");
        return;
    }
    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->power);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

struct node *add(struct node *a, struct node *b)
{
    struct node *head = NULL, *last = NULL, *t;
    while (a != NULL || b != NULL)
    {
        int c, p;
        if (b == NULL || (a != NULL && a->power > b->power))
        {
            c = a->coeff;
            p = a->power;
            a = a->next;
        }
        else if (a == NULL || b->power > a->power)
        {
            c = b->coeff;
            p = b->power;
            b = b->next;
        }
        else
        {
            c = a->coeff + b->coeff;
            p = a->power;
            a = a->next;
            b = b->next;
        }
        if (c != 0)
        {
            t = malloc(sizeof(struct node));
            if (t == NULL)
                return head;
            t->coeff = c;
            t->power = p;
            t->next = NULL;
            if (head == NULL)
                head = t;
            else
                last->next = t;
            last = t;
        }
    }
    return head;
}

int main()
{
    struct node *a, *b, *ans;
    printf("First polynomial\n");
    a = create();
    printf("Second polynomial\n");
    b = create();
    ans = add(a, b);
    printf("Sum = ");
    display(ans);
    return 0;
}
