#include <ctype.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = creat("eeee.txt", 0644);
    // "0644" mean octal not "644"

    char *str1 = "hello";
    write(fd, str1, strlen(str1));

    close(fd);
    return 0;
}

