#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigint_handler(int signum)
{
    printf("Recibí la señal %d\n", signum);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }

    while (1)
    {
        printf("Esperando una señal...\n");
        sleep(1);
    }

    return 0;
}
