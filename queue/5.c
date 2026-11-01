// IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>

int queue[10];     // maximum possible size
int size;           // size chosen by the user
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % size == front;
}

void insert(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {          // first element
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = x;
        printf("%d inserted\n", x);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted\n", queue[front]);
        if (front == rear) {        // last element removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
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
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, x;

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