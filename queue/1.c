// IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>

int queue[10];     
int size;           
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == size - 1;
}

void insert(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
        printf("%d inserted\n", x);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted\n", queue[front]);
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
        printf("Front element is %d\n", queue[front]);
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, x;

    printf("Enter queue size cc: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1.Insert\n 2.Delete\n 3.Peek \n4.IsEmpty \n5.IsFull \n6.Display \n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
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