#include <stdio.h>

int main() {
    char dir[10] = "~/";
    char buffer[256];
    char *ptr;

    ptr = tempnam(dir, "1234");
    printf("%s\n", ptr);

    return 0;
}

