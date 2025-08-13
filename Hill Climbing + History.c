#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STATE 100
#define MAX_NEIGHBORS 10
#define MAX_HISTORY 200

int getValue(int state) {
    return (100 - abs(50 - state)); 
}

void generateNeighbors(int current, int neighbors[], int *count) {
    *count = 0;
    for (int i = -2; i <= 2; i++) {
        if (i != 0 && current + i >= 0 && current + i <= MAX_STATE) {
            neighbors[(*count)++] = current + i;
        }
    }
}

int visitedBefore(int state, int history[], int histCount) {
    for (int i = 0; i < histCount; i++) {
        if (history[i] == state)
            return 1;
    }
    return 0;
}

void hillClimbWithHistory(int start) {
    int current = start;
    int currentValue = getValue(current);

    int history[MAX_HISTORY];
    int histCount = 0;
    history[histCount++] = current;
    printf("Start State: %d | Value: %d\n", current, currentValue);
    while (1) {
        int neighbors[MAX_NEIGHBORS];
        int count = 0;
        generateNeighbors(current, neighbors, &count);
        int bestNeighbor = -1;
        int bestValue = currentValue;
        for (int i = 0; i < count; i++) {
            if (!visitedBefore(neighbors[i], history, histCount)) {
                int val = getValue(neighbors[i]);
                printf("  Checking Neighbor: %d | Value: %d\n", neighbors[i], val);
                if (val > bestValue) {
                    bestValue = val;
                    bestNeighbor = neighbors[i];
                }
            }
        }
        if (bestNeighbor == -1) {
            printf("Reached Peak at State: %d | Value: %d\n", current, currentValue);
            break;
        }
        current = bestNeighbor;
        currentValue = bestValue;
        history[histCount++] = current;
        printf("Move to State: %d | Value: %d\n", current, currentValue);
    }
    printf("\nVisited States: ");
    for (int i = 0; i < histCount; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int start;
    printf("Enter starting state (0-100): ");
    scanf("%d", &start);
    if (start < 0 || start > MAX_STATE) {
        printf("Invalid start state!\n");
        return 1;
    }
    hillClimbWithHistory(start);
    return 0;
}
