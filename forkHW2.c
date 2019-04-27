#include <pwd.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int n = 2000;
    int sum = 0;

    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0) {  // child
        struct passwd *pw = getpwuid(getuid());
        const char *home = pw->pw_dir;
        if (execlp("ls", "ls", "-al", home, NULL) < 0) printf("execl error\n");
    } else
        sum = 0;

    for (int i = 0; i < n; i++) sum += 2;

    printf("%d\n", sum);

    return 0;
}

