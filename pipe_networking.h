#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1000

int server_setup();
int server_connect(int from_client);
int client_connect();
