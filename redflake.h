
typedef struct {
    /* Networking */
    int port; /* TCP listening port */
    /* Configuration */
    int daemonize; /* True if running as a daemon */
} Server;

typedef struct {
} Client;

typedef void CommandProc(Client *c);

typedef struct {
    const char *declared_name; /* A string representing the command declared_name. */
    CommandProc *proc; /* Command implementation */
} Command;
