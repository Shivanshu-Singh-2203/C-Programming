#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* q = initQueue();
    int choice, value;

    while (1) {
        printf("\n=== Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Reverse Queue\n");
        printf("5. Search Element\n");
        printf("6. Show Front\n");
        printf("7. Show Size\n");
        printf("8. Clear Queue\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                printf("Enqueued %d successfully.\n", value);
                break;

            case 2:
                if (isEmpty(q)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    int val = dequeue(q);
                    printf("Dequeued: %d\n", val);
                }
                break;

            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue elements: ");
                    display(q);
                    printf("\n");
                }
                break;

            case 4:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    reverseQueue(q);
                    printf("Queue reversed successfully.\n");
                }
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(q, value))
                    printf("%d found in queue.\n", value);
                else
                    printf("%d not found in queue.\n", value);
                break;

            case 6:
                if (isEmpty(q))
                    printf("Queue is empty.\n");
                else
                    printf("Front element: %d\n", front(q));
                break;

            case 7:
                printf("Queue size: %d\n", size(q));
                break;

            case 8:
                clear(q);
                printf("Queue cleared successfully.\n");
                break;

            case 9:
                freeQueue(q);
                printf("Exiting... Memory freed.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

