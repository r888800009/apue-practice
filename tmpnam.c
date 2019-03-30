#include <stdio.h>

int main() {
    char buffer[256];
    char *ptr;

    tmpnam(buffer);
    printf("%s\n", buffer);

    ptr = tmpnam(NULL);
    printf("%s\n", ptr);

    return 0;
}

