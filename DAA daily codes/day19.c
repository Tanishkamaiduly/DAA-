#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int detectCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &nodes[i]->data);

        nodes[i]->prev = NULL;
        nodes[i]->next = NULL;
    }

    // Connect nodes as a doubly linked list
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
        nodes[i + 1]->prev = nodes[i];
    }

    printf("Enter position where last node should connect (-1 for no cycle): ");
    scanf("%d", &position);

    if (position >= 0 && position < n) {
        nodes[n - 1]->next = nodes[position];
        nodes[position]->prev = nodes[n - 1];
    }

    if (detectCycle(nodes[0])) {
        printf("Cycle detected.\n");
    } else {
        printf("No cycle detected.\n");
    }

    return 0;
}