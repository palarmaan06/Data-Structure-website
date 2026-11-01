// IMPLEMENT THE OPERATIONS OF QUEUE DYNAMICALLY OF STRING (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty() {
    return front == NULL;
}

int isFull() {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    free(temp);
    return 0;
}

void insert(char x[]) {
    struct node *newnode;
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->data, x);
    newnode->next = NULL;

    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%s inserted\n", x);
}

void deleteElement() {
    struct node *temp;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    printf("%s deleted\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void peek() {
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Front element is %s\n", front->data);
}

void display() {
    struct node *temp = front;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char s[50];

    while (1) {
        printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string (one word): ");
                scanf("%49s", s);
                insert(s);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 5:
                if (isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
}