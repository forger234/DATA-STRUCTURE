
#include <stdio.h>
int a[20], size, front = -1, rear = -1;

void PUSH_DQ(int item) {
    if (front == 0 && rear == size - 1)
        printf("Deque is FULL. Insertion is not possible.\n");
    else if (rear == -1) {
        front = 0;
        rear = 0;
        a[front] = item;
    } else if (front > 0) {
        front--;
        a[front] = item;
    } else {
        for (int i = rear; i >= front; i--)
            a[i + 1] = a[i];
        a[front] = item;
        rear++;
    }
}

void INJECT_DQ(int item) {
    if (front == 0 && rear == size - 1)
        printf("Deque is FULL. Insertion is not possible.\n");
    else if (rear == -1) {
        front = 0;
        rear = 0;
        a[rear] = item;
    } else if (rear < size - 1) {
        for (int i = rear; i >= front; i--)
            a[i + 1] = a[i];
        a[front] = item;
        rear++;
    } else {
        printf("Deque is FULL. Insertion is not possible.\n");
    }
}

void POP_DQ() {
    if (front == -1)
        printf("Deque is EMPTY.\n");
    else if (front == rear) {
        printf("Deleted item is %d\n", a[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted item is %d\n", a[front]);
        front++;
    }
}

void EJECT_DQ() {
    if (front == -1)
        printf("Deque is EMPTY.\n");
    else if (front == rear) {
        printf("Deleted item is %d\n", a[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Deleted item is %d\n", a[rear]);
        rear--;
    }
}

void DISPLAY_DQ() {
    if (front == -1)
        printf("Deque is EMPTY.\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}

int main() {
    int item, opt;

    printf("Enter the size of the Deque: ");
    scanf("%d", &size);

    do {
        printf("\nEnter the option:\n1. PUSH\n2. POP\n3. INJECT\n4. EJECT\n5. DISPLAY\n6. EXIT\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                PUSH_DQ(item);
                break;

            case 2:
                POP_DQ();
                break;

            case 3:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                INJECT_DQ(item);
                break;

            case 4:
                EJECT_DQ();
                break;

            case 5:
                DISPLAY_DQ();
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
        }
    } while (opt != 6);

    return 0;
}