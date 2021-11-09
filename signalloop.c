#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// static void sighandler(int sig) {

// }

int main() {
    while(1) {
        printf("pid: %d\n",getpid());
        sleep(1);
    }
    return 0;
}