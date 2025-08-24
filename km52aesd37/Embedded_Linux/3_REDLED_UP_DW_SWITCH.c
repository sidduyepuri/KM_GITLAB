#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/input.h>

int main()
{
    int fd1, fd2, fd3, ret;
    struct input_event ev;

    fd1 = open("/sys/class/gpio/export", O_WRONLY);
    if (fd1 == -1) {
        perror("Failed to open export file");
        exit(EXIT_FAILURE);
    }
    ret = write(fd1, "10", 2);
    if (ret == -1) {
        perror("Failed to write to export file");
        close(fd1);
        exit(EXIT_FAILURE);
    }
    close(fd1);

    fd2 = open("/sys/class/gpio/gpio10/direction", O_WRONLY);
    if (fd2 == -1) {
        perror("Failed to open direction file");
        exit(EXIT_FAILURE);
    }
    ret = write(fd2, "out", 3);
    if (ret == -1) {
        perror("Failed to write to direction file");
        close(fd2);
        exit(EXIT_FAILURE);
    }
    close(fd2);

    while (1)
    {
        fd1 = open("/dev/input/event0", O_RDWR);
        if (fd1 == -1) {
            perror("Failed to open input device file");
            exit(EXIT_FAILURE);
        }

        ret = read(fd1, &ev, sizeof(struct input_event));
        if (ret == -1) {
            perror("Failed to read from input device file");
            close(fd1);
            exit(EXIT_FAILURE);
        }

        if (ev.code == 114 && ev.value == 0)
        {
            fd3 = open("/sys/class/gpio/gpio10/value", O_WRONLY);
            if (fd3 == -1) {
                perror("Failed to open value file");
                close(fd1);
                exit(EXIT_FAILURE);
            }
            ret = write(fd3, "0", 1);
            if (ret == -1) {
                perror("Failed to write to value file");
                close(fd3);
                close(fd1);
                exit(EXIT_FAILURE);
            }
            close(fd3);
        }
        else if (ev.code == 115 && ev.value == 1)
        {
            fd3 = open("/sys/class/gpio/gpio10/value", O_WRONLY);
            if (fd3 == -1) {
                perror("Failed to open value file");
                close(fd1);
                exit(EXIT_FAILURE);
            }
            ret = write(fd3, "1", 1);
            if (ret == -1) {
                perror("Failed to write to value file");
                close(fd3);
                close(fd1);
                exit(EXIT_FAILURE);
            }
            close(fd3);
        }
    }

    close(fd1);
    close(fd3);

    return 0;
}
