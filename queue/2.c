// IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <stdio.h>
#include <string.h>

char queue[100][50];    // up to 100 strings, each up to 49 characters
int size;               // size chosen by the user
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == size - 1;
}

void insert(char x[]) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        strcpy(queue[rear], x);
        printf("%s inserted\n", x);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("%s deleted\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void peek() {
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Front element is %s\n", queue[front]);
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%s ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    char s[50];

    printf("Enter queue size (max 100): ");
    scanf("%d", &size);

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