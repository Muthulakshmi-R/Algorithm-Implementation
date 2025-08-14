#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 20
#define MAX_PATH_LEN 50
#define MAX_PATHS 100

int graph[MAX_NODES][MAX_NODES];
int n;
int paths[MAX_PATHS][MAX_PATH_LEN];
int pathLengths[MAX_PATHS];
int pathCosts[MAX_PATHS];
int pathsFound = 0;
int currentPath[MAX_PATH_LEN];

void dfs(int current, int goal, bool visited[], int pathLen, int cost) {
    visited[current] = true;
    currentPath[pathLen] = current;
    pathLen++;
    if (current == goal) {
        pathLengths[pathsFound] = pathLen;
        pathCosts[pathsFound] = cost;
        for (int i = 0; i < pathLen; i++) {
            paths[pathsFound][i] = currentPath[i];
        }
        pathsFound++;
    } else {
        for (int i = 0; i < n; i++) {
            if (graph[current][i] > 0 && !visited[i]) {
                dfs(i, goal, visited, pathLen, cost + graph[current][i]);
            }
        }
    }
    visited[current] = false;
}

bool isReachable(int current, int goal, bool visited[]) {
    if (current == goal) return true;
    visited[current] = true;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] > 0 && !visited[i]) {
            if (isReachable(i, goal, visited)) return true;
        }
    }
    return false;
}

int main() {
    printf("Enter number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d), use 0 if no edge:\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int start, goal;
    printf("Enter start node (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("Enter goal node (0 to %d): ", n - 1);
    scanf("%d", &goal);

    bool visitedCheck[MAX_NODES] = {false};
    if (!isReachable(start, goal, visitedCheck)) {
        printf("Goal node %d is not reachable from start node %d.\n", goal, start);
        return 0;
    }

    bool visited[MAX_NODES] = {false};
    dfs(start, goal, visited, 0, 0);
    printf("Oracle Search (All paths from %d to %d):\n", start, goal);
    for (int i = 0; i < pathsFound; i++) {
        for (int j = 0; j < pathLengths[i]; j++) {
            printf("%d ", paths[i][j]);
        }
        printf("=> Cost: %d\n", pathCosts[i]);
    }
    return 0;
}
