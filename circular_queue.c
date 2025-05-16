#include <stdio.h>
#define SIZE 5

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Enqueue
            if (rear == -1 && front == -1) {
                rear = front = 0;
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                queue[rear] = element;
            } else if ((rear + 1) % SIZE == front) {
                printf("Queue is full\n");
            } else {
                rear = (rear + 1) % SIZE;
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                queue[rear] = element;
            }
        }
        else if (choice == 2) { // Dequeue
            if (front == -1 && rear == -1) {
                printf("Queue is empty\n");
            } else if (front == rear) {
                printf("Element deleted: %d\n", queue[front]);
                front = rear = -1;
            } else {
                printf("Element deleted: %d\n", queue[front]);
                front = (front + 1) % SIZE;
            }
        }
        else if (choice == 3) { // Display using for loop
            if (front == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                int i;
                for (i = front; i != rear; i = (i + 1) % SIZE) {
                    printf("%d ", queue[i]);
                }
                printf("%d\n", queue[rear]); // Print the last element
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
