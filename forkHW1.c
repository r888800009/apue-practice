#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        printf("forkHW1 <N>\n");
        return 1;
    }

    pid_t pid;
    int n = atoi(argv[1]);
    int sum = 0;

    // fork
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)  // child
        sum = 1;
    else
        sum = 0;

    while (n > 0) sum += 2, n--;

    printf("%d\n", sum);

    return 0;
}

