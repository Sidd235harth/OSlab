#include <stdio.h>

int main() {
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], work[10], total[10];
    int n, m, i, j, k;
    int finish[10] = {0};   // 0 = not finished, 1 = finished
    int count = 0;

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("\nEnter MAX matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("\nEnter ALLOCATION matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("\nEnter TOTAL resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate Available resources
    for (i = 0; i < m; i++)
        avail[i] = total[i];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            avail[j] -= alloc[i][j];

    // Calculate Need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Copy available to work
    for (i = 0; i < m; i++)
        work[i] = avail[i];

    printf("\n--- Banker's Algorithm Execution ---\n");

    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canExecute = 1;

                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute) {
                    printf("Process P%d is executed\n", i + 1);

                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    count++;
                    found = 1;

                    printf("Available after execution: ");
                    for (k = 0; k < m; k++)
                        printf("%d ", work[k]);
                    printf("\n\n");
                }
            }
        }

        if (!found) {
            printf("\nSystem is NOT in a safe state (Deadlock possible)\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state\n");
    return 0;
}
