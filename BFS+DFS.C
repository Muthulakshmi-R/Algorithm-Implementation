#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int adj[MAX][MAX]; 
bool visited[MAX];
int n;  

void DFS(int node, int goal) {
    if (node == goal) {
        printf("%d ", node);
        return;
    }

    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            DFS(i, goal);
            break;  // for simple DFS, go to one neighbor at a time
        }
    }
}

void BFS(int start, int goal) {
    int queue[MAX];
    int front = 0, rear = 0;
    bool visitedB[MAX] = {false};

    queue[rear++] = start;
    visitedB[start] = true;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        if (node == goal) return;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visitedB[i]) {
                queue[rear++] = i;
                visitedB[i] = true;
            }
        }
    }
}

int main() {
    int start, goal;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter goal node: ");
    scanf("%d", &goal);

    printf("\nDFS Traversal: ");
    for (int i = 0; i < n; i++) visited[i] = false;
    DFS(start, goal);

    printf("\nBFS Traversal: ");
    BFS(start, goal);

    printf("\n");
    return 0;
}
