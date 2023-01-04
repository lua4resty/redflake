#include <fcntl.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "redflake.h"

Server server; /* Server global state */

void dbsizeCommand(Client *c) {
}

void infoCommand(Client *c) {
}

Command CommandTable[] = {
    {"dbsize", dbsizeCommand},
    {"info", infoCommand},
    {NULL}
};

static void daemonize(void) {
    int fd;
    if (fork() != 0) exit(0); /* parent exits */
    setsid(); /* create a new session */

    /* Every output goes to /dev/null. */
    if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }
}

static void print_usage(FILE *f) {
    fprintf(f, "redflake version: 0.0.1\n");
    fprintf(f, "Usage: redflake [-dh] [-p port] [-n node]\n");
}

int main(int argc, char *argv[]) {
    int c;
    while ((c = getopt(argc, argv, "dhn:p:")) != -1) {
        switch (c) {
            case 'd':
                server.daemonize = 1;
                break;
            case 'h':
                print_usage(stdout);
                break;
            case 'n':
                break;
            case 'p':
                break;
            default:
                print_usage(stderr);
        }
    }
    if (server.daemonize) daemonize();
    return EXIT_SUCCESS;
}
