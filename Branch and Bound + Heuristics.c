#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX];
int n;
int visited[MAX];
int path[MAX], best_path[MAX];
int best_cost = INT_MAX;

int minEdge(int node) {
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0 && graph[node][i] < min)
            min = graph[node][i];
    }
    return min;
}

void branchAndBoundHeuristic(int curr_node, int level, int cost) {
    int bound = cost;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) bound += minEdge(i);
    }
    if (bound >= best_cost) return;
    if (level == n) {
        if (graph[curr_node][0] != 0 && cost + graph[curr_node][0] < best_cost) {
            best_cost = cost + graph[curr_node][0];
            for (int i = 0; i < n; i++) best_path[i] = path[i];
            best_path[n] = 0;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[curr_node][i] != 0) {
            visited[i] = 1;
            path[level] = i;
            branchAndBoundHeuristic(i, level + 1, cost + graph[curr_node][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[0] = 1;
    path[0] = 0;
    branchAndBoundHeuristic(0, 1, 0);
    printf("\nMinimum cost: %d\n", best_cost);
    printf("Optimal path: ");
    for (int i = 0; i <= n; i++)
        printf("%d ", best_path[i]);
    printf("\n");
    return 0;
}
