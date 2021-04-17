#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *inainte;
} *first = NULL, *last = NULL;

struct Node *add(int data) {
    if (first == NULL) {
        struct Node *node = malloc(sizeof(struct Node));
        node->data = data;
        node->inainte= node;
        first = last = node;
    } else {
        struct Node *node = malloc(sizeof(struct Node));
        node->data = data;
        node->inainte = first;
        last->inainte = node;
        last = node;
    }
}

struct Node *printList(struct Node *data) {
    struct Node *temp = data;
    printf("\n");
    do {
        printf("elementele sunt: %d\n", temp->data);
        temp = temp->inainte;
    } while (temp != first);
}

struct Node *min() {
    struct Node *minimum = first, *pivot = first;

    do {
        if (pivot->data < minimum->data) {
            minimum = pivot;
        }
        pivot = pivot->inainte;
    } while (pivot != first);

    return minimum;
}

struct Node *max() {
    struct Node *maximum = first, *pivot = first;

    do {
        if (pivot->data > maximum->data) {
            maximum = pivot;
        }
        pivot = pivot->inainte;
    } while (pivot != first);

    return maximum;
}

void printBetween(struct Node *min, struct Node *max) {
    struct Node *pivot = min->inainte;

    if (pivot == max) { return; }

    do {
        printf("%d ", pivot->data);
        pivot = pivot->inainte;
    } while (pivot != max);
}

int main() {
    int n, i, x;
    printf("Introduceti numarul de elemente:");
    scanf("%d", &n);
    srand(time(0));

    for (i = 0; i < n; i++) {
        x = rand() % 1000;
        add(x);
    }
    printList(first);
    struct Node *minNode = min();
    struct Node *maxNode = max();
    printf("Min is %d\n", minNode->data);
    printf("Max is %d\n", maxNode->data);
    printf("Numere dintre Min si Max sunt: ");
    printBetween(minNode, maxNode);
}