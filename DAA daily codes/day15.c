#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Moves one step
        fast = fast->next->next;    // Moves two steps

        if (slow == fast) {
            return 1;               // Cycle found
        }
    }

    return 0;                       // No cycle
}

int main() {
    int n, cyclePosition;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *nodes[n];

    printf("Enter node values:\n");

    for (int i = 0; i < n; i++) {
        nodes[i] = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &nodes[i]->data);
        nodes[i]->next = NULL;

        if (head == NULL) {
            head = nodes[i];
        } else {
            tail->next = nodes[i];
        }

        tail = nodes[i];
    }

    printf("Enter cycle position (-1 for no cycle): ");
    scanf("%d", &cyclePosition);

    if (cyclePosition >= 0 && cyclePosition < n) {
        tail->next = nodes[cyclePosition];
    }

    if (hasCycle(head)) {
        printf("Cycle detected.\n");
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}