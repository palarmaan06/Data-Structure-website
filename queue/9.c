// IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>

int queue[100];
int size;
int front = 0, count = 0;

int isEmpty() {
    return count == 0;
}

int isFull() {
    return count == size;
}

void insertFront(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    front = (front - 1 + size) % size;      // move front one step back
    queue[front] = x;
    count++;
    printf("%d inserted at front\n", x);
}

void insertRear(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    queue[(front + count) % size] = x;      // position after the last element
    count++;
    printf("%d inserted at rear\n", x);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted from front\n", queue[front]);
    front = (front + 1) % size;
    count--;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted from rear\n", queue[(front + count - 1) % size]);
    count--;
}

void peekFront() {
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Front element is %d\n", queue[front]);
}

void peekRear() {
    if (isEmpty())
        printf("Queue is empty\n");
    else
        printf("Rear element is %d\n", queue[(front + count - 1) % size]);
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = 0; i < count; i++)
        printf("%d ", queue[(front + i) % size]);
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
        printf("\n1.InsertFront 2.InsertRear 3.DeleteFront 4.DeleteRear 5.PeekFront\n");
        printf("6.PeekRear 7.IsEmpty 8.IsFull 9.Display 10.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                peekFront();
                break;
            case 6:
                peekRear();
                break;
            case 7:
                if (isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 8:
                if (isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;
            case 9:
                display();
                break;
            case 10:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
}