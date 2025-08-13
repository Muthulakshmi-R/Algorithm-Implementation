#include <stdio.h>
#include <limits.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n, best_cost = INT_MAX;
int path[MAX], best_path[MAX];
int history[MAX * MAX], histCount = 0;

void addToHistory(int node) {
    history[histCount++] = node;
}

void copyPath(int len) {
    for (int i = 0; i < len; i++) {
        best_path[i] = path[i];
    }
}

void branchAndBound(int curr_node, int level, int cost) {
    addToHistory(curr_node);
    if (cost >= best_cost) return; 
    if (level == n) {
        if (graph[curr_node][0] != 0 && cost + graph[curr_node][0] < best_cost) {
            best_cost = cost + graph[curr_node][0];
            path[level] = 0;
            copyPath(level + 1);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[curr_node][i] != 0) {
            visited[i] = 1;
            path[level] = i;
            branchAndBound(i, level + 1, cost + graph[curr_node][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[0] = 1;
    path[0] = 0;
    branchAndBound(0, 1, 0);
    printf("\nMinimum cost: %d\n", best_cost);
    printf("Optimal path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\n\nHistory of all nodes visited: ");
    for (int i = 0; i < histCount; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
    return 0;
}
