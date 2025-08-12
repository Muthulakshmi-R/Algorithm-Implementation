#include <stdio.h>
#define MAX 100

int main() {
    int graph[MAX][MAX]; 
    int visited[MAX];    
    int queue[MAX];     
    int n;              
    int front = 0, rear = -1;
    int start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[start] = 1;
    queue[++rear] = start;
    printf("BFS Traversal: ");
    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    return 0;
}
