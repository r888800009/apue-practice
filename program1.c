#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int atoi(char const *numStr) {
    int result = 0;

    while (*numStr != '\0') {
        result *= 10;
        result += *numStr - '0';
        numStr++;
    }

    return result;
}

void printInt(int num) {
    // itoa
    char buffer[30];
    int i = 0;
    while (num > 0) {
        buffer[i] = num % 10 + '0';
        i++;
        num /= 10;
    }

    buffer[i] = '\n';
    buffer[i + 1] = '\0';
    i--;        // last item
    int j = 0;  // first item
    while (i > j) {
        char tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
        i--, j++;
    }

    write(STDOUT_FILENO, buffer, strlen(buffer));
}

int file1() {
    int fd;
    fd = open("./test1.dat", O_RDWR);
    if (fd == -1) {
        return -1;  // fall
    }

    int a, b, c;

    char drop;
    read(fd, &a, 4);
    read(fd, &drop, 1);
    read(fd, &b, 4);

    c = a + b;
    printInt(c);

    close(fd);
}

void readStr(char *ptr, int fd) {
    char buffer;
    while (read(fd, &buffer, 1) > 0 && buffer != ' ' && buffer != '\0') {
        *ptr = buffer;
        ptr++;
    }

    *ptr = '\0';  // string end
}

int file2() {
    int fd;
    fd = open("./test2.dat", O_RDWR);
    if (fd == -1) {
        return -1;  // fall
    }

    char a[20], b[20];
    int c;

    readStr(a, fd);
    readStr(b, fd);

    c = atoi(a) + atoi(b);
    printInt(c);

    close(fd);
}

int main() {
    file1();
    file2();

    return 0;
}
