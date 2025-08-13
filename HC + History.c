#include <stdio.h>
#define MAX_HISTORY 100
int history[MAX_HISTORY];
int historyCount = 0;

int getValue(int state) {
    return -(state - 50) * (state - 50) + 2500; 
}

void addToHistory(int state) {
    history[historyCount++] = state;
}

void hillClimb(int start) {
    int current = start;
    int currentValue = getValue(current);
    addToHistory(current);
    while (1) {
        int bestNeighbor = current;
        int bestValue = currentValue;
        for (int step = -1; step <= 1; step += 2) {
            int neighbor = current + step;
            if (neighbor >= 0 && neighbor <= 100) {
                int value = getValue(neighbor);
                if (value > bestValue) {
                    bestValue = value;
                    bestNeighbor = neighbor;
                }
            }
        }
        if (bestValue <= currentValue) {
            printf("Reached peak at %d (Value: %d)\n", current, currentValue);
            break;
        }
        current = bestNeighbor;
        currentValue = bestValue;
        addToHistory(current);
    }
    printf("\nHistory of visited states:\n");
    for (int i = 0; i < historyCount; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}

int main() {
    int start;
    printf("Enter starting state (0-100): ");
    scanf("%d", &start);

    if (start < 0 || start > 100) {
        printf("Invalid state!\n");
        return 1;
    }

    hillClimb(start);
    return 0;
}

