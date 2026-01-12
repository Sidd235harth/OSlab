#include <stdio.h>
#define max 25

int main() {
    int frag[max], b[max], f[max];
    int bf[max] = {0}, ff[max];
    int i, j, nb, nf, temp;

    printf("\nMemory Management Scheme - Worst Fit\n");

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of files: ");
    scanf("%d", &nf);

    for (i = 0; i < nb; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < nf; i++) {
        printf("File %d size: ", i + 1);
        scanf("%d", &f[i]);
        ff[i] = -1;   // initialize
    }

    for (i = 0; i < nf; i++) {
        int maxFrag = -1, index = -1;

        for (j = 0; j < nb; j++) {
            if (!bf[j]) {
                temp = b[j] - f[i];
                if (temp >= 0 && temp > maxFrag) {
                    maxFrag = temp;
                    index = j;
                }
            }
        }

        if (index != -1) {
            ff[i] = index;
            frag[i] = maxFrag;
            bf[index] = 1;
        }
    }

    printf("\nFile\tSize\tBlock\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1)
            printf("\n%d\t%d\t%d\t%d\t\t%d",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        else
            printf("\n%d\t%d\tNot Allocated", i + 1, f[i]);
    }

    return 0;
}
