#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NEIGHBORS 4

int getValue(int state) {
    return 100 - abs(50 - state);
}

void generateNeighbors(int current, int neighbors[], int *count) {
    *count = 0;
    if (current - 1 >= 0) neighbors[(*count)++] = current - 1;
    if (current + 1 <= 100) neighbors[(*count)++] = current + 1;
    if (current - 2 >= 0) neighbors[(*count)++] = current - 2;
    if (current + 2 <= 100) neighbors[(*count)++] = current + 2;
}

void hillClimb(int start) {
    int current = start;
    int currentValue = getValue(current);
    printf("\nStarting Hill Climb...\n");
    printf("State: %d | Value: %d\n", current, currentValue);
    while (1) {
        int neighbors[MAX_NEIGHBORS];
        int count = 0;
        generateNeighbors(current, neighbors, &count);
        int bestNeighbor = current;
        int bestValue = currentValue;
        printf("Checking neighbors of %d:\n", current);
        for (int i = 0; i < count; i++) {
            int val = getValue(neighbors[i]);
            printf("  Neighbor: %d | Value: %d\n", neighbors[i], val);
            if (val > bestValue) {
                bestValue = val;
                bestNeighbor = neighbors[i];
            }
        }

        if (bestValue <= currentValue) {
            printf("\nReached Peak at State: %d | Value: %d\n", current, currentValue);
            break;
        }
        printf("Moving to better neighbor: %d (Value: %d)\n\n", bestNeighbor, bestValue);
        current = bestNeighbor;
        currentValue = bestValue;
    }
}

int main() {
    int start;
    srand(time(NULL));

    printf("Enter starting state (0-100): ");
    scanf("%d", &start);

    if (start < 0 || start > 100) {
        printf("Invalid state! Enter between 0 and 100.\n");
        return 1;
    }
    hillClimb(start);
    return 0;
}
