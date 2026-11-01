// IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)


#include <stdio.h>
#include <string.h>

char q[5][30];
int front = -1, rear = -1;

void insertFront()
{ char x[30];
    if (front == 0)
    {
        printf("Insertion at front not possible\n");
        return;
    }
printf("Enter string: ");
    scanf("%s", x);

    if (front == -1)
    { front = rear = 0;
    }
    else
    {
        front--;
    }
strcpy(q[front], x);
}

void insertRear()
{char x[30];

    if (rear == 4)
    {printf("Deque is full\n");
        return;
    }
printf("Enter string: ");
    scanf("%s", x);
if (front == -1)
        front = 0;

    rear++;
    strcpy(q[rear], x);
}

void deleteFront()
{
    if (front == -1)
    { printf("Deque is empty\n");
        return;
    }

    printf("Deleted: %s\n", q[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted: %s\n", q[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void peek()
{
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Front element: %s\n", q[front]);
}

void isEmpty()
{
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

void isFull()
{
    if (front == 0 && rear == 4)
        printf("Deque is full\n");
    else
        printf("Deque is not full\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%s ", q[i]);

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Peek");
        printf("\n6. IsEmpty");
        printf("\n7. IsFull");
        printf("\n8. Display");
        printf("\n9. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: peek(); break;
            case 6: isEmpty(); break;
            case 7: isFull(); break;
            case 8: display(); break;
            case 9: printf("Program ended"); break;
            default: printf("Invalid choice");
        }

    } while (choice != 9);

    return 0;
}