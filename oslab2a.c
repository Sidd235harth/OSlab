//writer
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define FIFO_NAME "/tmp/myfifo"

int main() {
    int fd;
    char message[] = "Hello from writer process!";

    /* Create FIFO */
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    printf("Writer: FIFO ready\n");

    /* Open FIFO for writing */
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Writer: FIFO opened for writing\n");

    /* Write message */
    if (write(fd, message, strlen(message) + 1) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Writer: Message written successfully\n");

    close(fd);
    return 0;
}
