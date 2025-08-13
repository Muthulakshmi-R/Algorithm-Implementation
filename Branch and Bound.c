#include <stdio.h>
#include <limits.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n, best_cost = INT_MAX;
int path[MAX], best_path[MAX];

void copyPath(int len) {
    for (int i = 0; i < len; i++) {
        best_path[i] = path[i];
    }
}

void branchAndBound(int curr_node, int level, int cost) {
    if (cost >= best_cost) return;
        if (graph[curr_node][0] != 0) {
            int total_cost = cost + graph[curr_node][0];
            if (total_cost < best_cost) {
                best_cost = total_cost;
                path[level] = 0; 
                copyPath(level + 1);
            }
        }
        return;
    }
    for (int next = 0; next < n; next++) {
        if (!visited[next] && graph[curr_node][next] != 0) {
            visited[next] = 1;
            path[level] = next;
            branchAndBound(next, level + 1, cost + graph[curr_node][next]);
            visited[next] = 0;
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d, 0 if no edge):\n", n, n);
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
    printf("Best path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\n");
    return 0;
}
