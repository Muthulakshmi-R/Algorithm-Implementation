#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int adj[MAX][MAX]; 
bool visited[MAX];
int n;

void DFS(int node) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    if (!visited[start]) {
        queue[rear++] = start;
        visited[start] = true;
    }
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++) visited[i] = false;
    printf("\nDFS traversal: ");
    DFS(start);
    printf("\nBFS traversal for remaining nodes: ");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    printf("\n");
    return 0;
}
