#include <stdio.h>
#define MAX 100

void bfsWithHistory(int adj[MAX][MAX], int nodes, int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};
    int history[MAX], histIndex = 0;

    queue[rear++] = start;
    visited[start] = 1;
    printf("\nBFS with History\n");
    while (front < rear) {
        int current = queue[front++];
        history[histIndex++] = current;
        printf("Step %d - Visited: ", histIndex);
        for (int i = 0; i < histIndex; i++) {
            printf("%d ", history[i]);
        }
        printf("\n");

        for (int i = 0; i < nodes; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\nFinal BFS Exploration Order: ");
    for (int i = 0; i < histIndex; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}

int main() {
    int nodes, start;
    int adj[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter adjacency matrix (%d x %d):\n", nodes, nodes);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    bfsWithHistory(adj, nodes, start);
    return 0;
}
