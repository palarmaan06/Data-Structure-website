// Doubly linked list using integers
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

int isEmpty() { return head == NULL; }

int isFull() {
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL) return 1;
    free(t);
    return 0;
}

void insertBegin(int x) {
    struct node *t = malloc(sizeof(struct node));
    if (t == NULL) { printf("Memory full\n"); return; }
    t->data = x;
    t->prev = NULL;
    t->next = head;
    if (head != NULL) head->prev = t;
    head = t;
}

void insertEnd(int x) {
    struct node *t = malloc(sizeof(struct node)), *p;
    if (t == NULL) { printf("Memory full\n"); return; }
    t->data = x;
    t->next = NULL;
    if (head == NULL) {
        t->prev = NULL;
        head = t;
    } else {
        p = head;
        while (p->next != NULL) p = p->next;
        p->next = t;
        t->prev = p;
    }
}

void insertPos(int x, int pos) {
    int i;
    struct node *p = head, *t;
    if (pos == 1) { insertBegin(x); return; }
    for (i = 1; p != NULL && i < pos - 1; i++) p = p->next;
    if (p == NULL) { printf("Invalid position\n"); return; }
    t = malloc(sizeof(struct node));
    if (t == NULL) { printf("Memory full\n"); return; }
    t->data = x;
    t->next = p->next;
    t->prev = p;
    if (p->next != NULL) p->next->prev = t;
    p->next = t;
}

void deleteBegin() {
    struct node *t;
    if (head == NULL) { printf("List is empty\n"); return; }
    t = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(t);
}

void deleteEnd() {
    struct node *p;
    if (head == NULL) { printf("List is empty\n"); return; }
    p = head;
    while (p->next != NULL) p = p->next;
    if (p->prev != NULL) p->prev->next = NULL;
    else head = NULL;
    free(p);
}

void deletePos(int pos) {
    int i;
    struct node *p = head;
    if (pos == 1) { deleteBegin(); return; }
    for (i = 1; p != NULL && i < pos; i++) p = p->next;
    if (p == NULL) { printf("Invalid position\n"); return; }
    p->prev->next = p->next;
    if (p->next != NULL) p->next->prev = p->prev;
    free(p);
}

void display() {
    struct node *p = head;
    if (p == NULL) printf("List is empty\n");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void search(int x) {
    struct node *p = head;
    int pos = 1;
    while (p != NULL) {
        if (p->data == x) { printf("Found at position %d\n", pos); return; }
        p = p->next;
        pos++;
    }
    printf("Not found\n");
}

int main() {
    int ch, x, pos;
    do {
        printf("\n1.Insert Begin 2.Insert Position 3.Insert End");
        printf("\n4.Delete Begin 5.Delete End 6.Delete Position");
        printf("\n7.IsEmpty 8.IsFull 9.Display 10.Search 0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); insertBegin(x); break;
            case 2: printf("Enter value and position: "); scanf("%d%d", &x, &pos); insertPos(x, pos); break;
            case 3: printf("Enter value: "); scanf("%d", &x); insertEnd(x); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Enter position: "); scanf("%d", &pos); deletePos(pos); break;
            case 7: printf(isEmpty() ? "List is empty\n" : "List is not empty\n"); break;
            case 8: printf(isFull() ? "Memory full\n" : "Memory available\n"); break;
            case 9: display(); break;
            case 10: printf("Enter value: "); scanf("%d", &x); search(x); break;
        }
    } while (ch != 0);
    return 0;
}
