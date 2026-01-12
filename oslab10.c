#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[25], n, h, i, j, temp;
    int totalMovement = 0;
    int maxTrack = 199;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &h);

    // Add head position to request list
    t[n] = h;
    n++;

    // Sort the request array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find head index
    int headIndex;
    for (i = 0; i < n; i++) {
        if (t[i] == h) {
            headIndex = i;
            break;
        }
    }

    printf("\nSeek Sequence:\n");

    // Move LEFT first
    for (i = headIndex; i > 0; i--) {
        printf("%d -> %d\n", t[i], t[i - 1]);
        totalMovement += abs(t[i] - t[i - 1]);
    }

    // Move from first request to 0
    printf("%d -> 0\n", t[0]);
    totalMovement += t[0];

    // Move RIGHT
    for (i = headIndex + 1; i < n; i++) {
        printf("%d -> %d\n", (i == headIndex + 1 ? 0 : t[i - 1]), t[i]);
        totalMovement += abs(t[i] - (i == headIndex + 1 ? 0 : t[i - 1]));
    }

    printf("\nTotal head movement = %d\n", totalMovement);

    return 0;
}
