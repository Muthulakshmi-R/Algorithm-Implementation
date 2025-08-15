#include <stdio.h>

int minimax(int depth, int index, int isMax, int scores[], int maxDepth) {
    if (depth == maxDepth)
        return scores[index];
    if (isMax) {
        int left = minimax(depth + 1, index * 2, 0, scores, maxDepth);
        int right = minimax(depth + 1, index * 2 + 1, 0, scores, maxDepth);
        return (left > right) ? left : right;
    }
    else {
        int left = minimax(depth + 1, index * 2, 1, scores, maxDepth);
        int right = minimax(depth + 1, index * 2 + 1, 1, scores, maxDepth);
        return (left < right) ? left : right;
    }
}

int main() {
    int depth, numLeaves, i, rootIsMax;
    printf("Enter depth of the game tree: ");
    scanf("%d", &depth);
    numLeaves = 1 << depth;
    int scores[numLeaves];
    printf("Enter %d leaf node values:\n", numLeaves);
    for (i = 0; i < numLeaves; i++)
        scanf("%d", &scores[i]);
    printf("Is root a MAX player? (1 = Yes, 0 = No): ");
    scanf("%d", &rootIsMax);
    int optimalValue = minimax(0, 0, rootIsMax, scores, depth);
    printf("\nOptimal value: %d\n", optimalValue);
    return 0;
}
