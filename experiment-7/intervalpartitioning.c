#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int finish;
};

int compare(const void *a, const void *b) {
    struct Interval *x = (struct Interval *)a;
    struct Interval *y = (struct Interval *)b;

    return x->start - y->start;
}

int intervalPartitioning(struct Interval intervals[], int n) {
    int finishTime[n];
    int rooms = 0;

    for (int i = 0; i < n; i++) {
        int roomFound = 0;

        for (int j = 0; j < rooms; j++) {
            if (finishTime[j] <= intervals[i].start) {
                finishTime[j] = intervals[i].finish;
                roomFound = 1;
                break;
            }
        }

        
        if (roomFound == 0) {
            finishTime[rooms] = intervals[i].finish;
            rooms++;
        }
    }

    return rooms;
}

int main() {
    struct Interval intervals[] = {
        {9, 10},
        {9, 12},
        {10, 11},
        {11, 13},
        {12, 14}
    };

    int n = sizeof(intervals) / sizeof(intervals[0]);

    qsort(intervals, n, sizeof(struct Interval), compare);

    int result = intervalPartitioning(intervals, n);

    printf("Minimum rooms required: %d\n", result);

    return 0;
}