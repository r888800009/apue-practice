#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void count(int n, int sum) {
    while (n > 0) sum += 2, n--;
    printf("%d\n", sum);
}

static void sig_handler(int signo) {
    if (signo == SIGUSR1) printf("SIGUSR1 received pid = %d\n", getppid());
    printf("child counting\n");
    count(10, 1);
}

int main(int argc, const char* argv[]) {
    pid_t pid;

    // disable buffer
    setbuf(stdout, NULL);

    // add handler
    if (signal(SIGUSR1, sig_handler) == SIG_ERR) perror("signal error");

    // fork
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid != 0) {  // parent
        printf("parent counting\n");
        count(10, 0);

        // send single
        printf("parent send signal\n");
        sleep(1);
        kill(pid, SIGUSR1);

    } else {      // child
        pause();  // do nothing
    }

    return 0;
}

