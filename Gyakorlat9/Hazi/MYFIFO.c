#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MYFIFO "MYFIFO"
#define END_MSG "end"

int main() 
{

    int res;
    res = mknod(MYFIFO, S_IFIFO | 0640, 0);
    if (res == -1 && errno != EEXIST) 
    {
        perror("mknod error");
        exit(EXIT_FAILURE);
    }

    int fd;
    fd = open(MYFIFO, O_RDONLY);
    if (fd == -1) 
    {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (1) 
    {
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer)-1);
        if (bytes_read == -1) 
        {
            perror("read error");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';
        printf("Kapott uzenet: %s", buffer);
        if (strncmp(buffer, END_MSG, strlen(END_MSG)) == 0) 
        {
            printf("Kileptel a ciklusbol.\n");
            break;
        }
    }
    close(fd);
    
    fd = open(MYFIFO, O_WRONLY);
    if (fd == -1) 
    {
        perror("open error");
        exit(EXIT_FAILURE);
    }

    while (1) 
    {
        printf("Irj be egy uzenetet (end szo hasznalataval kilepsz a ciklusbol): ");
        fgets(buffer, sizeof(buffer), stdin);
        write(fd, buffer, strlen(buffer));
        if (strncmp(buffer, END_MSG, strlen(END_MSG)) == 0) 
        {
            printf("Kileptel a ciklusbol.\n");
            break;
        }
    }

    close(fd);
    unlink(MYFIFO);

    return 0;
}
