#include <stdio.h>
#define MAX 100

int visited[MAX];
int history[MAX];
int histIndex = 0;
void dfsWithHistory(int adj[MAX][MAX], int nodes, int current) {
    visited[current] = 1;
    history[histIndex++] = current;
    printf("Step %d - Visited: ", histIndex);
    for (int i = 0; i < histIndex; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
    for (int i = 0; i < nodes; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfsWithHistory(adj, nodes, i);
        }
    }
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
    printf("\nDFS with History\n");
    dfsWithHistory(adj, nodes, start);
    printf("\nFinal DFS Exploration Order: ");
    for (int i = 0; i < histIndex; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
    return 0;
}
