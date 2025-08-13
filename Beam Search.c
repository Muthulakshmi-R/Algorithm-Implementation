#include <stdio.h>
#define MAX 20

int queue[MAX];
int front = 0, rear = 0;
int history[MAX];
int histCount = 0;
int heuristics[MAX];

void enqueue(int node) {
    queue[rear++] = node;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void addToHistory(int node) {
    history[histCount++] = node;
}

void sortByHeuristic(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (heuristics[arr[i]] > heuristics[arr[j]]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void beamSearch(int graph[MAX][MAX], int n, int start, int beamWidth) {
    enqueue(start);
    addToHistory(start);
    while (!isEmpty()) {
        int levelCount = rear - front; 
        int nextLevel[MAX];
        int nextCount = 0;

        for (int i = 0; i < levelCount; i++) {
            int node = dequeue();
            for (int j = 0; j < n; j++) {
                if (graph[node][j] == 1) {
                    nextLevel[nextCount++] = j;
                }
            }
        }
        sortByHeuristic(nextLevel, nextCount);
        if (nextCount > beamWidth) {
            nextCount = beamWidth;
        }

        for (int i = 0; i < nextCount; i++) {
            enqueue(nextLevel[i]);
            addToHistory(nextLevel[i]);
        }
    }
    printf("\nVisited Order (History): ");
    for (int i = 0; i < histCount; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}

int main() {
    int n, start, beamWidth;
    int graph[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter heuristic values for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heuristics[i]);
    }
    printf("Enter start node (0-%d): ", n - 1);
    scanf("%d", &start);
    printf("Enter beam width: ");
    scanf("%d", &beamWidth);
    beamSearch(graph, n, start, beamWidth);
    return 0;
}
