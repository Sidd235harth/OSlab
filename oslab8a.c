#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10

struct directory {
    char dname[20];
    char fname[MAX_FILES][20];
    int fcnt;
} dir;

int main() {
    int i, ch, found;
    char f[20];

    dir.fcnt = 0;

    printf("\nEnter name of directory: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\n\n--- SINGLE LEVEL DIRECTORY ---");
        printf("\n1. Create File");
        printf("\n2. Delete File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1: // Create File
            if (dir.fcnt >= MAX_FILES) {
                printf("Directory is full!");
                break;
            }

            printf("Enter file name: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcnt; i++) {
                if (strcmp(f, dir.fname[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File already exists!");
            else {
                strcpy(dir.fname[dir.fcnt], f);
                dir.fcnt++;
                printf("File created successfully.");
            }
            break;

        case 2: // Delete File
            printf("Enter file name to delete: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcnt; i++) {
                if (strcmp(f, dir.fname[i]) == 0) {
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    dir.fcnt--;
                    found = 1;
                    printf("File deleted successfully.");
                    break;
                }
            }

            if (!found)
                printf("File not found!");
            break;

        case 3: // Search File
            printf("Enter file name to search: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcnt; i++) {
                if (strcmp(f, dir.fname[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File found.");
            else
                printf("File not found!");
            break;

        case 4: // Display Files
            if (dir.fcnt == 0)
                printf("Directory is empty.");
            else {
                printf("\nDirectory: %s", dir.dname);
                printf("\nFiles:");
                for (i = 0; i < dir.fcnt; i++)
                    printf("\n%s", dir.fname[i]);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!");
        }
    }
    return 0;
}
