#include <stdio.h>
#include <string.h>
#define MAX_LEN 5

long long attempts = 0;
int generateAndCheck(char target[], int len, char current[], int pos) {
    if (pos == len) {
        current[pos] = '\0'; 
        attempts++;
        printf("Trying: %s\n", current); 
        if (strcmp(current, target) == 0) {
            printf("Found: %s\n", current);
            printf("Total attempts: %lld\n", attempts);
            return 1; 
        }
        return 0; 
    }
    for (char c = 'a'; c <= 'z'; c++) {
        current[pos] = c;
        if (generateAndCheck(target, len, current, pos + 1)) {
            return 1; 
        }
    }
    return 0;
}

int main() {
    char target[MAX_LEN];
    char current[MAX_LEN];
    int len;
    printf("Enter target word (lowercase letters only): ");
    scanf("%s", target);
    len = strlen(target);
    printf("\nSearching...\n");
    if (!generateAndCheck(target, len, current, 0)) {
        printf("Not found after %lld attempts!\n", attempts);
    }
    return 0;
}
