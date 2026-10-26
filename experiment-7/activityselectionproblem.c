#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

int compare(const void *a, const void *b) {
    struct Activity *x = (struct Activity *)a;
    struct Activity *y = (struct Activity *)b;

    return x->finish - y->finish;
}

void activitySelection(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), compare);

    int lastFinish = 0;
    int count = 0;

    printf("Selected activities:\n");

    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("(%d, %d)\n",
                   activities[i].start,
                   activities[i].finish);

            lastFinish = activities[i].finish;
            count++;
        }
    }

    printf("Maximum activities selected: %d\n", count);
}

int main() {
    struct Activity activities[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9},
        {3, 5}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}