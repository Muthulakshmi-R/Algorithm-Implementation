#include <stdio.h>
#define MAX 100

int visited[MAX];
void dfs(int adj[MAX][MAX], int nodes, int current) {
    visited[current] = 1;
    printf("%d ", current); 

    for (int i = 0; i < nodes; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(adj, nodes, i);
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
    printf("\nDFS Traversal Order: ");
    dfs(adj, nodes, start);
    printf("\n");
    return 0;
}
