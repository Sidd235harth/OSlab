#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILES 10

struct directory {
    char dname[20];
    char fname[MAX_FILES][20];
    int fcnt;
} dir[MAX_DIR];

int main() {
    int i, j, ch, dcnt = 0, found;
    char d[20], f[20];

    while (1) {
        printf("\n\n--- TWO LEVEL DIRECTORY ---");
        printf("\n1. Create Directory");
        printf("\n2. Create File");
        printf("\n3. Delete File");
        printf("\n4. Search File");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1: // Create Directory
            if (dcnt >= MAX_DIR) {
                printf("Directory limit reached!");
                break;
            }

            printf("Enter directory name: ");
            scanf("%s", d);

            found = 0;
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("Directory already exists!");
            else {
                strcpy(dir[dcnt].dname, d);
                dir[dcnt].fcnt = 0;
                dcnt++;
                printf("Directory created.");
            }
            break;

        case 2: // Create File
            printf("Enter directory name: ");
            scanf("%s", d);

            found = 0;
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    found = 1;
                    if (dir[i].fcnt >= MAX_FILES) {
                        printf("File limit reached!");
                        break;
                    }

                    printf("Enter file name: ");
                    scanf("%s", f);

                    for (j = 0; j < dir[i].fcnt; j++) {
                        if (strcmp(f, dir[i].fname[j]) == 0) {
                            printf("File already exists!");
                            goto skip;
                        }
                    }

                    strcpy(dir[i].fname[dir[i].fcnt], f);
                    dir[i].fcnt++;
                    printf("File created.");
                skip:
                    break;
                }
            }

            if (!found)
                printf("Directory not found!");
            break;

        case 3: // Delete File
            printf("Enter directory name: ");
            scanf("%s", d);

            found = 0;
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    found = 1;
                    printf("Enter file name: ");
                    scanf("%s", f);

                    for (j = 0; j < dir[i].fcnt; j++) {
                        if (strcmp(f, dir[i].fname[j]) == 0) {
                            strcpy(dir[i].fname[j], dir[i].fname[dir[i].fcnt - 1]);
                            dir[i].fcnt--;
                            printf("File deleted.");
                            goto done;
                        }
                    }
                    printf("File not found!");
                done:
                    break;
                }
            }

            if (!found)
                printf("Directory not found!");
            break;

        case 4: // Search File
            printf("Enter directory name: ");
            scanf("%s", d);

            found = 0;
            for (i = 0; i < dcnt; i++) {
                if (strcmp(d, dir[i].dname) == 0) {
                    found = 1;
                    printf("Enter file name: ");
                    scanf("%s", f);

                    for (j = 0; j < dir[i].fcnt; j++) {
                        if (strcmp(f, dir[i].fname[j]) == 0) {
                            printf("File found.");
                            goto found_file;
                        }
                    }
                    printf("File not found!");
                found_file:
                    break;
                }
            }

            if (!found)
                printf("Directory not found!");
            break;

        case 5: // Display
            if (dcnt == 0)
                printf("No directories available.");
            else {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dcnt; i++) {
                    printf("\n%s\t\t", dir[i].dname);
                    for (j = 0; j < dir[i].fcnt; j++)
                        printf("%s ", dir[i].fname[j]);
                }
            }
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!");
        }
    }
    return 0;
}
