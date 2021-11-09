#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

static void term(int sig) {
    if (sig == SIGINT) {
        int file = open("ended.txt", O_WRONLY | O_APPEND | O_CREAT, 0);
        char buffer[100] = "signalloop.c was terminated by SIGINT\n";
        printf("terminated by SIGINT\n");
        // char time[100] =
        write(file,buffer,100);
        close(file);
        exit(0);
    }
}

int main() {
    signal(SIGINT, term);
    
    while(1) {
        printf("pid: %d\n",getpid());
        sleep(1);
    }

    return 0;
}