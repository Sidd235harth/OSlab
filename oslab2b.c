//reader
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myfifo"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char buffer[BUFFER_SIZE];

    /* Open FIFO for reading */
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Reader: FIFO opened for reading\n");

    /* Read message */
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Reader: Message received: %s\n", buffer);

    close(fd);

    /* Remove FIFO */
    unlink(FIFO_NAME);

    return 0;
}

