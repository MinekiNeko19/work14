#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

static void term(int sig) {
    if (sig == SIGINT) {
        time_t t = time(NULL);
        char * s = ctime(&t);
        int file = open("ended.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
        char buffer[40] = ": signalloop.c was terminated by SIGINT\n";
        printf("terminated by SIGINT\n");
        write(file,s,sizeof(s));
        write(file,buffer,40);
        close(file);
        exit(0);
    }
    if (sig == SIGUSR1) {
        printf("parent pid: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, term);
    signal(SIGUSR1, term);

    while(1) {
        printf("pid: %d\n",getpid());
        kill(getpid(),SIGUSR1);
        sleep(1);
    }

    return 0;
}