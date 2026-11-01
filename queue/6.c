// IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#include <string.h>

char queue[100][50];
int size;
int front = 0, rear = -1, count = 0;

int isEmpty() {
    return count == 0;
}

int isFull() {
    return count == size;
}

void insert(char x[]) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % size;
    strcpy(queue[rear], x);
    count++;
    printf("%s inserted\n", x);
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%s deleted\n", queue[front]);
    front = (front + 1) % size;
    count--;
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
    printf("Queue: ");
    for (i = 0; i < count; i++)
        printf("%s ", queue[(front + i) % size]);
    printf("\n");
}

int main() {
    int choice;
    char s[50];

    printf("Enter queue size (max 100): ");
    scanf("%d", &size);

    if (size < 1 || size > 100) {
        printf("Invalid size\n");
        return 0;
    }

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